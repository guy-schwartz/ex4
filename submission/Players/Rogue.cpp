//
// Created by Guy Schwartz on 09/06/2022.
//
#include "Rogue.h"

Rogue::Rogue(const std::string& name) : Player(name) {}

void Rogue::addCoins(int coinsToAdd){
    if(coinsToAdd<0){
        return;
    }
    m_coins+=(2*coinsToAdd);
}

void Rogue::print(std::ostream& out) const{
    printPlayerDetails(out,m_name,"Rogue",m_level,m_force,m_HP,m_coins);
}
