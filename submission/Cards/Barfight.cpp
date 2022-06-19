//
// Created by Guy Schwartz on 09/06/2022.
//
#include "Barfight.h"

Barfight::Barfight(): Card("Barfight"), m_damage(DAMAGE) {}

Card* Barfight::clone() const {
    return new Barfight(*this);
}

void Barfight::applyEncounter(Player &player) const {
    try{
        Fighter &fighter = dynamic_cast<Fighter&>(player);
        printBarfightMessage(true);
    }
    catch(const std::bad_cast&){
        player.damage(m_damage);
        printBarfightMessage(false);
    }
}
