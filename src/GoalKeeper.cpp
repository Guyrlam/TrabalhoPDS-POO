#include <iostream>
#include <string>
#include "../include/GoalKeeper.hpp"



std::string GoalKeeper::getName() const {
	return this->name;
}

void GoalKeeper::setName(const std::string& newName) {
	this->name = newName;
}

int GoalKeeper::getFlexibility() const{
	return this->flexibility;
}

void GoalKeeper::setFlexibility(int value) {
	flexibility = value;
}

int GoalKeeper::getStrength() const{
	return this->strength;
}

void GoalKeeper::setStrength(int value) {
	strength = value;
}

void GoalKeeper::informations() const {

	std::string info = "Nome: " + this->getName() + " | " + "Flexibilidade: " + std::to_string(this->getFlexibility()) + 
	" | Força: " + std::to_string(this->getStrength());
	" | Velocidade: " + std::to_string(this->getSpeed()) +
    " | Chute: " + std::to_string(this->getShooting()) +
    " | Passe: " + std::to_string(this->getPassing()) +
    " | Drible: " + std::to_string(this->getDribbling());

	std::cout << info << std::endl;
}

GoalKeeper::~GoalKeeper() {

}