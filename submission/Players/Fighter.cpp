//
// Created by Guy Schwartz on 09/06/2022.
//
#include "Fighter.h"

Fighter::Fighter(const std::string& name) : Player(name), m_job(FIGHTER_JOB) {}

Player* Fighter::clone() const {
    return new Fighter(*this);
}

int Fighter::getAttackStrength() const{
    return (2*m_force+m_level);
}

void Fighter::print(std::ostream& out) const{
    printPlayerDetails(out,m_name,FIGHTER_JOB,m_level,m_force,m_HP,m_coins);
}

std::string Fighter::getJob() const {
    return m_job;
}