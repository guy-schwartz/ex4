//
// Created by Guy Schwartz on 09/06/2022.
//
#include "Dragon.h"
Dragon::Dragon(): Card("Dragon"), m_force(25), m_loot(1000) {}

Card* Dragon::clone() const {
    return new Dragon(*this);
}

void Dragon::print(std::ostream &out) const {
    printCardDetails(out,m_name);
    printMonsterDetails(out,m_force,0,m_loot,true);
    printEndOfCardDetails(out);
}

void Dragon::applyEncounter(Player &player) const {
    if(player.getAttackStrength()>=m_force){
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(),m_name);
    }
    else{
        player.damage(player.showHP());
        printLossBattle(player.getName(),m_name);
    }
}