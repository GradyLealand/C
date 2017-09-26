//draw board code taken from cplusepluse.com/forum/beginner/5260
/*
 * This class performs all game functions including the players turn and
 * check win conditions, whether or not the board is full and if the square is
 * free to be played on.
 */

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

//run the game
void ticTacToe::playGame() {
    do{
        //players turn
        playerMove();
        boardFull = checkFull();
        gameWon = checkWin();
            if(gameWon){
                std::cout << "Player has won" << std::endl;
                break;
            }else if(boardFull){
                std::cout << "The game has ended in a tie" << std::endl;
                break;
            }
        //ai's turn1
        drawBoard();
    }
    while(!boardFull && !gameWon);
    drawBoard();
}//end playGame()

void ticTacToe::playerMove() {
    int x;
    std::cout << "Which square do you want to play on?" << std::endl;
    std::cin >> x;
    checkSquare(x, 'X');
}//end payerMove

bool ticTacToe::checkSquare(int move, char player){
    //set false by default
    playable = false;
    do{
        if(move < 4){
            if(board[0][move - 1] != 'X' && board[0][move - 1] != 'O'){
                board[0][move - 1] = player;
                playable = true;
            }else{ std::cout << "space already taken. Please Pick another" << std::endl;}
        }else if(move < 6){
            if(board[1][move - 4] != 'X' && board[1][move - 4] != 'O'){
                board[1][move - 4] = player;
            }else{ std::cout << "space already taken. Please Pick another" << std::endl;}
        }else{
            if(board[2][move - 7] != 'X' && board[2][move - 7] != 'O'){
                board[2][move - 7] = player;
            }else{ std::cout << "space already taken. Please Pick another" << std::endl;}
        }
    }while(playable = false);
}//end checkSquare

bool ticTacToe::checkFull() {
    for (auto &i : board) {
        for (char j : i) {
            if(j != 'X' && j != 'O'){
                return false;
            }
        }
    }//end for loop
    return true;
}//end checkFull

bool ticTacToe::checkWin(){
    //loop through straight line win conditions and check to see if a player has won
    for(int i = 0; i < 3; ++i){
        char x = board[i][0];
        char y = board[i][1];
        char z = board[i][2];
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            return true;
        }else if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            return true;
        }
    }//end loop
    //check both diagonal win conditions
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        return true;
    }else if(board[0][2] == board[1][1] && board[1][1] == board[0][2]){
        return true;
    }
    //if no one won return false
    return false;
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




