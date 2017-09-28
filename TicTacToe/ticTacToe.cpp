//draw board code taken from cplusepluse.com/forum/beginner/5260
/*
 * This class performs all game functions including the players turn and
 * check win conditions, whether or not the board is full and if the square is
 * free to be played on.
 */

#include "ticTacToe.h"
#include <iostream>

//instance the ai to be used
ai comp;

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

    char turn = 't';// jsut a char that is not 1 or 2
    while(turn != 1 && turn != 2){
        std::cout << "would you like to play first (1) or second (2)" << std::endl;
        std::cin >> turn;
        if(turn == '1' || turn == '2'){
            break;
        }
        std::cout << "invalid option" << std::endl;
    }
    //player plays first
    if (turn == '1'){
        //set booleans to false so game will play
        gameWon = false;
        boardFull = false;
        while(!boardFull && !gameWon){
            //players turn
            drawBoard();
            playerMove();
            gameWon = checkWin();
            if(gameWon){
                std::cout << "\nPlayer has won" << std::endl;
                break;
            }else if(boardFull) {
                std::cout << "\nThe game has ended in a tie" << std::endl;
                break;
            }

            //ai's turn1
            std::cout << "\nTacAi made its move" << std::endl;
            int move = comp.randomMove(1, false);
            checkSquare(move, 'O');
            boardFull = checkFull();
            gameWon = checkWin();
            if(gameWon){
                std::cout << "\nAi has won" << std::endl;
                break;
            }
            drawBoard();
        }
    }
    //ai plays first
    else{
        //set booleans to false so gme will play
        gameWon = false;
        boardFull = false;
        while(!boardFull && !gameWon){
            //ai's turn1
            std::cout << "\nTacAi made its move" << std::endl;
            int move = comp.randomMove(1, false);
            checkSquare(move, 'O');
            boardFull = checkFull();
            gameWon = checkWin();
            if(gameWon){
                std::cout << "\nAi has won" << std::endl;
                break;
            }else if(boardFull) {
                std::cout << "\nThe game has ended in a tie" << std::endl;
                break;
            }

            drawBoard();

            //players turn
            playerMove();
            gameWon = checkWin();
            if(gameWon){
                std::cout << "\nPlayer has won" << std::endl;
                break;
            }
            drawBoard();
        }
        drawBoard();
    }
}//end playGame()

void ticTacToe::playerMove() {
    int x;
    std::cout << "\nWhich square do you want to play on?" << std::endl;
    std::cin >> x;
    checkSquare(x, 'X');
}//end payerMove

bool ticTacToe::checkSquare(int move, char player){
    //set false by default
    playable = false;
    int aiMove = 1;
    bool centerPlay = false;
    while(playable == false){
        if(move < 4){
            if(board[0][move - 1] != 'X' && board[0][move - 1] != 'O'){
                board[0][move - 1] = player;
                playable = true;
            }
        }else if(move < 6){
            if(board[1][move - 4] != 'X' && board[1][move - 4] != 'O'){
                board[1][move - 4] = player;
                playable = true;
            }
        }else{
            if(board[2][move - 7] != 'X' && board[2][move - 7] != 'O'){
                board[2][move - 7] = player;
                playable = true;
            }
        }
        if(playable == false){
            if(player == 'X'){
                std::cout << "space already taken. Please Pick another" << std::endl;
                std::cin >> move;
            }else if(player == 'O'){
                if(board[1][1] == 'X'){
                    centerPlay = true;
                    aiMove++;
                    move =comp.randomMove(aiMove, centerPlay);
                }else{
                    aiMove++;
                    move = comp.randomMove(aiMove, centerPlay);
                }

            }
        }
    }
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
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            return true;
        }else if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            return true;
        }
    }//end loop
    //check both diagonal win conditions
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        return true;
    }else if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
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




