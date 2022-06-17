//
// Created by Guy Schwartz on 09/06/2022.
//
#include "Card.h"

using std::string;

Card::Card(const std::string& name) : m_name(name){}

void Card::print(std::ostream& out) const{
    printCardDetails(out,m_name);
    printEndOfCardDetails(out);
}


std::ostream& operator<<(std::ostream& out, const Card& card)
{
    card.print(out);
    return out;
}
