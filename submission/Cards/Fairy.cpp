//
// Created by Guy Schwartz on 09/06/2022.
//
#include "Fairy.h"

Fairy::Fairy(): Card("Fairy"), m_heal(HEAL) {}

Card* Fairy::clone() const {
    return new Fairy(*this);
}

void Fairy::applyEncounter(Player &player) const {
    if(player.getJob()==WIZARD){
        player.heal(m_heal);
        printFairyMessage(true);
    }
    else{
        printFairyMessage(false);
    }
}
