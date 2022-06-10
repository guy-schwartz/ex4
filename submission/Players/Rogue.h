//
// Created by Guy Schwartz on 09/06/2022.
//

#ifndef EX4_ROGUE_H
#define EX4_ROGUE_H

#include "Player.h"
#include "../utilities.h"

class Rogue : public Player{

public:
    /**
  * c'tor for rogue
  * @param name
  */
    explicit Rogue(const string& name);

    /**
     * default d'tor for rogue
     * @param name
     */
    ~Rogue() override=default;

    /**
    * member function adds coins by doubling the given value
    * in case of an undefined argument, coins member will remain unchanged
    * @param coinsToAdd - an integer
    */
    void addCoins(int coinsToAdd) override;

    /**
     * suitable printing function
     * @param out
     */
    void print(ostream& out) const override;

};

#endif //EX4_ROGUE_H
