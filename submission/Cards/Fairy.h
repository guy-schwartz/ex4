//
// Created by Guy Schwartz on 09/06/2022.
//

#ifndef EX4_FAIRY_H
#define EX4_FAIRY_H

#include "Card.h"

const std::string FAIRY="Fairy";

class Fairy : public Card{
public:
    static const int HEAL = 10;

    Fairy();
    ~Fairy() override = default;

    Fairy* clone() const override;

    /**
     * Handles player encounter with the card
     *
     * @param player - The player.
     * @return
     *      void
    **/
    void applyEncounter(Player& player) const override;


private:
    const int m_heal;
};
#endif //EX4_FAIRY_H
