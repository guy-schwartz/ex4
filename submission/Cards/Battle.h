//
// Created by Guy Schwartz on 21/06/2022.
//

#ifndef EX4_BATTLE_H
#define EX4_BATTLE_H

#include "Card.h"

class Battle : public Card{
public:
    /**
     * C'tor of Battle
     * @param loot
     * @param force
     */
    Battle(const std::string &name, int loot, int force, int damage);

    /**
     * D'tor of Battle
     */
    ~Battle() override = default;

    virtual Battle* clone() const override = 0;

    /**
     * check if player won or not
     */
     bool playerWin(Player &player) const;


     /**
      * printing fuction for monsters (non-Dragon)
      * @param out
      */
    virtual void print(std::ostream& out) const override;

    /**
     * returns the loot of the card
     * @return
     */
    int getLoot() const;

    /**
     * applies the damage to the player
     * @param player
     */
    virtual void damage(Player &player) const = 0;


protected:
    int m_loot;
    int m_force;
    int m_damage;
};


#endif //EX4_BATTLE_H
