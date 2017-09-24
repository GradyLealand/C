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
    bool playable;
    char humanPlayer;
    char cpuPlayer;

public:
    ticTacToe();
    void drawBoard();
    void playGame();
    void playerMove();
    bool checkFull();
    bool checkWin();
    bool checkSquare(int move, char player);
    bool isBoardFull() const;
    void setBoardFull(bool boardFull);
    bool isGameWon() const;
    void setGameWon(bool gameWon);

};


#endif //TICTACTOE_TICTACTOE_H
