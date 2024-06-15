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

int SoccerPlayer::getPassing() const {
	return this->passing;
}

void SoccerPlayer::setPassing(int value){
	this->passing = value;
}

// Todo: Podera ser adicionado aleatoriedade para o jogador. Ex.: Torcidada xingou o jogador

int SoccerPlayer::getAttack() const{
	// To do: Discutir como melhorar a formula do ataque
	int attack = this->getAgility() + this->getPassing() + this->getShooting() + this->getDribbling() + this->getStrength() + this->getResistance();
	
	return attack;
}

int SoccerPlayer::getDefense() const{
	// To do: Discutir como melhorar a formula de defesa

	int defense = this->getAgility() + this->getStrength() + this->getResistance();
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
}

void SoccerPlayer::setResistance(int value) {
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
