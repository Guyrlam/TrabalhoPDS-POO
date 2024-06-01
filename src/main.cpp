#include <iostream>
#include "../include/SoccerPlayer.hpp"
#include "../include/SoccerTeam.hpp"


int main() {

	SoccerPlayer *player1 = new SoccerPlayer();
	SoccerPlayer *player2 = new SoccerPlayer();

	SoccerTeam* team1 = new SoccerTeam();

	player1->setName("Vini Jr");
	player1->setAttack(90);
	player1->setDefense(30);

	player2->setName("Rodrigo");
	player2->setAttack(82);
	player2->setDefense(40);

	team1->insertSoccerPlayer(player1);
	team1->insertSoccerPlayer(player2);
	
	team1->showSoccerPlayerInformations();

	return 0;
}