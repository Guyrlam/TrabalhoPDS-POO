#include <iostream>
#include <string>
#include "../include/SoccerPlayer.hpp"
#include "../include/SoccerPlayerAttributes.hpp"

SoccerPlayer::SoccerPlayer() {}
	
SoccerPlayer::~SoccerPlayer() {}

int SoccerPlayer::getDribbling() const {
	return this->dribbling;
}

void SoccerPlayer::setDribbling(int value){
	this->dribbling = value;
}

int SoccerPlayer::getShooting() const {
	return this->shooting;
}

void SoccerPlayer::setShooting(int value){
	this->shooting = value;
}


int SoccerPlayer::getShirtNumber() const {
	return this->shirtNumber;
}

void SoccerPlayer::setShirtNumber(int value){
	this->shirtNumber = value;
}

int SoccerPlayer::getPassing() const {
	return this->passing;
}

void SoccerPlayer::setPassing(int value){
	this->passing = value;
}

// Todo: Podera ser adicionado aleatoriedade para o jogador. Ex.: Torcidada xingou o jogador

// Agilidade
// Chute 3
// Força 
// Dible 2
// Passe 2

/*
Força:70
Agilidade:95
Resistencia:35
Chute:95
Drible:50
Drible:90

Ataque = (Agilidade + 3*Chute + Força + 2*Drible + 2*Drible)
Defesa = (5*Agilidade + 4*Força)
*/

int SoccerPlayer::getAttack() const
{
    int attack = (
			
				(this->getAgility()) + 
				(3*this->getShooting()) + 
				(this->getStrength()) + 
				(2*this->getDribbling()) + 
				(2*this->getPassing())

				) *this->getResistance();

	return attack;
}

// força 5
// agility 4
// resistencia 

int SoccerPlayer::getDefense() const{
	// To do: Discutir como melhorar a formula de defesa

	int defense = ((5*this->getAgility()) + (4*this->getStrength()))*this->getResistance();
	
	return defense;
}

#pragma region  Implementacao dos metodos abstratos

std::string SoccerPlayer::getName() const {
	return this->name;
}

void SoccerPlayer::setName(const std::string& newName) {
	this->name = newName;
}

float SoccerPlayer::getResistance() const {
	return resistance;
}

void SoccerPlayer::setResistance(float value) {
	resistance = value;
}

int SoccerPlayer::getAgility() const {
	return agility;
}

void SoccerPlayer::setAgility(int value) {
	agility = value;
}

int SoccerPlayer::getStrength() const {
	return strength;
}

void SoccerPlayer::setStrength(int value) {
	strength = value;
}

void SoccerPlayer::informations() const {

	std::string info = "Nome: " + this->getName() + " | " + "Resistencia: " + std::to_string(this->getResistance()) + 
	" | Agilidade: " + std::to_string(this->getAgility()) +
	" | Chute: " + std::to_string(this->getShooting()) +
	" | Passe: " + std::to_string(this->getPassing()) +
	" | Drible: " + std::to_string(this->getDribbling());
	std::cout << info << std::endl;
}

#pragma endregion
