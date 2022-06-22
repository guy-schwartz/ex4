//
// Created by Guy Schwartz on 09/06/2022.
//

#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H

#include "Card.h"

const std::string TREASURE_CARD = "Treasure";

class Treasure : public Card{
public:
    Treasure();
    ~Treasure() override = default;

    Treasure* clone() const override;

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
};
#endif //EX4_TREASURE_H
