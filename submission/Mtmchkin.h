#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <iostream>
#include <fstream>
#include <deque>
#include <list>
#include <memory>
#include "Cards/Card.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Fairy.h"
#include "Cards/Goblin.h"
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Cards/Vampire.h"
#include "Players/Player.h"
#include "Players/Fighter.h"
#include "Players/Rogue.h"
#include "Players/Wizard.h"



class Mtmchkin{
public:
    static const int MIN_CARDS = 5;
    static const int MIN_PLAYERS=2;
    static const int MAX_PLAYERS=6;
    static const char SPACE = ' ';
    static const char MIN_LETTER = 'A';
    static const char MAX_LETTER = 'z';
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string fileName);

    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();

    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;

    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;

	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;


private:
    static const int WINNER_LEVEL = 10;

    /**
     * initializes the cards
     * @param fileName
     */
    void initializeCards(const std::string fileName);

    /**
     * initializes the players
     */
    void initializePlayer();

    /**
     * creates an instance of a player object
     * @param playerName
     * @param job
     * @return returns false if job string is invalid, and doesnt create anything
     */
    bool createPlayer(const std::string &playerName, const std::string &job);

    /**
     * returns the team size from the player
     * @return
     */
    static int getTeamSize();

    /**
     * target each string to its corresponding type of card
     * @param input
     * @return if type of card is not identified, nullptr will be returned
     */
    static std::unique_ptr<Card> getCardType(const std::string &input);

    /**
     * checks if the player name is valid
     */
    static bool isNameValid(const std::string &playerName);

    /**
     * deletes null elements from players deque
     */
    void cleanDeque();

    /**
     * makes an iteration on the deck of cards
     */
    void iterateOnCards();


    std::deque<std::unique_ptr<Card>> m_cardQueue;
    std::deque<std::unique_ptr<Player>> m_activePlayers;
    std::deque<std::unique_ptr<Player>> m_winners;
    std::deque<std::unique_ptr<Player>> m_losers;
    int m_numOfRounds;
    int m_currentCard;

};






#endif /* MTMCHKIN_H_ */
