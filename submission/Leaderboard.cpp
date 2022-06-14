//
// Created by Guy Schwartz on 12/06/2022.
//

#include "Leaderboard.h"

void Leaderboard::printWinners() const {
    for(int i=0; i<m_winners.size(); i++){
        printPlayerLeaderBoard(i,*(m_winners[i]));
    }
}