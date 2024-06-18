#include <iostream>
#include <string>
#include "../include/GoalKeeper.hpp"
#include "../include/SoccerPlayerAttributes.hpp"

GoalKeeper::GoalKeeper () {}

GoalKeeper::~GoalKeeper() {}

int GoalKeeper::getFlexibility() const{
	return this->flexibility;
}

void GoalKeeper::setFlexibility(int value) {
	this->flexibility = value;
}

int GoalKeeper::getDefense() const{
	return this->defense;
}

void GoalKeeper::setDefense(int value) {
	this->defense = value;
}

#pragma region  Implementacao dos metodos abstratos

std::string GoalKeeper::getName() const {
	return this->name;
}

void GoalKeeper::setName(const std::string& newName) {
	this->name = newName;
}

float GoalKeeper::getResistance() const {
	return this->resistance;
}

void GoalKeeper::setResistance(float value) {
	this->resistance = value;
}

int GoalKeeper::getAgility() const {
	return this->agility;
}

void GoalKeeper::setAgility(int value) {
	this->agility = value;
}

int GoalKeeper::getStrength() const {
	return this->strength;
}

void GoalKeeper::setStrength(int value) {
	this->strength = value;
}

void GoalKeeper::informations() const {

	std::string info = "Nome: " + this->getName() + " | " + "Resistencia: " + std::to_string(this->getResistance()) + 
	" | Agilidade: " + std::to_string(this->getAgility()) +
	" | Flexibilidade: " + std::to_string(this->getFlexibility()) +
	" | Defesa: " + std::to_string(this->getDefense());
	std::cout << info << std::endl;
}

#pragma endregion

