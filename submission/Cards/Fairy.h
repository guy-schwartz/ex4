//
// Created by Guy Schwartz on 09/06/2022.
//

#ifndef EX4_FAIRY_H
#define EX4_FAIRY_H

#include "Card.h"


class Fairy : public Card{
public:
    Fairy();
    ~Fairy() override = default;

    Card* clone() const override;

    /**
     * Handles non-Wizard player encounter with the card
     *
     * @param player - The player.
     * @return
     *      void
    **/
    void applyEncounter(Player& player) const override;

    /**
     * Handles Wizard player encounter with the card
     *
     * @param player - The player.
     * @return
     *      void
    **/
    void applyEncounter(Wizard& player) const;

private:
    const int m_heal;
};
#endif //EX4_FAIRY_H
