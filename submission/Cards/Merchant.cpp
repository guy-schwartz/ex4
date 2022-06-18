//
// Created by Guy Schwartz on 09/06/2022.
//

#include "Merchant.h"

Merchant::Merchant() : Card("Merchant"), m_heal(HEAL), m_buff(BUFF), m_buffPrice(BUFF_PRICE), m_healPrice(HEAL_PRICE) {}

Card* Merchant::clone() const {
    return new Merchant(*this);
}

void Merchant::applyEncounter(Player &player) const {
    printMerchantInitialMessageForInteractiveEncounter(std::cout,player.getName(),player.showCoins());
    while(true){
        try{
            switch (getChoice()){
                case LEAVE:
                    printMerchantSummary(std::cout,player.getName(),LEAVE,0);
                    break;
                case BUY_HP:
                    if(player.pay(m_healPrice)){
                        player.heal(m_heal);
                        printMerchantSummary(std::cout,player.getName(),BUY_HP,m_healPrice);
                    }
                    else{
                        printMerchantInsufficientCoins(std::cout);
                    }
                    break;
                case BUY_FORCE:
                    if(player.pay(m_buffPrice)){
                        player.buff(m_buff);
                        printMerchantSummary(std::cout,player.getName(),BUY_FORCE,m_buffPrice);
                    }
                    else{
                        printMerchantInsufficientCoins(std::cout);
                    }
                    break;
                default:
                    throw std::out_of_range("bad number");
            }
        }
        catch(...){
            printInvalidInput();
            continue;
        }
        break;
    }
}


int Merchant::getChoice() {
        std::string tempString;
        std::getline(std::cin,tempString);
        return std::stoi(tempString);
}