//
// Created by Guy Schwartz on 09/06/2022.
//
#include "Player.h"

Player::Player(const std::string& name) : m_name(name), m_level(MIN_LEVEL), m_coins(DEFAULT_COINS), m_force(DEFAULT_FORCE), m_HP(MAX_HP){}

void Player::levelUp(){
    if(m_level>=MAX_LEVEL){
        return;
    }
    m_level++;
}

int Player::getLevel() const{
    return m_level;
}

void Player::buff(int forceUpgrade){
    if(forceUpgrade<0){
        return;
    }
    m_force+=forceUpgrade;
}

void Player::heal(int newPoints){
    if(newPoints<0){
        return;
    }
    int tempHP=m_HP+newPoints;
    if(tempHP>MAX_HP){
        tempHP=MAX_HP;
    }
    m_HP=tempHP;
}

void Player::damage(int reduceBy){
    if(reduceBy<0){
        return;
    }
    int tempHP=m_HP-reduceBy;
    if(tempHP<0){
        tempHP=0;
    }
    m_HP=tempHP;
}

bool Player::isKnockedOut() const{
    if(!m_HP){
        return true;
    }
    else{
        return false;
    }
}

void Player::addCoins(int coinsToAdd){
    if(coinsToAdd<0){
        return;
    }
    m_coins+=coinsToAdd;
}

bool Player::pay(int coinsToPay){
    if(coinsToPay<0){
        return true;
    }
    int tempCoins=m_coins-coinsToPay;
    if(tempCoins<0){
        return false;
    }
    m_coins=tempCoins;
    return true;
}

int Player::getAttackStrength() const{
    int attackStrength = m_force+m_level;
    return attackStrength;
}

std::ostream& operator<<(std::ostream& out, const Player& player)
{
    player.print(out);
    return out;
}

std::string Player::getName() {
    return m_name;
}

int Player::showCoins() const {
    return m_coins;
}

int Player::showHP() const{
    return m_HP;
}

void Player::hitForce(const int hitBy){
    int tempForce=m_force-hitBy;
    if(tempForce<0){
        m_force=0;
    }
    else{
        m_force=tempForce;
    }
}