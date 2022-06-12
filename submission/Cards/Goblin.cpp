//
// Created by Guy Schwartz on 09/06/2022.
//
#include "Goblin.h"
Goblin::Goblin(): Card("Goblin"), m_force(6), m_loot(2), m_damage(10) {}


void Goblin::print(std::ostream &out) const {
    printCardDetails(out,m_name);
    printMonsterDetails(out,m_force,m_damage,m_loot,false);
    printEndOfCardDetails(out);
}

void Goblin::applyEncounter(Player &player) const {
    if(player.getAttackStrength()>=m_force){
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(),m_name);
    }
    else{
        player.damage(m_damage);
        printLossBattle(player.getName(),m_name);
    }
}