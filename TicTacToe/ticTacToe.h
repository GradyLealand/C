//
// Created by prog2100 on 19/09/17.
//

#ifndef TICTACTOE_TICTACTOE_H
#define TICTACTOE_TICTACTOE_H


class ticTacToe {
private:
    char board[3][3];
    bool boardFull;
    bool gameWon;

public:
    ticTacToe();
    void drawBoard();
    void playGame();
    bool checkFull(char myArray[]);
    bool checkWin(char player);

};


#endif //TICTACTOE_TICTACTOE_H
