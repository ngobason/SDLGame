#ifndef _GRAPHICS__H
#define _GRAPHICS__H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <string>
#include "defs.h"

using namespace std;

struct Graphics{
    SDL_Renderer *renderer;
	SDL_Window *window;


	void logErrorAndExit(const char* msg, const char* error){
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
        SDL_Quit();
    }


	void init(){
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
            logErrorAndExit("SDL_Init", SDL_GetError());

        window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (window == nullptr){
            logErrorAndExit("Create Window", SDL_GetError());
        }

        if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)){
            logErrorAndExit( "SDL_image error:", IMG_GetError());
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        if (renderer == nullptr){
            logErrorAndExit("Create Renderer", SDL_GetError());
        }

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
        SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

        if (TTF_Init() == -1){
            logErrorAndExit("SDL_ttf could not initialize! SDL_ttf Error: ", TTF_GetError());
        }
        if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
               logErrorAndExit( "SDL_mixer could not initialize! SDL_mixer Error: %s\n",
                                Mix_GetError() );
            }

    }


    void prepareScene(SDL_Texture * background){
        SDL_RenderClear(renderer);
        SDL_RenderCopy( renderer, background, NULL, NULL);
    }

    void presentScene(){
        SDL_RenderPresent(renderer);
    }


    SDL_Texture *loadTexture(const char *filename){
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

        SDL_Texture *texture = IMG_LoadTexture(renderer, filename);
        if (texture == NULL)
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load texture %s", IMG_GetError());
                return texture;
    }


     void renderTexture(SDL_Texture *texture, int x, int y){
        SDL_Rect dest;
        dest.x = x;
        dest.y = y;
        SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
        SDL_RenderCopy(renderer, texture, NULL, &dest);
    }


    void quitSDL(){
        Mix_Quit();
        TTF_Quit();
        IMG_Quit();
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }


    TTF_Font* loadFont(const char* path, int size){
        TTF_Font* gFont = TTF_OpenFont( path, size );
        if (gFont == nullptr) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load font %s", TTF_GetError());
        }
            return gFont;
    }


    void renderText(const string text, TTF_Font* font, SDL_Color color, int x, int y, SDL_Renderer *renderer) {
        SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), color);
        if (surface == nullptr) {
            logErrorAndExit("Unable to render text surface! SDL_ttf Error: ", TTF_GetError());
        }
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (texture == nullptr) {
            logErrorAndExit("Unable to create texture from rendered text! SDL Error: ", SDL_GetError());
            SDL_FreeSurface(surface);
        }
        SDL_Rect destRect = {x, y, surface->w, surface->h};
        SDL_RenderCopy(renderer, texture, nullptr, &destRect);

        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
    }


    Mix_Music *loadMusic(const char* path){
        Mix_Music *gMusic = Mix_LoadMUS(path);
        if (gMusic == nullptr) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                           "Could not load music! SDL_mixer Error: %s", Mix_GetError());
        }
        return gMusic;
    }

    void play(Mix_Music *gMusic){
        if (gMusic == nullptr) return;

        if (Mix_PlayingMusic() == 0){
            Mix_PlayMusic( gMusic, -1 );
        }
        else if( Mix_PausedMusic() == 1 ){
            Mix_ResumeMusic();
        }
    }

};

#endif
