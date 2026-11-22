#include "Cyberdemon.h"
#include <iostream>
#include <string>

namespace cs_creature {

    Cyberdemon::Cyberdemon() {
    }

    Cyberdemon::Cyberdemon(int newStrength, int newHitpoints)
        : Demon(newStrength, newHitpoints) {
    }

    std::string Cyberdemon::getSpecies() const {
        return "cyberdemon";
    }

    int Cyberdemon::getDamage() const {
        std::cout << "The cyberdemon";
        return Demon::getDamage();
    }

}
