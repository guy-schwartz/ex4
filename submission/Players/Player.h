//
// Created by Guy Schwartz on 09/06/2022.
//

#ifndef EX4_PLAYER_H
#define EX4_PLAYER_H
#include <string>
#include <iostream>




class Player{
public:
    static const int MAX_HP = 100;
    static const int MIN_LEVEL = 1;
    static const int MAX_LEVEL = 10;
    static const int DEFAULT_COINS = 10;
    static const int DEFAULT_FORCE = 5;

    /**
     * c'tor of Player class
     * @param name
     */
    explicit Player(const std::string& name);
    virtual ~Player()=default;

    virtual Player* clone() const = 0;

    /**
     * upgrades player's level by 1, up to a maximum of 10
     * for 10 or above, method does nothing
     */
    void levelUp();

    /**
     * returns player's level
     */
    int getLevel() const;

    /**
     * upgrades the player's force by a certain input given to the member function
     * in case of an undefined argument (forceUpgrade<0), force member will remain unchanged
     * @param forceUpgrade - an integer
     */
    void buff(int forceUpgrade);

    /**
     * updates the health points up to a maximum defined by maxHP
     * @param newPoints - and integer
     */
    virtual void heal(int newPoints);

    /**
     * reduces health points by a given value, down to a minimum of 0
     * @param reduceBy - an integer
     */
    void damage(int reduceBy);

    /**
     * returns true if health points are down to their minimum
     * otherwise returns false
     */
    bool isKnockedOut() const;

    /**
     * member function adds coins by a given value
     * in case of an undefined argument, coins member will remain unchanged
     * @param coinsToAdd - an integer
     */
    virtual void addCoins(int coinsToAdd);

    /**
     * reduces number of coins by a given value
     * @param coinsToPay - an integer
     * @return
     * member function returns true if reduction is successful.
     * otherwise, function does nothing (thus, number of coins shall not be reduced)
     * and returns false
     * true will be returned for undefined arguments as well
     */
    bool pay(int coinsToPay);

    /**
     * calculates a value which is defined by force+level and returns it in default
     */
    virtual int getAttackStrength() const;

    /**
     * printing method for operator<<, to be defined in inheriting classes
     * @param out
     */
    virtual void print(std::ostream& out) const = 0;

    /**
     * operator<<, prints the following template: <name> <level> <Force> <Hp> <Coins> <Class>
     * @param out
     */
    friend std::ostream& operator<<(std::ostream& out, const Player& player);

    /**
     * returns the name of the player
     * @return
     */
    std::string getName();

    /**
     * returns the number of coins the player currently holds
     * @return
     */
    int showCoins() const;

    /**
     * returns the current HP status of a player
     * @return
     */
    int showHP() const;

    /**
     * downgrade force by one
     */
    void hitForce(int hitBy);



protected:
    std::string m_name;
    int m_level;
    int m_force;
    int m_HP;
    int m_coins;

};

#endif //EX4_PLAYER_H
