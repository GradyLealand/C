//draw board code taken from cplusepluse.com/forum/beginner/5260

#include "ticTacToe.h"
#include <iostream>

//build game
ticTacToe::ticTacToe(){
    //declare players
    //fill array board[]
    char charArray[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for(int i = 0; i <9; i++){
        if(i < 3){
            board[0][i] = charArray[i];
        }else if(i < 6){
            board[1][i - 3] = charArray[i];
        }else{
            board[2][i - 6] = charArray[i];
        }
    }

}
void ticTacToe::drawBoard(){
    std::cout   << std::endl
                << board[0][0] << " │ " << board[0][1] << " │ " << board[0][2]
                << "\n──┼───┼──\n"
                << board[1][0] << " │ " << board[1][1] << " │ " << board[1][2]
                << "\n──┼───┼──\n"
                << board[2][0] << " │ " << board[2][1] << " │ " << board[2][2]
                << std::endl;

}

void ticTacToe::playGame() {
    do{

    }
    while(!boardFull || !gameWon);
}

bool ticTacToe::checkFull(char myArray[]) {
//    for(int i = 0; i < sizeof(myArray); ++i){
//
//    }

}

bool ticTacToe::checkWin(char player){
    //loop through win conditions and check to see if player passed to method won
//    if(board[0,1,2] == player){
//
//    }

}


