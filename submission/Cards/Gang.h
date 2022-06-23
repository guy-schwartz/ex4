//
// Created by Guy Schwartz on 19/06/2022.
//

#ifndef EX4_GANG_H
#define EX4_GANG_H

#include "Vampire.h"
#include "Dragon.h"
#include "Goblin.h"
#include <vector>
#include <memory>
#include <iostream>

const std::string GANG_CARD = "Gang";

class Gang : public Card {
public:
    const std::string END_READ = "EndGang";

    /**
     * constructor of Gang object
     * @param file - input text file
     * @param countLines - continue to count lines
     */
    Gang(std::fstream &file, int &countLines);

    /**
     * copy constructor
     * @param oldGang
     */
    Gang(const Gang &oldGang);

    /**
     * destructor
     */
    ~Gang() override = default;

    /**
     * clone function for Gang card
     * @return
     */
     Gang* clone() const override;

     Gang& operator=(Gang const &oldGang);

    /**
     * Handles player encounter with the card
     *
     * @param player - The player.
     * @return
     *      void
    **/
    void applyEncounter(Player& player) const override;

private:
    /**
     * adds cards to the gang.
     * if card doesn't exist, an exception will be thrown
     * @param cardName
     */
    void addToGang(std::string &cardName);


    std::vector<std::unique_ptr<Battle>> m_battleCards;
};

#endif //EX4_GANG_H
