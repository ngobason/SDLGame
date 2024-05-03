#ifndef _TILE__H
#define _TILE__H

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "defs.h"

using namespace std;

class Tile {
private:
    SDL_Rect tileRect;
    int value = 0;
    SDL_Surface* textSurface = NULL;
    SDL_Texture* Text = NULL;
    SDL_Color textColor = {255, 255, 255};
    TTF_Font* font = NULL;



public:
    Tile() : tileRect({0, 0, 0, 0}), value(0), textSurface(NULL), Text(NULL), font(NULL) {}

    Tile(int x, int y, int size, int val) : tileRect({x, y, size, size}), value(val) {
        font = TTF_OpenFont("assets/PTF-NORDIC-Rnd.ttf", 100);
        if (!font) {
            cout << "Failed to load font: " << TTF_GetError() << endl;
            return;
        }
}

    int getValue(){
        return value;
    }

    void setValue(int val) {
        value = val;
    }

    void destroy() {
        SDL_DestroyTexture(Text);
        Text= NULL;
        SDL_FreeSurface(textSurface);
        textSurface = NULL;
    }

    void render(SDL_Renderer* renderer){
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderFillRect(renderer, &tileRect);

        if(value > 0){
            textSurface = TTF_RenderText_Solid(font, to_string(value).c_str(), textColor);
            Text= SDL_CreateTextureFromSurface(renderer, textSurface);
            SDL_RenderCopy(renderer, Text, NULL, &tileRect);
        }

        destroy();
    }

};

#endif

