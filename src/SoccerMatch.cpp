#include <iostream>
#include <fstream>
#include <string>
#include "../include/SoccerMatch.hpp"

// Criando um gerador de n�meros aleat�rios
std::random_device rd;
std::mt19937 gen(rd()); // Mersenne Twister 19937 gerador de n�meros aleat�rios

// Definindo a distribui��o dos n�meros aleat�rios (de 1 a 100)
std::uniform_int_distribution<> dis(1, 100);

// Construtor SoccerMatch: Quando instanciado inicia o placar 0 x 0 e define que ser� o time a inciar os turno, lembrando o time A sempre come�a
SoccerMatch::SoccerMatch(SoccerTeam &leftSideTeam, SoccerTeam &rightSideTeam) 
	: teamAScore(0), teamBScore(0), round(1){

	if (dis(gen) % 2 == 0) {

		this->teamA = leftSideTeam;
		this->teamB = rightSideTeam;
	}
	else {
		this->teamA = rightSideTeam;
		this->teamB = leftSideTeam;
	}
}

void SoccerMatch::showTeams() {

	

}

/*
void SoccerMatch::nextRound() {

	int attack = 0;
	int defese = 0;
	int leftOver = 0;

	if (this->round % 2 != 0) {
			
		for (int i = 0; i < PLAYERS_PER_TEAM, i++) {
			
		}

	}

}*/

SoccerMatch::~SoccerMatch(){

}

