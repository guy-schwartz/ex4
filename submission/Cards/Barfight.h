//
// Created by Guy Schwartz on 09/06/2022.
//

#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H

#include "Card.h"

class Barfight : public Card{
public:
    Barfight();
    ~Barfight() override = default;

    /**
     * Handles non-Fighter player encounter with the card
     *
     * @param player - The player.
     * @return
     *      void
    **/
    void applyEncounter(Player& player) const override;

    /**
     * Handles Fighter player encounter with the card
     *
     * @param player - The player.
     * @return
     *      void
    **/
    void applyEncounter(Fighter& player) const;


private:
    const int m_damage;
};
#endif //EX4_BARFIGHT_H
