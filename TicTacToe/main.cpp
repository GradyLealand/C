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
    //build and declare game
    ticTacToe game;
    std::cout << "Welcome to TicTacToe.  You will Be playing agians TacAi." << std::endl;
    std::cout << "TacAi Will be 'O'  and you will be  'X' " << std::endl;

    game.playGame();



}