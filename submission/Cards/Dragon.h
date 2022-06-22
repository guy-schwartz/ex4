//
// Created by Guy Schwartz on 09/06/2022.
//

#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include "Battle.h"

const std::string DRAGON_CARD= "Dragon";

class Dragon : public Battle{
public:
    static const int LOOT = 1000;
    static const int FORCE = 25;

    Dragon();
    ~Dragon() override = default;

    Dragon* clone() const override;

    /**
     * printing method for operator<<
     * @param out
     */
    void print(std::ostream& out) const override;

    /**
     * apply damage on player
     * @param player
     */
    void damage(Player &player) const override;

    /**
     * Handles player encounter with the card
     *
     * @param player - The player.
     * @return
     *      void
    **/
    void applyEncounter(Player& player) const override;

};
#endif //EX4_DRAGON_H
