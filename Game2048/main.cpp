#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "defs.h"
#include "graphics.h"
#include "tile.h"
#include "matrix.h"
#include "menu.h"

using namespace std;

enum GameState{
    MENU,
    PLAYING,
    GAME_OVER,
    WIN_GAME
};

struct Button{
    int x, y, width, height;
    bool Clicked;
};

bool MouseInButton(Button& button, int mouseX, int mouseY) {
    return (mouseX >= button.x && mouseX <= button.x + button.width &&
            mouseY >= button.y && mouseY <= button.y + button.height);
}

void renderButton(SDL_Renderer* renderer, SDL_Texture* texture, Button& button) {
    SDL_Rect destRect = {button.x, button.y, button.width, button.height};
    SDL_RenderCopy(renderer, texture, nullptr, &destRect);
}


int main(int argc, char* argv[]) {
    Graphics graphics;
    graphics.init();

    ImageManager imageManager(graphics.renderer);
    imageManager.loadMenuImage("assets/menu.png");
    imageManager.loadStartButtonImage("assets/StartButton.png");
    imageManager.loadGameOverImage("assets/lose.png");
    imageManager.loadWinGameImage("assets/win.png");
    imageManager.loadResetButtonImage("assets/reset.png");

    SDL_Texture* background = graphics.loadTexture(BACKGROUND_IMG);
    graphics.prepareScene(background);
    graphics.presentScene();

    TTF_Font* font = graphics.loadFont("assets/CabalBold-78yP.ttf", 70);
    SDL_Color textColor = {0, 0, 0};

    Matrix matrix;
    matrix.loadHighScore();

    Button startButton;
    Button resetButton;

    GameState gameState = MENU;
    Mix_Music *gMusic = graphics.loadMusic("assets/GameMusic.mp3");
    SDL_Event event;

    while(true){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                return 0;
            }
            if (event.type == SDL_MOUSEMOTION){
                startButton.Clicked = MouseInButton(startButton, event.motion.x, event.motion.y);
                resetButton.Clicked = MouseInButton(resetButton, event.motion.x, event.motion.y);
            }
            if (event.type == SDL_MOUSEBUTTONDOWN){
                if (startButton.Clicked && gameState == MENU){
                    gameState = PLAYING;
                    Mix_PlayMusic(gMusic, -1);
                }
            }
            if (event.type == SDL_MOUSEBUTTONDOWN){
                if (resetButton.Clicked) {
                    gameState = PLAYING;
                    matrix.resetGame();
                    Mix_PlayMusic(gMusic, -1);
                }
            }
            matrix.Events(graphics.window, event);
        }

        SDL_RenderClear(graphics.renderer);

        switch (gameState) {
            case MENU:
                imageManager.renderMenuImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
                imageManager.renderStartButton(startButton.x, startButton.y, startButton.width, startButton.height);
                if (startButton.Clicked){
                    startButton.x = 130;
                    startButton.y = 380;
                    startButton.width = 300;
                    startButton.height = 300;
                }
                else {
                    startButton.x = 150;
                    startButton.y = 400;
                    startButton.width = 250;
                    startButton.height = 250;
                }
                break;
            case PLAYING:
                SDL_RenderCopy(graphics.renderer, background, NULL, NULL);
                matrix.render(graphics.renderer);
                matrix.renderScore(graphics.renderer, font, graphics, currentScoreX, currentScoreY);
                matrix.renderHighScore(graphics.renderer, font, graphics, highScoreX, highScoreY);

                if (matrix.isGameOver()) {
                    gameState = GAME_OVER;
                    Mix_PauseMusic();
                }
                if(matrix.CheckIfWin()) {
                    gameState = WIN_GAME;
                    Mix_PauseMusic();
                }
                break;
            case WIN_GAME:
                imageManager.renderWinGameImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
                imageManager.renderResetButton(resetButton.x, resetButton.y, resetButton.width, resetButton.height);
                matrix.renderScore(graphics.renderer, font, graphics, 350, 450);
                matrix.renderHighScore(graphics.renderer, font, graphics, 350, 550);
                graphics.renderText("Play again ?", font, textColor, 70, 10, graphics.renderer);
                if (resetButton.Clicked){
                    resetButton.x = 170;
                    resetButton.y = 60;
                    resetButton.width = 210;
                    resetButton.height = 210;
                }
                else {
                    resetButton.x = 190;
                    resetButton.y = 80;
                    resetButton.width = 180;
                    resetButton.height = 180;
                }
                break;
            case GAME_OVER:
                imageManager.renderGameOverImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
                imageManager.renderResetButton(resetButton.x, resetButton.y, resetButton.width, resetButton.height);
                matrix.renderScore(graphics.renderer, font, graphics, 800, 450);
                matrix.renderHighScore(graphics.renderer, font, graphics, 800, 535);
                graphics.renderText("Try again next time", font, textColor, 280, 10, graphics.renderer);
                if (resetButton.Clicked){
                    resetButton.x = 630;
                    resetButton.y = 120;
                    resetButton.width = 210;
                    resetButton.height = 210;
                }
                else {
                    resetButton.x = 650;
                    resetButton.y = 140;
                    resetButton.width = 180;
                    resetButton.height = 180;
                }
                break;
        }
        SDL_RenderPresent(graphics.renderer);
    }

    SDL_Delay(100);
    TTF_CloseFont(font);
    SDL_DestroyTexture(background);
    background = nullptr;
    graphics.quitSDL();
    return 0;
}
