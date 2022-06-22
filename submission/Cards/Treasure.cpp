//
// Created by Guy Schwartz on 09/06/2022.
//
#include "Treasure.h"

Treasure::Treasure() : Card(TREASURE_CARD), m_loot(10){}

Treasure* Treasure::clone() const {
    return new Treasure(*this);
}

void Treasure::applyEncounter(Player& player) const{
    player.addCoins(m_loot);
    printTreasureMessage();
}