//
// Created by Guy Schwartz on 09/06/2022.
//

#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include "Card.h"


class Dragon : public Card{
public:
    Dragon();
    ~Dragon() override = default;

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
};
#endif //EX4_DRAGON_H
