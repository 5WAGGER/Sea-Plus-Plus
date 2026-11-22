
#include "Creature.h"
#include <cstdlib>
#include <string>

namespace cs_creature {

    Creature::Creature() {
        strength = DEFAULT_STRENGTH;
        hitpoints = DEFAULT_HITPOINTS;
    }

    Creature::Creature(int newStrength, int newHitpoints) {
        strength = newStrength;
        hitpoints = newHitpoints;
    }

    int Creature::getStrength() const {
        return strength;
    }

    int Creature::getHitpoints() const {
        return hitpoints;
    }

    void Creature::setStrength(int newStrength) {
        strength = newStrength;
    }

    void Creature::setHitpoints(int newHitpoints) {
        hitpoints = newHitpoints;
    }

    std::string Creature::getSpecies() const {
        return "Creature";
    }

    int Creature::getDamage() const {
        return (std::rand() % strength) + 1;
    }

}
