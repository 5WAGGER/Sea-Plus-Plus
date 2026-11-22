#include "Balrog.h"
#include <cstdlib>
#include <iostream>
#include <string>

namespace cs_creature {

    Balrog::Balrog() {
    }

    Balrog::Balrog(int newStrength, int newHitpoints)
        : Demon(newStrength, newHitpoints) {
    }

    std::string Balrog::getSpecies() const {
        return "balrog";
    }

    int Balrog::getDamage() const {
        std::cout << "The balrog";

        int damage = Demon::getDamage();
        int damage2 = (std::rand() % getStrength()) + 1;

        std::cout << "Balrog speed attack inflicts " << damage2
                  << " additional damage points!" << std::endl;

        return damage + damage2;
    }

}
