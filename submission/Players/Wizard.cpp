//
// Created by Guy Schwartz on 09/06/2022.
//
#include "Wizard.h"

Wizard::Wizard(const std::string& name) : Player(name) {}

Wizard* Wizard::clone() const {
    return new Wizard(*this);
}

void Wizard::heal(int newPoints){
    if(newPoints<0){
        return;
    }
    int tempHP=m_HP+(2*newPoints);
    if(tempHP>MAX_HP){
        tempHP=MAX_HP;
    }
    m_HP=tempHP;
}

void Wizard::print(std::ostream& out) const{
    printPlayerDetails(out,m_name,WIZARD_JOB,m_level,m_force,m_HP,m_coins);
}
