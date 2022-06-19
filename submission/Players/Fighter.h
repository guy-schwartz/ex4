//
// Created by Guy Schwartz on 09/06/2022.
//

#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H

#include "Player.h"
#include "../utilities.h"

class Fighter : public Player{

public:
    const std::string FIGHTER_JOB = "Fighter";

    /**
      * c'tor for fighter
      * @param name
      */
    Fighter(const std::string& name);

    /**
     * default d'tor for fighter
     * @param name
     */
    ~Fighter() override=default;


    Player* clone() const override;

    /**
     * calculates a value which is defined by 2*force+level and returns it
     */
    int getAttackStrength() const override;

    /**
     * suitable printing function
     * @param out
     */
    void print(std::ostream& out) const override;



};
#endif //EX4_FIGHTER_H
