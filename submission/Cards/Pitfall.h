
//
// Created by Guy Schwartz on 09/06/2022.
//

#ifndef EX4_PITFALL_H
#define EX4_PITFALL_H

#include "Card.h"

const std::string PITFALL_CARD = "Pitfall";

class Pitfall : public Card{
public:

    Pitfall();
    ~Pitfall() override = default;

    Pitfall* clone() const override;

    /**
     * Handles player encounter with the card
     *
     * @param player - The player.
     * @return
     *      void
    **/
    void applyEncounter(Player& player) const override;



private:
    const int m_damage;
};
#endif //EX4_PITFALL_H
