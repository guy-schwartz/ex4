//
// Created by Guy Schwartz on 09/06/2022.
//
#include "Dragon.h"
Dragon::Dragon(): Battle(DRAGON_CARD,LOOT,FORCE,0)  {}

Dragon* Dragon::clone() const {
    return new Dragon(*this);
}

void Dragon::print(std::ostream &out) const {
    printCardDetails(out,m_name);
    printMonsterDetails(out,m_force,0,m_loot,true);
    printEndOfCardDetails(out);
}

void Dragon::applyEncounter(Player &player) const {
    if(playerWin(player)){
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(),m_name);
    }
    else{
        damage(player);
    }
}

void Dragon::damage(Player &player) const {
    player.damage(player.showHP());
    printLossBattle(player.getName(),m_name);
}