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

    imageManager.loadMenuImage("menu.png");
    imageManager.loadStartButtonImage("StartButton.png");
    imageManager.loadSettingButtonImage("SettingButton.png");
    imageManager.loadGameOverImage("lose.png");
    imageManager.loadWinGameImage("win.png");

    SDL_Texture* background = graphics.loadTexture(BACKGROUND_IMG);
    graphics.prepareScene(background);
    graphics.presentScene();

    TTF_Font* font = graphics.loadFont("assets/CabalBold-78yP.ttf", 70);
    SDL_Color textColor = {0, 0, 0};

    Matrix matrix;
    matrix.loadHighScore();

    Button startButton = {165, 230, 250, 250, false};
    Button settingButton = {165, 375, 250, 260, false};


    GameState gameState = MENU;
    Mix_Music *gMusic = graphics.loadMusic("assets/Cardigan.mp3");
    SDL_Event event;

    while(true){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                return 0;
            }
            if (event.type == SDL_MOUSEMOTION){
                startButton.Clicked = MouseInButton(startButton, event.motion.x, event.motion.y);
                settingButton.Clicked = MouseInButton(settingButton, event.motion.x, event.motion.y);
            }
            if (event.type == SDL_MOUSEBUTTONDOWN){
                if (startButton.Clicked && gameState == MENU){
                    gameState = PLAYING;
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
                imageManager.renderSettingButton(settingButton.x, settingButton.y, settingButton.width, settingButton.height);

                if (startButton.Clicked) {
                    startButton.x = 140;
                    startButton.y = 210;
                    startButton.width = 300;
                    startButton.height = 300;
                }
                else {
                    startButton.x = 165;
                    startButton.y = 230;
                    startButton.width = 250;
                    startButton.height = 250;
                }
                if (settingButton.Clicked) {
                    settingButton.x = 150;
                    settingButton.y = 355;
                    settingButton.width = 300;
                    settingButton.height = 310;
                }
                else {
                    settingButton.x = 165;
                    settingButton.y = 375;
                    settingButton.width = 250;
                    settingButton.height = 260;
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
                matrix.renderScore(graphics.renderer, font, graphics, 350, 420);
                matrix.renderHighScore(graphics.renderer, font, graphics, 350, 530);
                graphics.renderText("GOOD JOB!", font, textColor, 70, 10, graphics.renderer);
                SDL_Delay(1000);
                break;
            case GAME_OVER:
                imageManager.renderGameOverImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
                matrix.renderScore(graphics.renderer, font, graphics, 800, 450);
                matrix.renderHighScore(graphics.renderer, font, graphics, 800, 555);
                graphics.renderText("Try again next time", font, textColor, 280, 10, graphics.renderer);
                SDL_Delay(1000);
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
