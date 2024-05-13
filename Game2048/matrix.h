#ifndef _MATRIX__H
#define _MATRIX__H

#include <fstream>
#include <ctime>
#include <string>
#include <SDL.h>
#include "tile.h"
#include "defs.h"

using namespace std;

class Matrix{
private:
    Tile tiles[ROWS][COLS];
    int score = 0;
    int highScore = 0;
    int currentScore = 0;

public:
    Matrix(){
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                tiles[i][j] = Tile(216+124*j, 188+123*i, 121, 0, {128, 128, 128});
            }
        }
        GenerateTile();
        GenerateTile();
    }

    bool GenerateTile(){
        int TilesLeft = 0;
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(tiles[i][j].getValue() == 0) {
                    TilesLeft++;
                }
            }
        }
        if(TilesLeft == 0) return false;

        srand(time(NULL));
        int i = rand() % 4;
        int j = rand() % 4;
        while(tiles[i][j].getValue() != 0){
            i = rand() % 4;
            j = rand() % 4;
        }
        tiles[i][j].setValue((rand() % 2 + 1) * 2);
        return true;
    }

    void mergeTiles(int startRow, int startCol, int destRow, int destCol){
        tiles[destRow][destCol].setValue(tiles[startRow][startCol].getValue() * 2);
        tiles[startRow][startCol].setValue(0);
        score += tiles[destRow][destCol].getValue();
    }

    bool moveUp(){
        bool moved = false;
        for (int j = 0; j < COLS; ++j){
            for (int i = 1; i < ROWS; ++i){
                if (tiles[i][j].getValue() != 0){
                    int row = i;
                    while (row > 0 && (tiles[row - 1][j].getValue() == 0 ||
                                       tiles[row - 1][j].getValue() == tiles[i][j].getValue())){
                        if (tiles[row - 1][j].getValue() == tiles[i][j].getValue()){
                            mergeTiles(i, j, row - 1, j);
                            moved = true;
                            break;
                        }
                        row--;
                    }
                    if (row != i){
                        tiles[row][j].setValue(tiles[i][j].getValue());
                        tiles[i][j].setValue(0);
                        moved = true;
                    }
                }
            }
        }
        return moved;
    }

    bool moveDown(){
        bool moved = false;
        for (int j = 0; j < COLS; ++j){
            for (int i = ROWS - 2; i >= 0; --i){
                if (tiles[i][j].getValue() != 0){
                    int row = i;
                    while (row < ROWS - 1 && (tiles[row + 1][j].getValue() == 0 ||
                                              tiles[row + 1][j].getValue() == tiles[i][j].getValue())){
                        if (tiles[row + 1][j].getValue() == tiles[i][j].getValue()){
                            mergeTiles(i, j, row + 1, j);
                            moved = true;
                            break;
                        }
                        row++;
                    }
                    if (row != i){
                        tiles[row][j].setValue(tiles[i][j].getValue());
                        tiles[i][j].setValue(0);
                        moved = true;
                    }
                }
            }
        }
        return moved;
    }

    bool moveLeft(){
        bool moved = false;
        for (int i = 0; i < ROWS; ++i){
            for (int j = 1; j < COLS; ++j){
                if (tiles[i][j].getValue() != 0){
                    int col = j;
                    while (col > 0 && (tiles[i][col - 1].getValue() == 0 ||
                                       tiles[i][col - 1].getValue() == tiles[i][j].getValue())){
                        if (tiles[i][col - 1].getValue() == tiles[i][j].getValue()){
                            mergeTiles(i, j, i, col - 1);
                            moved = true;
                            break;
                        }
                        col--;
                    }
                    if (col != j){
                        tiles[i][col].setValue(tiles[i][j].getValue());
                        tiles[i][j].setValue(0);
                        moved = true;
                    }
                }
            }
        }
        return moved;
    }

    bool moveRight(){
        bool moved = false;
        for (int i = 0; i < ROWS; ++i){
            for (int j = COLS - 2; j >= 0; --j){
                if (tiles[i][j].getValue() != 0){
                    int col = j;
                    while (col < COLS - 1 && (tiles[i][col + 1].getValue() == 0 ||
                                              tiles[i][col + 1].getValue() == tiles[i][j].getValue())){
                        if (tiles[i][col + 1].getValue() == tiles[i][j].getValue()){
                            mergeTiles(i, j, i, col + 1);
                            moved = true;
                            break;
                        }
                        col++;
                    }
                    if (col != j){
                        tiles[i][col].setValue(tiles[i][j].getValue());
                        tiles[i][j].setValue(0);
                        moved = true;
                    }
                }
            }
        }
        return moved;
    }


    bool CheckIfWin(){
        for (int i = 0; i < ROWS; ++i){
            for (int j = 0; j < COLS; ++j){
                if (tiles[i][j].getValue() == 2048){
                    return true;
                }
            }
        }
        return false;
    }


    bool isGameOver(){
        for (int i = 0; i < ROWS; ++i){
            for (int j = 0; j < COLS; ++j){
                if (tiles[i][j].getValue() == 0){
                    return false;
                }
                if ((i < ROWS - 1 && tiles[i][j].getValue() == tiles[i + 1][j].getValue()) ||
                    (j < COLS - 1 && tiles[i][j].getValue() == tiles[i][j + 1].getValue())){
                    return false;
                }
            }
        }
        return true;
    }


    void updateCurrentScore(){
        currentScore = score;
    }

    void renderScore(SDL_Renderer* renderer, TTF_Font* font, Graphics& graphics, int x, int y) {
        SDL_Color textColor = {128, 128, 128};
        string currentScoreText = to_string(currentScore);
        graphics.renderText(currentScoreText, font, textColor, x, y, renderer);
    }

    int getHighScore(){
        return highScore;
    }

    void renderHighScore(SDL_Renderer* renderer, TTF_Font* font, Graphics& graphics, int x, int y){
        SDL_Color textColor = {128, 128, 128};
        string highScoreText = to_string(highScore);
        graphics.renderText(highScoreText, font, textColor, x, y, renderer);
    }

    void saveHighScore(){
        ofstream file("highscore.txt");
        if (file.is_open()){
            file << highScore;
            file.close();
        }
    }

    void loadHighScore(){
        ifstream file("highscore.txt");
        if (file.is_open()) {
            file >> highScore;
            file.close();
        }
    }

    void resetHighScore(){
        highScore = 0;
        saveHighScore();
    }

    void resetGame() {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                tiles[i][j].setValue(0);
            }
        }
        score = 0;
        updateCurrentScore();

        GenerateTile();
        GenerateTile();
    }

    void Events(SDL_Window* window, SDL_Event event){
        if (event.type == SDL_KEYDOWN) {
            bool moved = false;
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                    moved = moveUp();
                    break;
                case SDLK_DOWN:
                    moved = moveDown();
                    break;
                case SDLK_LEFT:
                    moved = moveLeft();
                    break;
                case SDLK_RIGHT:
                    moved = moveRight();
                    break;
                case SDLK_r:
                    resetHighScore();
                    cout << "High score has been reset" << endl;
                    break;
            }

        if (moved){
            GenerateTile();
            updateCurrentScore();
            if (score > highScore){
                    highScore = score;
                    saveHighScore();
                }
            }
        }
    }


    void render(SDL_Renderer* renderer){
        for (int i = 0; i < ROWS; ++i){
            for (int j = 0; j < COLS; ++j) {
                tiles[i][j].render(renderer);
            }
        }
    }
};

#endif
