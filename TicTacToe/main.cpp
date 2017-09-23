
#include <iostream>
#include "ticTacToe.h"

int main() {
    //Declare and build game
    ticTacToe game;
    game.drawBoard();
    //set end conditions to flase
    game.setBoardFull(false);
    game.setGameWon(false);

    //start the game
    game.playGame();

    //display win, los or tie text and offer to start a new game

}