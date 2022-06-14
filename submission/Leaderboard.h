//
// Created by Guy Schwartz on 12/06/2022.
//

#ifndef EX4_LEADERBOARD_H
#define EX4_LEADERBOARD_H

#include <deque>
#include "Players/Player.h"
#include "utilities.h"


class Leaderboard{
public:
    Leaderboard()=default;

    ~Leaderboard()=default;

    void printWinners() const;

    void printLosers() const;

    void addLoser(Player& loser) const;

    void addWinner(Player& winner) const;

private:
    std::deque<std::unique_ptr<Player>> m_winners;
    std::deque<std::unique_ptr<Player>> m_losers;
};
#endif //EX4_LEADERBOARD_H
