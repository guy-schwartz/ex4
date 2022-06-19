//
// Created by Guy Schwartz on 09/06/2022.
//
#include "Pitfall.h"

Pitfall::Pitfall(): Card("Pitfall"), m_damage(10) {}

Card* Pitfall::clone() const {
    return new Pitfall(*this);
}

void Pitfall::applyEncounter(Player &player) const {
    try{
        dynamic_cast<Rogue&>(player);
        printPitfallMessage(true);
    }
    catch(std::bad_cast&){
        player.damage(m_damage);
        printPitfallMessage(false);
    }
}