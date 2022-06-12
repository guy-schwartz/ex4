//
// Created by Guy Schwartz on 09/06/2022.
//

#include "Merchant.h"

Merchant::Merchant() : Card("Merchant"), m_heal(1), m_buff(1), m_buffPrice(10), m_healPrice(5) {}

void Merchant::applyEncounter(Player &player) const {
    printMerchantInitialMessageForInteractiveEncounter(std::cout,player.getName(),player.showCoins());
    char tempChoice[MAX_LEN];
    std::cin.getline(tempChoice,MAX_LEN); //todo: exceptions
    int choice=std::stoi(tempChoice);
    switch (choice){
        case 0:
            printMerchantSummary(std::cout,player.getName(),0,0);
            break;
        case 1:
            if(player.pay(m_healPrice)){
                player.heal(m_heal);
                printMerchantSummary(std::cout,player.getName(),1,m_healPrice);
            }
            else{
                printMerchantInsufficientCoins(std::cout);
            }
            break;
        case 2:
            if(player.pay(m_buffPrice)){
                player.buff(m_buff);
                printMerchantSummary(std::cout,player.getName(),2,m_buffPrice);
            }
            else{
                printMerchantInsufficientCoins(std::cout);
            }
            break;
        default:
            throw; //todo: exceptions
    }
}
