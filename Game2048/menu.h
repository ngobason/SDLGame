#ifndef _MENU__H
#define _MENU__H

#include "graphics.h"

class ImageManager {
private:
    SDL_Renderer* renderer;
    SDL_Texture* menuImage;
    SDL_Texture* startButtonImage;
    SDL_Texture* settingButtonImage;
    SDL_Texture* gameOverImage;
    SDL_Texture* winGameImage;

public:
    ImageManager(SDL_Renderer* rend) : renderer(rend), menuImage(NULL), startButtonImage(NULL),
    settingButtonImage(NULL), gameOverImage(NULL) {}

    bool loadMenuImage(const char* filename) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);
        SDL_Surface* surface = IMG_Load(filename);
        if (!surface) {
            return false;
        }
        menuImage = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        if (!menuImage) {
            return false;
        }
        return true;
    }

    bool loadStartButtonImage(const char* filename) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);
        SDL_Surface* surface = IMG_Load(filename);
        if (!surface) {
            return false;
        }
        startButtonImage = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        if (!startButtonImage) {
            return false;
        }
        return true;
    }

    bool loadSettingButtonImage(const char* filename) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);
        SDL_Surface* surface = IMG_Load(filename);
        if (!surface) {
            return false;
        }
        settingButtonImage = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        if (!settingButtonImage) {
            return false;
        }
        return true;
    }

    bool loadGameOverImage(const char* filename) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);
        SDL_Surface* surface = IMG_Load(filename);
        if (!surface) {
            return false;
        }
        gameOverImage = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        if (!gameOverImage) {
            return false;
        }
        return true;
    }

    bool loadWinGameImage(const char* filename) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);
        SDL_Surface* surface = IMG_Load(filename);
        if (!surface) {
            return false;
        }
        winGameImage = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        if (!winGameImage) {
            return false;
        }
        return true;
    }

    void renderMenuImage(int x, int y, int width, int height) {
        if (menuImage) {
            SDL_Rect destRect = {x, y, width, height};
            SDL_RenderCopy(renderer, menuImage, NULL, &destRect);
        }
    }

    void renderStartButton(int x, int y, int width, int height) {
        if (startButtonImage) {
            SDL_Rect destRect = {x, y, width, height};
            SDL_RenderCopy(renderer, startButtonImage, NULL, &destRect);
        }
    }

    void renderSettingButton(int x, int y, int width, int height) {
        if (settingButtonImage) {
            SDL_Rect destRect = {x, y, width, height};
            SDL_RenderCopy(renderer, settingButtonImage, NULL, &destRect);
        }
    }
    void renderGameOverImage(int x, int y, int width, int height) {
        if (gameOverImage) {
            SDL_Rect destRect = {x, y, width, height};
            SDL_RenderCopy(renderer, gameOverImage, NULL, &destRect);
        }
    }

    void renderWinGameImage(int x, int y, int width, int height) {
        if (winGameImage) {
            SDL_Rect destRect = {x, y, width, height};
            SDL_RenderCopy(renderer, winGameImage, NULL, &destRect);
        }
    }

    void cleanup() {
        if (menuImage) {
            SDL_DestroyTexture(menuImage);
            menuImage = NULL;
        }
        if (startButtonImage) {
            SDL_DestroyTexture(startButtonImage);
            startButtonImage = NULL;
        }
        if (settingButtonImage) {
            SDL_DestroyTexture(settingButtonImage);
            settingButtonImage = NULL;
        }
        if (gameOverImage) {
            SDL_DestroyTexture(gameOverImage);
            gameOverImage = NULL;
        }
        if (winGameImage) {
            SDL_DestroyTexture(winGameImage);
            winGameImage = NULL;
        }
    }
};

#endif
