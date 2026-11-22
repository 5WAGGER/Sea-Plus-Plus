
#include "Demon.h"
#include <cstdlib>
#include <iostream>
#include <string>

namespace cs_creature {

    Demon::Demon() {
    }

    Demon::Demon(int newStrength, int newHitpoints)
        : Creature(newStrength, newHitpoints) {
    }

    std::string Demon::getSpecies() const {
        return "demon";
    }

    int Demon::getDamage() const {
        int damage = Creature::getDamage();

        std::cout << " attacks for " << damage
                  << " points!" << std::endl;

        if (std::rand() % 100 * 0.01 < DEMONIC_ATTACK_PROBABILITY) {
            damage += DEMONIC_BONUS_DAMAGE;

            std::cout << "Demonic attack inflicts "
                      << DEMONIC_BONUS_DAMAGE
                      << " additional damage points!" << std::endl;
        }

        return damage;
    }

}
