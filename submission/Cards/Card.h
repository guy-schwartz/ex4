//
// Created by Guy Schwartz on 09/06/2022.
//

#ifndef EX4_CARD_H
#define EX4_CARD_H
#include <string>
#include <iostream>
#include "../Players/Player.h"
#include "../Players/Rogue.h"
#include "../Players/Fighter.h"
#include "../Players/Wizard.h"
#include "../utilities.h"


class Card{
public:
    /**
     * c'tor of Card class
     * @param name
     */
    explicit Card(const std::string& name);
    virtual ~Card()=default;

    /**
     * printing method for operator<<, to be defined in inheriting classes
     * @param out
     */
    virtual void print(std::ostream& out) const;

    /**
     * operator<<, prints the following template: <name> <level> <Force> <Hp> <Coins> <Class>
     * @param out
     */
    friend std::ostream& operator<<(std::ostream& out, const Card& card);

    /**
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const = 0;

protected:
    const std::string m_name;
};

#endif //EX4_CARD_H
