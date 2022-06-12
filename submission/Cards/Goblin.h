//
// Created by Guy Schwartz on 09/06/2022.
//

#ifndef EX4_GOBLIN_H
#define EX4_GOBLIN_H

#include "Card.h"

class Goblin : public Card{
public:
    Goblin();
    ~Goblin() override = default;


    /**
     * printing method for operator<<
     * @param out
     */
    void print(std::ostream& out) const override;

    /**
     * Handles player encounter with the card
     *
     * @param player - The player.
     * @return
     *      void
    **/
    void applyEncounter(Player& player) const override;

private:
    const int m_loot;
    const int m_force;
    const int m_damage;
};
#endif //EX4_GOBLIN_H
