//
// Created by Guy Schwartz on 09/06/2022.
//
#include "Fighter.h"

Fighter::Fighter(const string& name) : Player(name) {}

int Fighter::getAttackStrength() const{
    return (2*m_force+m_level);
}

void Fighter::print(ostream& out) const{
    printPlayerDetails(out,m_name,"Fighter",m_level,m_force,m_HP,m_coins);
}