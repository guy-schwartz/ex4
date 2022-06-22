//
// Created by Guy Schwartz on 09/06/2022.
//
#include "Goblin.h"

Goblin::Goblin(): Battle(GOBLIN_CARD,LOOT,FORCE,DAMAGE) {}

Goblin* Goblin::clone() const {
    return new Goblin(*this);
}

void Goblin::applyEncounter(Player &player) const {
    if(playerWin(player)){
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(),m_name);
    }
    else{
        damage(player);
    }
}

void Goblin::damage(Player &player) const {
    player.damage(m_damage);
    printLossBattle(player.getName(),m_name);
}
