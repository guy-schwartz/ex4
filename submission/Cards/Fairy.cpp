//
// Created by Guy Schwartz on 09/06/2022.
//
#include "Fairy.h"

Fairy::Fairy(): Card(FAIRY), m_heal(HEAL) {}

Fairy* Fairy::clone() const {
    return new Fairy(*this);
}

void Fairy::applyEncounter(Player &player) const {
    try{
        dynamic_cast<Wizard&>(player);
        player.heal(m_heal);
        printFairyMessage(true);
    }
    catch (std::bad_cast&){
        printFairyMessage(false);
    }
}
