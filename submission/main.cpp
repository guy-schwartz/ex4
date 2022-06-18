//
// Created by Guy Schwartz on 09/06/2022.
//

#include "Cards/Pitfall.h"
#include "Players/Rogue.h"
#include "Players/Fighter.h"
#include "Cards/Barfight.h"
#include "Cards/Treasure.h"
#include "Players/Wizard.h"
#include "Cards/Merchant.h"
#include "Cards/Vampire.h"
#include "Cards/Dragon.h"
#include "Mtmchkin.h"
using std::string;
using std::cin;
using std::cout;

int main(){
    const int MAX_ROUNDS = 100;
    Mtmchkin game("deck1.txt");
    while(!game.isGameOver() && game.getNumberOfRounds()<MAX_ROUNDS){
        game.playRound();
        game.printLeaderBoard();
    }
    return 0;
}