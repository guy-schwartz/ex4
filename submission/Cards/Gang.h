//
// Created by Guy Schwartz on 19/06/2022.
//

#ifndef EX4_GANG_H
#define EX4_GANG_H

#include "Card.h"
#include <vector>


class Gang : public Card {
public:
    const std::string GANG_CARD = "Gang";
    /**
     * constructor of Gang object
     * @param file - input text file
     * @param countLines - continue to count lines
     */
    Gang(std::fstream &file, int &countLines);

    /**
     * destructor
     */
    ~Gang() override = default;





private:

    std::vector<std::unique_ptr<Card>> m_gangCards;
};

#endif //EX4_GANG_H
