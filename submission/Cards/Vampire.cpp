//
// Created by Guy Schwartz on 09/06/2022.
//
#include "Vampire.h"

Vampire::Vampire() : Battle(VAMPIRE_CARD,LOOT,FORCE,DAMAGE), m_forceDamage(1) {}

Vampire* Vampire::clone() const {
    return new Vampire(*this);
}

void Vampire::applyEncounter(Player &player) const {
    if(playerWin(player)){
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(),m_name);
    }
    else{
        damage(player);
    }
}

void Vampire::damage(Player &player) const {
    player.damage(m_damage);
    player.hitForce(m_forceDamage);
    printLossBattle(player.getName(),m_name);
}
