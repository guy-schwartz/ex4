
//
// Created by Guy Schwartz on 09/06/2022.
//

#ifndef EX4_PITFALL_H
#define EX4_PITFALL_H

#include "Card.h"


class Pitfall : public Card{
public:
    Pitfall();
    ~Pitfall() override = default;

    Card* clone() const override;

    /**
     * Handles non-Rogue player encounter with the card
     *
     * @param player - The player.
     * @return
     *      void
    **/
    void applyEncounter(Player& player) const override;

    /**
     * Handles Rogue player encounter with the card
     *
     * @param player - The player.
     * @return
     *      void
    **/
    void applyEncounter(Rogue& player) const;

private:
    const int m_damage;
};
#endif //EX4_PITFALL_H
