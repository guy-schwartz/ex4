//
// Created by Guy Schwartz on 09/06/2022.
//
#include "Goblin.h"
Goblin::Goblin(): Card("Goblin"), m_force(FORCE), m_loot(LOOT), m_damage(DAMAGE) {}

Card* Goblin::clone() const {
    return new Goblin(*this);
}

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