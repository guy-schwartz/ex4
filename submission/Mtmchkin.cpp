//
// Created by Guy Schwartz on 09/06/2022.
//

#include "Mtmchkin.h"
using std::string;
using std::fstream;
using std::getline;
using std::unique_ptr;
using std::deque;

Mtmchkin::Mtmchkin(const string fileName) : m_cardQueue(), m_activePlayers(),m_winners(), m_losers(), m_numOfRounds(0), m_currentCard(0) {
    printStartGameMessage();
    initializeCards(fileName);
    int numPlayers = getTeamSize();
    for(int i=0 ; i<numPlayers ; i++){
        initializePlayer();
    }
}


void Mtmchkin::initializeCards(const string fileName) {
    fstream file;
    file.open(fileName, std::ios::in);

    if(!file.is_open())
        throw DeckFileNotFound();

    string lineContent;
    int cardCounter=0;

    while(getline(file,lineContent)){
        unique_ptr<Card> card = getCardType(lineContent);
        if(card==nullptr){
            throw DeckFileFormatError(++cardCounter);
        }
        else{
            m_cardQueue.push_back(std::move(card));
            cardCounter++;
        }
    }
    if(cardCounter<MIN_CARDS){
        throw DeckFileInvalidSize();
    }
}



void Mtmchkin::initializePlayer() {
    printInsertPlayerMessage();
    string playerName;
    string job;
    while(true) {
        try {
            getline(std::cin, playerName, SPACE);
            getline(std::cin, job);
            if (!isNameValid(playerName)) {
                printInvalidName();
                continue;
            }
            if (createPlayer(playerName, job)) {
                break;
            }
        }
        catch(...){
            continue;
        }
    }
}

int Mtmchkin::getTeamSize(){
    printEnterTeamSizeMessage();
    int teamSize;
    string number;
    do{
        try {
            getline(std::cin, number);
            teamSize = std::stoi(number);
            if (teamSize >= MIN_PLAYERS && teamSize <= MAX_PLAYERS) {
                break;
            }
            printInvalidTeamSize();
        }
        catch(...){
            printInvalidTeamSize();
            continue;
        }
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


bool Mtmchkin::createPlayer(const string &playerName, const string &job) {
    if(job=="Fighter"){
        unique_ptr<Player> pPlayer(new Fighter(playerName));
        m_activePlayers.push_back(std::move(pPlayer));
        return true;
    }
    else if(job=="Rogue"){
        unique_ptr<Player> pPlayer(new Rogue(playerName));
        m_activePlayers.push_back(std::move(pPlayer));
        return true;
    }
    else if(job=="Wizard"){
        unique_ptr<Player> pPlayer(new Wizard(playerName));
        m_activePlayers.push_back(std::move(pPlayer));
        return true;
    }
    else{
        printInvalidClass();
        return false;
    }
}

int Mtmchkin::getNumberOfRounds() const {
    return m_numOfRounds;
}

void Mtmchkin::playRound() {
    m_numOfRounds++;
    printRoundStartMessage(m_numOfRounds);
    for(unique_ptr<Player> &currentPlayer : m_activePlayers){
        printTurnStartMessage(currentPlayer->getName());
        m_cardQueue[m_currentCard]->applyEncounter(*currentPlayer);
        if(currentPlayer->isKnockedOut()){
            m_losers.push_front(std::move(currentPlayer));
        }
        else if(currentPlayer->getLevel()==WINNER_LEVEL){
            m_winners.push_back(std::move(currentPlayer));
        }
        cleanDeque();
        iterateOnCards();
        if(isGameOver()){
            printGameEndMessage();
            break;
        }
    }
}


void Mtmchkin::cleanDeque() {
    deque<unique_ptr<Player>>::iterator it1 = m_activePlayers.begin();
    for(unique_ptr<Player> &currentPlayer : m_activePlayers){
        if(currentPlayer == nullptr){
            m_activePlayers.erase(it1);
        }
        ++it1;
    }
}


void Mtmchkin::iterateOnCards() {
    m_currentCard = (m_currentCard+1)%m_cardQueue.size();
}


bool Mtmchkin::isGameOver() const {
    if(m_activePlayers.empty()){
        return true;
    }
    else{
        return false;
    }
}

void Mtmchkin::printLeaderBoard() const {
    printLeaderBoardStartMessage();
    int ranking = 1;
    for(const unique_ptr<Player> &player: m_winners){
        printPlayerLeaderBoard(ranking,*player);
        ranking++;
    }
    for(const unique_ptr<Player> &player : m_activePlayers){
        printPlayerLeaderBoard(ranking,*player);
        ranking++;
    }
    for(const unique_ptr<Player> &player : m_losers){
        printPlayerLeaderBoard(ranking,*player);
        ranking++;
    }
}