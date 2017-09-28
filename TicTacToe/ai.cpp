//
// Created by prog2100 on 27/09/17.
//

#include "ticTacToe.h"
#include <cstdlib>
//set center first to true
bool playedOnce = false;
bool claimedThree = false;
bool claimedSeven = false;


int ai::randomMove(int move, bool centerPlay) {
    //if player has not played int he center
    if(!centerPlay){
        //if the second time playing check tosay center was not the players first move
        if(playedOnce){
            centerFirst = false;
        }
        //check for a free corner
        if(move == 1){
            return 1;
        }else if(move == 2){
            return 9 ;
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
        playedOnce = true; //will trigger the first time the ai plays

    }else if(centerFirst){//if the player has played in the center for there first move
        if(move == 1){
            return 1;
        }else if(move == 2){
            return 2 ;
        }else if(move == 3){
            return 3;
        }else if(move == 4){
            return 7;
        }else if(move == 5){
            return 4;
        }else if(move == 6){
            return 6;
        }else if(move == 7){
            return 8;
        }else if(move == 8){
            return 9;
        }
    }else if(!claimedThree && !claimedSeven){
        if(move == 1){
            return 1;
        }else if(move == 2){
            return 3;
        }else if(move == 3){
            return 7;
        }else if(move == 4){
            return 4;
        }else if(move == 5){
            return 6;
        }else if(move == 6){
            return 8;
        }
    }

}