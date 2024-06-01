#include <iostream>
#include "../include/SoccerPlayer.hpp"

SoccerPlayer::SoccerPlayer() : isGoalkeeper(false) {
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

void SoccerPlayer::changeToGoalkeeper(){
	this->isGoalkeeper = true;
}

void SoccerPlayer::informations() const {

	std::string info = "Nome: " + this->getName() + " | " + "Ataque: " + this->getAttack() + " | " + "Defesa: " + this->getDefense();

	std::cout << info << std::endl;
}
