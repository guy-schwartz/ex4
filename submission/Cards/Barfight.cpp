//
// Created by Guy Schwartz on 09/06/2022.
//
#include "Barfight.h"

Barfight::Barfight(): Card("Barfight"), m_damage(10) {}

Card* Barfight::clone() const {
    return new Barfight(*this);
}

void Barfight::applyEncounter(Player &player) const {
    player.damage(m_damage);
    printBarfightMessage(false);
}

void Barfight::applyEncounter(Fighter& player) const {
    printBarfightMessage(true);
}
