//
// Created by Guy Schwartz on 09/06/2022.
//

#ifndef EX4_VAMPIRE_H
#define EX4_VAMPIRE_H

#include "Card.h"

class Vampire : public Card{
public:
    Vampire();
    ~Vampire() override = default;

    Card* clone() const override;

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
    const int m_forceDamage;
};
#endif //EX4_VAMPIRE_H
