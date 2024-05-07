#ifndef _TILE__H
#define _TILE__H

#include <SDL.h>
#include <SDL_ttf.h>
#include "defs.h"

using namespace std;

class Tile {
private:
    SDL_Rect tileRect;
    int value = 0;
    SDL_Surface* textSurface = NULL;
    SDL_Texture* Text = NULL;
    TTF_Font* font = NULL;
    SDL_Color tileColor;
    SDL_Color textColor = {255, 255, 255};

public:
    Tile() : tileRect({0, 0, 0, 0}), value(0), textSurface(NULL), Text(NULL), font(NULL){}

    Tile(int x, int y, int size, int val, SDL_Color color) : tileRect({x, y, size, size}), value(val), tileColor(color){
        font = TTF_OpenFont("assets/CabalBold-78yP.ttf", 80);
    }

    void updateColor(){
        switch (value){
            case 2: case 4:
                tileColor = {255, 165, 0}; // Orange
                break;
            case 8: case 64:
                tileColor = {255, 0, 0}; // Red
                break;
            case 16: case 128:
                tileColor = {255, 192, 203}; // Pink
                break;
            case 32: case 256:
                tileColor = {255, 255, 0}; // Yellow
                break;
            case 512:
                tileColor = {255, 165, 0}; // Orange
                break;
            case 1024:
                tileColor = {128, 0, 128}; // Purple
                break;
            case 2048:
                tileColor = {0, 0, 255}; // Blue
                break;
            default:
                tileColor = {128, 128, 128}; // Green
        }
    }

    int getValue(){
        return value;
    }

    void setValue(int val){
        value = val;
        updateColor();
    }

    void destroy(){
        SDL_DestroyTexture(Text);
        Text = NULL;
        SDL_FreeSurface(textSurface);
        textSurface = NULL;
    }

    void render(SDL_Renderer* renderer){
        SDL_SetRenderDrawColor(renderer, tileColor.r, tileColor.g, tileColor.b, 0); // Set tile color
        SDL_RenderFillRect(renderer, &tileRect);

        if(value > 0){
            textSurface = TTF_RenderText_Solid(font, to_string(value).c_str(), textColor);
            Text = SDL_CreateTextureFromSurface(renderer, textSurface);
            SDL_RenderCopy(renderer, Text, NULL, &tileRect);
        }
        destroy();
    }
};

#endif
