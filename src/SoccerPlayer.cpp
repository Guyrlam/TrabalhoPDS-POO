#include <iostream>
#include <string>
#include "../include/SoccerPlayer.hpp"
#include "../include/SoccerPlayerAttributes.hpp"

SoccerPlayer::SoccerPlayer() {}
	
SoccerPlayer::~SoccerPlayer() {}

std::string SoccerPlayer::SoccerPlayerAttributes::getName() const {
	return this->name;
}

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

#pragma region  Implementacao dos metodos abstratos



void SoccerPlayer::SoccerPlayerAttributes::setName(const std::string& newName) {
	this->name = newName;
}

int SoccerPlayer::SoccerPlayerAttributes::getResistance() const {
	return resistance;
}

void SoccerPlayer::SoccerPlayerAttributes::setResistance(int value) {
	resistance = value;
}

int SoccerPlayer::SoccerPlayerAttributes::getAgility() const {
	return agility;
}

void SoccerPlayer::SoccerPlayerAttributes::setAgility(int value) {
	agility = value;
}

int SoccerPlayer::SoccerPlayerAttributes::getStrength() const {
	return strength;
}

void SoccerPlayer::SoccerPlayerAttributes::setStrength(int value) {
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



/*
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
*/