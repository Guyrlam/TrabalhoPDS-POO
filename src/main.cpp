#include <iostream>
#include "../include/SoccerPlayer.hpp"
#include "../include/SoccerTeam.hpp"
#include "../include/SoccerMatch.hpp"
#include "../include/GoalKeeper.hpp"

int main() {

	SoccerPlayer *player1 = new SoccerPlayer();
	SoccerPlayer *player2 = new SoccerPlayer();
	SoccerPlayer* player3 = new SoccerPlayer();
	SoccerPlayer* player4 = new SoccerPlayer();

	SoccerPlayer* player5 = new SoccerPlayer();
	SoccerPlayer* player6 = new SoccerPlayer();
	SoccerPlayer* player7 = new SoccerPlayer();
	SoccerPlayer* player8 = new SoccerPlayer();

	SoccerTeam* team1 = new SoccerTeam();
	SoccerTeam* team2 = new SoccerTeam();

	GoalKeeper *goalKepper = new GoalKeeper();

	/*player1->setName("Vini Jr");
	player1->setAttack(90);
	player1->setDefense(30); 

	player2->setName("Rodrigo");
	player2->setAttack(82);
	player2->setDefense(40);
	
	player3->setName("Marcelo");
	player3->setAttack(82);
	player3->setDefense(40);

	player4->setName("Militao");
	player4->setAttack(82);
	player4->setDefense(40);


	player5->setName("Kroos");
	player5->setAttack(90);
	player5->setDefense(30);

	player6->setName("Modric");
	player6->setAttack(82);
	player6->setDefense(40);

	player7->setName("Rodrigo");
	player7->setAttack(82);
	player7->setDefense(40);

	player8->setName("Coutois");
	player8->setAttack(82);
	player8->setDefense(40);

	team1->insertSoccerPlayer(player1);
	team1->insertSoccerPlayer(player2);
	team1->insertSoccerPlayer(player3);
	team1->insertSoccerPlayer(player4);

	team2->insertSoccerPlayer(player5);
	team2->insertSoccerPlayer(player6);
	team2->insertSoccerPlayer(player7);
	team2->insertSoccerPlayer(player8);

	team1->showSoccerPlayerInformations();
	team2->showSoccerPlayerInformations();

	SoccerMatch soccerMatch = SoccerMatch(team1, team2);

	soccerMatch.showTeams();*/
	return 0;
} 