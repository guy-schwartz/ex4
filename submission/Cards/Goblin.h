//
// Created by Guy Schwartz on 09/06/2022.
//

#ifndef EX4_GOBLIN_H
#define EX4_GOBLIN_H

#include "Battle.h"

const std::string GOBLIN_CARD = "Goblin";

class Goblin : public Battle{
public:
    static const int LOOT = 2;
    static const int FORCE = 6;
    static const int DAMAGE = 10;

    Goblin();
    ~Goblin() override = default;

    Goblin* clone() const override;

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
#endif //EX4_GOBLIN_H
