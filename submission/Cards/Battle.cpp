//
// Created by Guy Schwartz on 21/06/2022.
//

#include "Battle.h"

Battle::Battle(const std::string &name, int loot, int force, int damage) : Card(name), m_loot(loot), m_force(force), m_damage(damage) {}


bool Battle::playerWin(Player &player) const {
    if(player.getAttackStrength()>=m_force){
        return true;
    }
    else{
        return false;
    }
}

void Battle::print(std::ostream &out) const {
    printCardDetails(out,m_name);
    printMonsterDetails(out,m_force,m_damage,m_loot,false);
    printEndOfCardDetails(out);
}

int Battle::getLoot() const {
    return m_loot;
}

