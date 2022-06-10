//
// Created by Guy Schwartz on 09/06/2022.
//

#ifndef EX4_CARD_H
#define EX4_CARD_H
#include <string>
#include <iostream>
using namespace std;

class Card{
public:
    /**
     * c'tor of Card class
     * @param name
     */
    explicit Card(const string& name);
    virtual ~Card()=default;

    /**
     * printing method for operator<<, to be defined in inheriting classes
     * @param out
     */
    virtual void print(ostream& out) const = 0;

    /**
     * operator<<, prints the following template: <name> <level> <Force> <Hp> <Coins> <Class>
     * @param out
     */
    friend ostream& operator<<(ostream& out, const Card& card);

protected:
    string m_name;
};

#endif //EX4_CARD_H
