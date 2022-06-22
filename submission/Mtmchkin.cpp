//
// Created by Guy Schwartz on 09/06/2022.
//

#include "Mtmchkin.h"
using std::string;
using std::fstream;
using std::getline;
using std::unique_ptr;
using std::deque;

Mtmchkin::Mtmchkin(const string &fileName) : m_cardQueue(), m_activePlayers(),m_winners(), m_losers(), m_numOfRounds(0), m_currentCard(0) {
    printStartGameMessage();
    initializeCards(fileName);
    int numPlayers = getTeamSize();
    for(int i=0 ; i<numPlayers ; i++){
        initializePlayer();
    }
}


void Mtmchkin::initializeCards(const string &fileName) {
    fstream file;
    file.open(fileName, std::ios::in);

    if(!file.is_open())
        throw DeckFileNotFound();

    string lineContent;
    int cardCounter=0;
    int lineCounter=1;
    while(getline(file,lineContent)){
        unique_ptr<Card> card = getCardType(lineContent,file,lineCounter);
        m_cardQueue.push_back(std::move(card));
        cardCounter++;
        lineCounter++;

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
            if (teamSize < MIN_PLAYERS || teamSize > MAX_PLAYERS || number.size()!=1) {
                printInvalidTeamSize();
                printEnterTeamSizeMessage();
                continue;
            }
        }
        catch(...){
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
            continue;
        }
        break;
    } while(true);
    return teamSize;
}


unique_ptr<Card> Mtmchkin::getCardType(const std::string &input, fstream &file, int &countLines){
    if(input==BARFIGHT_CARD){
        unique_ptr<Card> pCard(new Barfight());
        return pCard;
    }
    else if(input==DRAGON_CARD){
        unique_ptr<Card> pCard(new Dragon());
        return pCard;
    }
    else if (input==FAIRY_CARD){
        unique_ptr<Card> pCard(new Fairy());
        return pCard;
    }
    else if (input==GOBLIN_CARD){
        unique_ptr<Card> pCard(new Goblin());
        return pCard;
    }
    else if (input==MERCHANT_CARD){
        unique_ptr<Card> pCard(new Merchant());
        return pCard;
    }
    else if (input==PITFALL_CARD){
        unique_ptr<Card> pCard(new Pitfall());
        return pCard;
    }
    else if (input==TREASURE_CARD){
        unique_ptr<Card> pCard(new Treasure());
        return pCard;
    }
    else if (input==VAMPIRE_CARD){
        unique_ptr<Card> pCard(new Vampire());
        return pCard;
    }
    else if (input==GANG_CARD){
        unique_ptr<Card> pCard(new Gang(file,countLines));
        return pCard;
    }
    else{
        throw DeckFileFormatError(countLines);
    }
}


bool Mtmchkin::isNameValid(const string &playerName) {
    int size=playerName.size();
    if(size>MAX_NAME){
        return false;
    }
    for(char letter: playerName) {
        if(letter<MIN_UPPERCASE||letter>MAX_LOWERCASE||(letter>MAX_UPPERCASE&&letter<MIN_LOWERCASE)){
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
    int groupSize = m_activePlayers.size();
    for(int i=0 ; i<groupSize ; ++i){
        printTurnStartMessage(m_activePlayers.front()->getName());
        m_cardQueue[m_currentCard]->applyEncounter(*m_activePlayers.front());
        if(m_activePlayers.front()->isKnockedOut()){
            m_losers.push_front(std::move(m_activePlayers.front()));
            m_activePlayers.pop_front();
        }
        else if(m_activePlayers.front()->getLevel()==WINNER_LEVEL){
            m_winners.push_back(std::move(m_activePlayers.front()));
            m_activePlayers.pop_front();
        }
        else{
            m_activePlayers.push_back(std::move(m_activePlayers.front()));
            m_activePlayers.pop_front();
        }
        iterateOnCards();
        if(isGameOver()){
            printGameEndMessage();
            break;
        }
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