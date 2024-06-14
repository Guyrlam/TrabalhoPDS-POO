#include "../include/SoccerPlayerAttributes.hpp"

std::string SoccerPlayerAttributes::getName() const {
    return this->name;
}

void SoccerPlayerAttributes::setName(const std::string& newName) {
    this->name = newName;
}

int SoccerPlayerAttributes::getAgility() const {
    return this->agility;
}

void SoccerPlayerAttributes::setAgility(int value) {
    this->agility = value;
}

int SoccerPlayerAttributes::getStrength() const {
    return this->strength;
}

void SoccerPlayerAttributes::setStrength(int value) {
    this->strength = value;
}

int SoccerPlayerAttributes::getResistance() const {
    return this->resistance;
}

void SoccerPlayerAttributes::setResistance(int value) {
    this->resistance = value;
}
