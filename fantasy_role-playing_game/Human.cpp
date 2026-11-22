#include "Human.h"
#include <iostream>
#include <string>

namespace cs_creature {

    Human::Human() {
    }

    Human::Human(int newStrength, int newHitpoints)
        : Creature(newStrength, newHitpoints) {
    }

    std::string Human::getSpecies() const {
        return "human";
    }

    int Human::getDamage() const {
        int damage = Creature::getDamage();

        std::cout << "The human attacks for " << damage
                  << " points!" << std::endl;

        return damage;
    }

}
