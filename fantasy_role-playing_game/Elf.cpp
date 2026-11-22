#include "Elf.h"
#include <cstdlib>
#include <iostream>
#include <string>

namespace cs_creature {

    Elf::Elf() {
    }

    Elf::Elf(int newStrength, int newHitpoints)
        : Creature(newStrength, newHitpoints) {
    }

    std::string Elf::getSpecies() const {
        return "elf";
    }

    int Elf::getDamage() const {
        int damage = Creature::getDamage();

        std::cout << "The elf attacks for " << damage
                  << " points!" << std::endl;

        if (std::rand() % 100 * 0.01 < MAGICAL_ATTACK_PROBABILITY) {
            std::cout << "Magical attack inflicts " << damage
                      << " additional damage points!" << std::endl;

            damage *= MAGICAL_ATTACK_MULTIPLIER;
        }

        return damage;
    }

}
