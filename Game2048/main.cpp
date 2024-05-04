#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "defs.h"
#include "graphics.h"
#include "tile.h"
#include "matrix.h"

using namespace std;

bool handleEvent(SDL_Window* window, Matrix& matrix, ScrollingBackground& background){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            return false;
        }
    matrix.Events(window, event);
    if(matrix.isGameOver() || matrix.CheckIfWin()){
        background.isScrolling = false;
        }
    }
    return true;
}



int main(int argc, char* argv[]){

    Graphics graphics;
    graphics.init();

    ScrollingBackground background;
    background.setTexture(graphics.loadTexture(BACKGROUND_IMG));

    TTF_Font* font = graphics.loadFont("assets/PTF-NORDIC-Rnd.ttf", 100);
    SDL_Color textColor = {255, 255, 255, 255};

    Matrix matrix;
    while(handleEvent(graphics.window, matrix, background)){
        SDL_SetRenderDrawColor( graphics.renderer, 255, 255, 255, 255 );
        SDL_RenderClear( graphics.renderer );
        background.scroll(1);
        graphics.render( background );
        matrix.render( graphics.renderer );
        SDL_RenderPresent( graphics.renderer );
    }

    SDL_Delay(100);
    TTF_CloseFont(font);
    SDL_DestroyTexture(background.texture);
    graphics.quitSDL();
    return 0;
}
