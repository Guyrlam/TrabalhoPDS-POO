#include <iostream>
#include <string>
#include "../include/SoccerPlayer.hpp"
#include "../include/SoccerPlayerAttributes.hpp"

SoccerPlayer::SoccerPlayer() {}
	
SoccerPlayer::~SoccerPlayer() {}

int SoccerPlayer::getDribbling() const {
	return this->dribbling;
	return this->priority;
}

void SoccerPlayer::setDribbling(int value){
	this->dribbling = value;
	this->priority = 2;
}

int SoccerPlayer::getShooting() const {
	return this->shooting;
	return this->priority;
}

void SoccerPlayer::setShooting(int value){
	this->shooting = value;
	this->priority = 1;
}

int SoccerPlayer::getPassing() const {
	return this->passing;
	return this->priority;
}

void SoccerPlayer::setPassing(int value){
	this->passing = value;
	this->priority = 2;
}

// Todo: Podera ser adicionado aleatoriedade para o jogador. Ex.: Torcidada xingou o jogador

// Agilidade
// Chute 3
// Força 
// Dible 2
// Passe 2

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

int SoccerPlayer::getResistance() const {
	return resistance;
	return this->priority;
}

void SoccerPlayer::setResistance(int value) {
	resistance = value;
	this->priority = 3;
}

int SoccerPlayer::getAgility() const {
	return agility;
	return this->priority;
}

void SoccerPlayer::setAgility(int value) {
	agility = value;
	this->priority = 2;
}

int SoccerPlayer::getStrength() const {
	return strength;
	return this->priority;
}

void SoccerPlayer::setStrength(int value) {
	strength = value;
	this->priority = 3;
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
