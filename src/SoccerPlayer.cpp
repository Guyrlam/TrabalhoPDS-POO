// #include <iostream>
// #include <string>
// #include "../include/SoccerPlayer.hpp"

// SoccerPlayer::SoccerPlayer() : resistance(0), qi(0) {}
	
// SoccerPlayer::~SoccerPlayer() {}

// std::string SoccerPlayer::getName() const {
// 	return this->name;
// }

// void SoccerPlayer::setName(const std::string& newName) {
// 	this->name = newName;
// }

// int SoccerPlayer::getResistance() const {
// 	return resistance;
// }

// void SoccerPlayer::setResistance(int value) {
// 	resistance = value;
// }

// int SoccerPlayer::getQi() const {
//     return qi;
// }

// void SoccerPlayer::setQi(int value) {
//     qi = value;
// }



// void SoccerPlayer::informations() const {

// 	std::string info = "Nome: " + this->getName() + " | " + "Resistencia: " + std::to_string(this->getResistance()) + 
// 	" | Qi: " + std::to_string(this->getQi());
// 	" | Velocidade: " + std::to_string(this->getSpeed()) +
//  " | Chute: " + std::to_string(this->getShooting()) +
//  " | Passe: " + std::to_string(this->getPassing()) +
//  " | Drible: " + std::to_string(this->getDribbling());

// 	std::cout << info << std::endl;
// }

#include <iostream>
#include <string>
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

	std::string info = "Nome: " + this->getName() + " | " + "Ataque: " + std::to_string(this->getAttack()) + " | " + "Defesa: " + std::to_string(this->getDefense());

	std::cout << info << std::endl;
}
