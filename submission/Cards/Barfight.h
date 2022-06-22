//
// Created by Guy Schwartz on 09/06/2022.
//

#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H

#include "Card.h"

const std::string FIGHTER="Fighter";

class Barfight : public Card{
public:
    static const int DAMAGE = 10;

    Barfight();
    ~Barfight() override = default;

    Barfight* clone() const override;

    /**
     * Handles non-Fighter player encounter with the card
     *
     * @param player - The player.
     * @return
     *      void
    **/
    void applyEncounter(Player& player) const override;



private:
    const int m_damage;
};
#endif //EX4_BARFIGHT_H
