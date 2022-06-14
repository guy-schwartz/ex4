//
// Created by Guy Schwartz on 09/06/2022.
//

#include "Cards/Pitfall.h"
#include "Players/Rogue.h"
#include "Players/Fighter.h"
#include "Cards/Barfight.h"
#include "Cards/Treasure.h"
#include "Players/Wizard.h"
#include "Cards/Merchant.h"
#include "Cards/Vampire.h"
#include "Cards/Dragon.h"
#include "Mtmchkin.h"


int main(){
    std::fstream file;
    std::string fileName="deck1.txt";
    file.open(fileName.c_str());
    if(!file.is_open())
        std::cout<<"problem"<<std::endl;
    std::string word;
    while(std::getline(file,word)){
        std::cout<<word<<std::endl;
    }
    return 0;
}