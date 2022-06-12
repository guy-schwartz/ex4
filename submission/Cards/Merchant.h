//
// Created by Guy Schwartz on 09/06/2022.
//

#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H

#include "Card.h"

const int MAX_LEN=2;

class Merchant : public Card{
public:
    Merchant();
    ~Merchant() override = default;

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
    const int m_buff;
    const int m_healPrice;
    const int m_buffPrice;
};
#endif //EX4_MERCHANT_H
