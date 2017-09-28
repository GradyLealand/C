//
// Created by prog2100 on 27/09/17.
//

#include "ticTacToe.h"
#include <cstdlib>
//set center first to true

int ai::randomMove(int move, bool centerPlay) {
    if(!centerPlay){
        //check for a free corner
        if(move == 1){
            return 1;
        }else if(move == 2){
            return 9;
        }else if(move == 3){
            return 3;
        }else if(move == 4){
            return 7;
        }else if(move == 5){
            return 5;
        }else if(move == 6){
            return 2;
        }else if(move == 7){
            return 4;
        }else if(move == 8){
            return 6;
        }else if(move == 9){
            return 8;
        }
    }else {//if the player has played in the center for there first move
        if(move == 1){
            return 1;
        }else if(move == 2){
            return 3;
        }else if(move == 3){
            return 8;
        }else if(move == 4){
            return 4;
        }else if(move == 5){
            return 6;
        }else if(move == 6){
            return 9;
        }else if(move == 7){
            return 7;
        }else if(move == 8){
            return 2;
        }
    }

}

void ai::setCenterFirst(bool centerFirst) {
    ai::centerFirst = centerFirst;
}

void ai::setPlayedOnce(bool playedOnce) {
    ai::playedOnce = playedOnce;
}

bool ai::isPlayedOnce() const {
    return playedOnce;
}

bool ai::isCenterFirst() const {
    return centerFirst;
}
