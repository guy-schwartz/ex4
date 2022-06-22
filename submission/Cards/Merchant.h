//
// Created by Guy Schwartz on 09/06/2022.
//

#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H

#include "Card.h"

const std::string MERCHANT_CARD = "Merchant";

class Merchant : public Card{
    static const int HEAL = 1;
    static const int BUFF = 1;
    static const int BUFF_PRICE = 10;
    static const int HEAL_PRICE = 5;
    static const int LEAVE = 0;
    static const int BUY_HP = 1;
    static const int BUY_FORCE = 2;
public:
    Merchant();
    ~Merchant() override = default;

    Merchant* clone() const override;

    /**
     * Handles player encounter with the card
     *
     * @param player - The player.
     * @return
     *      void
    **/
    void applyEncounter(Player& player) const override;

    /**
     * get buying choice from user
     * @return
     */
    static int getChoice();

private:
    const int m_heal;
    const int m_buff;
    const int m_healPrice;
    const int m_buffPrice;
};
#endif //EX4_MERCHANT_H
