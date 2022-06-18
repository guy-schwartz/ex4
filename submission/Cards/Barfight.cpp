//
// Created by Guy Schwartz on 09/06/2022.
//
#include "Barfight.h"

Barfight::Barfight(): Card("Barfight"), m_damage(DAMAGE) {}

Card* Barfight::clone() const {
    return new Barfight(*this);
}

void Barfight::applyEncounter(Player &player) const {
    if(player.getJob()==FIGHTER){
        printBarfightMessage(true);
    }
    else{
        player.damage(m_damage);
        printBarfightMessage(false);
    }
}
