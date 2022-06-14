//
// Created by Guy Schwartz on 09/06/2022.
//
#include "Fairy.h"

Fairy::Fairy(): Card("Fairy"), m_heal(10) {}

Card* Fairy::clone() const {
    return new Fairy(*this);
}

void Fairy::applyEncounter(Player &player) const {
    printFairyMessage(false);
}

void Fairy::applyEncounter(Wizard &player) const {
    player.heal(m_heal);
    printPitfallMessage(true);
}

