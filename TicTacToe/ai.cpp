//
// Created by prog2100 on 27/09/17.
//

#include "ticTacToe.h"
#include <cstdlib>

int ai::randomMove() {
    int move = rand() %9;
    return move + 1;
}