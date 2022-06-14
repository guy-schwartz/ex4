//
// Created by Guy Schwartz on 09/06/2022.
//

#include "Mtmchkin.h"
using std::string;
using std::ifstream;
using std::getline;
using std::unique_ptr;

Mtmchkin::Mtmchkin(const string fileName) : m_activePlayers(), m_cardQueue() {
    initializeCards(fileName);
    initializePlayers();
}


void Mtmchkin::initializeCards(const string fileName) {
    ifstream file;
    file.open(fileName); //todo: exception if file does not open
    string lineContent;
    int cardCounter=0;
    while(getline(file,lineContent)){
        unique_ptr<Card> card = getCardType(lineContent);
        if(card==nullptr){
            throw; //todo: handle exceptions
        }
        else{
            m_cardQueue.push_back(std::move(card));
            cardCounter++;
        }
    }
    if(cardCounter<MIN_CARDS){
        throw; //todo: handle exceptions
    }
}


void Mtmchkin::initializePlayers() {
    int numPlayers = getTeamSize();
    printInsertPlayerMessage();
    string playerName;
    string temp;
    while(true){
        getline(std::cin, playerName, SPACE);
        getline(std::cin, temp);
        string job = temp.substr(1);
    }
}

int Mtmchkin::getTeamSize(){
    printEnterTeamSizeMessage();
    int teamSize;
    string number;
    do{
        getline(std::cin,number);
        teamSize = std::stoi(number);
        if(teamSize>=MIN_PLAYERS && teamSize<=MAX_PLAYERS){
            break;
        }
        printInvalidTeamSize();
    } while(true);

    return teamSize;
}


unique_ptr<Card> Mtmchkin::getCardType(const string &input){
    if(input=="Barfight"){
        unique_ptr<Card> pCard(new Barfight());
        return pCard;
    }
    else if(input=="Dragon"){
        unique_ptr<Card> pCard(new Dragon());
        return pCard;
    }
    else if (input=="Fairy"){
        unique_ptr<Card> pCard(new Fairy());
        return pCard;
    }
    else if (input=="Goblin"){
        unique_ptr<Card> pCard(new Goblin());
        return pCard;
    }
    else if (input=="Merchant"){
        unique_ptr<Card> pCard(new Merchant());
        return pCard;
    }
    else if (input=="Pitfall"){
        unique_ptr<Card> pCard(new Pitfall());
        return pCard;
    }
    else if (input=="Treasure"){
        unique_ptr<Card> pCard(new Treasure());
        return pCard;
    }
    else if (input=="Vampire"){
        unique_ptr<Card> pCard(new Vampire());
        return pCard;
    }
    else{
        return nullptr;
    }
}


bool Mtmchkin::isNameValid(const string &playerName) {
    int size=playerName.size();
    if(size>MAX_NAME){
        return false;
    }
    for(char letter: playerName) {
        if(letter<MIN_LETTER||letter>MAX_LETTER){
            return false;
        }
    }
    return true;
}