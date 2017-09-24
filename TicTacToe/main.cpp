/*
 * Project: ticTacToe
 * Author: Grady Williams
 * Date: september 28, 2017
 */

#include <iostream>
#include "ticTacToe.h"
/*
 * This class calls build the game and then starts it from the class
 * ticTacToe.
 */
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