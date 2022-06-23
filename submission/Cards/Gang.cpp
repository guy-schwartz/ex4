//
// Created by Guy Schwartz on 19/06/2022.
//

#include <fstream>
#include "Gang.h"

using std::getline;
using std::string;
using std::unique_ptr;

Gang::Gang(std::fstream &file, int &countLines) : Card(GANG_CARD), m_battleCards(){
    string cardName;
    getline(file,cardName);
    while(cardName!=END_READ){
        try{
            countLines++;
            addToGang(cardName);
        }
        catch(DeckFileFormatError&){
            throw DeckFileFormatError(countLines);
        }
        if(file.eof()){
            throw DeckFileFormatError(countLines+1);
        }
        getline(file,cardName);
    }
    countLines++;
}

Gang* Gang::clone() const {
    return new Gang(*this);
}


void Gang::addToGang(std::string &cardName) {
    if(cardName==DRAGON_CARD){
        unique_ptr<Battle> pCard(new Dragon());
        m_battleCards.push_back(std::move(pCard));
    }
    else if(cardName==VAMPIRE_CARD){
        unique_ptr<Battle> pCard(new Vampire());
        m_battleCards.push_back(std::move(pCard));
    }
    else if(cardName==GOBLIN_CARD){
        unique_ptr<Battle> pCard(new Goblin());
        m_battleCards.push_back(std::move(pCard));
    }
    else{
        throw DeckFileFormatError(0);
    }
}

void Gang::applyEncounter(Player &player) const {
    bool didWinAll= true;
    for(unsigned int i=0 ; i<m_battleCards.size() ; i++){
        if(!m_battleCards[i]->playerWin(player)){
            didWinAll= false;
            for(; i<m_battleCards.size() ; i++){
                m_battleCards[i]->damage(player);
            }
        }
        else{
            player.addCoins(m_battleCards[i]->getLoot());
        }
    }
    if(didWinAll){
        player.levelUp();
        printWinBattle(player.getName(),GANG_CARD);
    }
}

Gang::Gang(const Gang &oldGang) : m_battleCards() {
    for (const unique_ptr<Battle> &currentCard : oldGang.m_battleCards) {
        unique_ptr<Battle> card(currentCard->clone());
        m_battleCards.push_back(std::move(card));
    }
}

Gang& Gang::operator=(const Gang &oldGang) {
    m_battleCards.clear();
    for (const unique_ptr<Battle> &currentCard : oldGang.m_battleCards) {
        unique_ptr<Battle> card(currentCard->clone());
        m_battleCards.push_back(std::move(card));
    }
    return *this;
}
