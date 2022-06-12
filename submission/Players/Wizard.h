//
// Created by Guy Schwartz on 09/06/2022.
//

#ifndef EX4_WIZARD_H
#define EX4_WIZARD_H

#include "Player.h"
#include "../utilities.h"

class Wizard : public Player {

public:
    /**
     * c'tor for Wizard
     * @param name
     */
    explicit Wizard(const std::string& name);

    /**
     * default d'tor for Wizard
     * @param name
     */
    ~Wizard() override=default;

    /**
      * updates the health points up to a maximum defined by maxHP by double the given number
      * @param newPoints - and integer
      */
      void heal(int newPoints) override;

    /**
     * suitable printing function
     * @param out
     */
    void print(std::ostream& out) const override;

};

#endif //EX4_WIZARD_H
