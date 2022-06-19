//
// Created by Guy Schwartz on 09/06/2022.
//
#include "Vampire.h"

Vampire::Vampire() : Card("Vampire"), m_loot(2), m_force(10),  m_damage(10), m_forceDamage(1) {}

Card* Vampire::clone() const {
    return new Vampire(*this);
}

void Vampire::print(std::ostream &out) const {
    printCardDetails(out,m_name);
    printMonsterDetails(out,m_force,m_damage,m_loot,false);
    printEndOfCardDetails(out);
}

void Vampire::applyEncounter(Player &player) const {
    if(player.getAttackStrength()>=m_force){
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(),m_name);
    }
    else{
        player.damage(m_damage);
        player.hitForce(m_forceDamage);
        printLossBattle(player.getName(),m_name);
    }
}