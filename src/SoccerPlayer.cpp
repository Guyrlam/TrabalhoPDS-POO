#include <iostream>
#include "../include/SoccerPlayer.hpp"

SoccerPlayer::SoccerPlayer() {
	this->attack = 0;
	this->defense = 0;
}

SoccerPlayer::~SoccerPlayer() {

}

std::string SoccerPlayer::getName() const {
	return this->name;
}

void SoccerPlayer::setName(const std::string& newName) {
	this->name = newName;
}

int SoccerPlayer::getAttack() const{
	return this->attack;
}

void SoccerPlayer::setAttack(int value) {
	this->attack = value;
}

int SoccerPlayer::getDefense() const{
	return this->defense;
}

void SoccerPlayer::setDefense(int value) {
	this->defense = value;
}

void SoccerPlayer::informations() {

	std::cout << this->getName() << " tem " << this->getAttack() << " e " << this->getDefense() << " de defesa" << std::endl;
}
