#include "../include/SoccerPlayerAttributes.hpp"

SoccerPlayerAttributes::SoccerPlayerAttributes() : speed(0), shooting(0), passing(0), dribbling(0) {}

SoccerPlayerAttributes::~SoccerPlayerAttributes() {}

int SoccerPlayerAttributes::getSpeed() const {
    return speed;
}

void SoccerPlayerAttributes::setSpeed(int value) {
    speed = value;
}

int SoccerPlayerAttributes::getShooting() const {
    return shooting;
}

void SoccerPlayerAttributes::setShooting(int value) {
    shooting = value;
}

int SoccerPlayerAttributes::getPassing() const {
    return passing;
}

void SoccerPlayerAttributes::setPassing(int value) {
    passing = value;
}

int SoccerPlayerAttributes::getDribbling() const {
    return dribbling;
}

void SoccerPlayerAttributes::setDribbling(int value) {
    dribbling = value;
}
