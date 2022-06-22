//
// Created by Guy Schwartz on 09/06/2022.
//

#ifndef EX4_VAMPIRE_H
#define EX4_VAMPIRE_H

#include "Battle.h"

const std::string VAMPIRE_CARD = "Vampire";

class Vampire : public Battle{
public:
    static const int FORCE = 10;
    static const int LOOT = 2;
    static const int DAMAGE = 10;

    Vampire();
    ~Vampire() override = default;

    Vampire* clone() const override;

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

private:
    const int m_forceDamage;
};
#endif //EX4_VAMPIRE_H
