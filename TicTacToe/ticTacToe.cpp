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

}//end drawBoard

void ticTacToe::playGame() {
    do{
        playerMove();
        drawBoard();
    }
    while(!boardFull || !gameWon);
}//end playGame()

void ticTacToe::playerMove() {
    int x;
    std::cout << "Which squid do you want to play on?" << std::endl;
    std::cin >> x;
    checkSquare(x, 'X');
}//end payerMove

bool ticTacToe::checkSquare(int move, char player){
    if(move < 4){
        if(board[0][move - 1] != 'X' && board[0][move - 1] != 'O'){
            board[0][move - 1] = player;
        }else{}
    }else if(move < 6){
        if(board[1][move - 4] != 'X' && board[1][move - 4] != 'O'){
            board[1][move - 4] = player;
        }
    }else{
        if(board[2][move - 7] != 'X' && board[2][move - 7] != 'O'){
            board[2][move - 7] = player;
        }
    }
}//end checkSquare

bool ticTacToe::checkFull() {
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if( board[i][j] == 'X' || board[i][j] == 'O'){
                return boardFull = true;
            }
        }
    }//end for loop
    return boardFull = false;
}//end checkFull

bool ticTacToe::checkWin(char player){
    //loop through win conditions and check to see if player passed to method won
//    if(board[0,1,2] == player){
//
//    }
}//end checkWin

bool ticTacToe::isBoardFull() const {
    return boardFull;
}

void ticTacToe::setBoardFull(bool boardFull) {
    ticTacToe::boardFull = boardFull;
}

bool ticTacToe::isGameWon() const {
    return gameWon;
}

void ticTacToe::setGameWon(bool gameWon) {
    ticTacToe::gameWon = gameWon;
}




