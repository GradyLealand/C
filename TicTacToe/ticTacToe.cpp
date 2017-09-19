//draw board code taken from cplusepluse.com/forum/beginner/5260

#include "ticTacToe.h"
#include <iostream>

//build game
ticTacToe::ticTacToe(){
    //declare players
    //fill array board[]
    char charArray[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for(int i = 0; i <9; i++){
        board[i] = charArray[i];
    }

}
void ticTacToe::drawBoard(){
    std::cout   << std::endl
                << board[0] << " │ " << board[1] << " │ " << board[2]
                << "\n──┼───┼──\n"
                << board[3] << " │ " << board[4] << " │ " << board[5]
                << "\n──┼───┼──\n"
                << board[6] << " │ " << board[7] << " │ " << board[8]
                << std::endl;

}

void ticTacToe::playGame() {
    do{

    }
    while(!boardFull || !gameWon);
}
