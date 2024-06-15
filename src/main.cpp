#include <iostream>
#include "../include/SoccerPlayer.hpp"
#include "../include/SoccerTeam.hpp"
#include "../include/SoccerMatch.hpp"
#include "../include/GoalKeeper.hpp"

int main() {

	SoccerPlayer* player1 = new SoccerPlayer();
	SoccerPlayer* player2 = new SoccerPlayer();
	SoccerPlayer* player3 = new SoccerPlayer();
	GoalKeeper* goalKeeper1 = new GoalKeeper();

	SoccerPlayer* player4 = new SoccerPlayer();
	SoccerPlayer* player5 = new SoccerPlayer();
	SoccerPlayer* player6 = new SoccerPlayer();
	GoalKeeper* goalKeeper2 = new GoalKeeper();

	SoccerTeam* team1 = new SoccerTeam();
	SoccerTeam* team2 = new SoccerTeam();

	player1->setName("Vini Jr");
	player1->setResistance(40);
	player1->setAgility(50); 
	player1->setStrength(20); 
	player1->setDribbling(60); 
	player1->setShooting(60); 
	player1->setPassing(30); 

	player2->setName("Rodrygo");
	player2->setResistance(70);
	player2->setAgility(50); 
	player2->setStrength(30); 
	player2->setDribbling(20); 
	player2->setShooting(50); 
	player2->setPassing(30); 
	
	player3->setName("Marcelo");
	player3->setResistance(40);
	player3->setAgility(50); 
	player3->setStrength(40); 
	player3->setDribbling(40); 
	player3->setShooting(50); 
	player3->setPassing(70); 

	player4->setName("Kroos");
	player4->setResistance(20);
	player4->setAgility(40); 
	player4->setStrength(40); 
	player4->setDribbling(70); 
	player4->setShooting(10); 
	player4->setPassing(30); 

	player5->setName("Modric");
	player5->setResistance(50);
	player5->setAgility(30); 
	player5->setStrength(20); 
	player5->setDribbling(40); 
	player5->setShooting(30); 
	player5->setPassing(70); 

	player6->setName("Cristiano");
	player6->setResistance(40);
	player6->setAgility(20); 
	player6->setStrength(50); 
	player6->setDribbling(40); 
	player6->setShooting(70); 
	player6->setPassing(20); 

	goalKeeper1->setName("Fabio");
	goalKeeper1->setResistance(50);
	goalKeeper1->setAgility(80); 
	goalKeeper1->setStrength(30); 
	goalKeeper1->setFlexibility(20); 
	goalKeeper1->setDefense(80); 

	goalKeeper2->setName("Victor");
	goalKeeper2->setResistance(60);
	goalKeeper2->setAgility(50); 
	goalKeeper2->setStrength(30); 
	goalKeeper2->setFlexibility(20); 
	goalKeeper2->setDefense(100);

	team1->insertSoccerPlayer(player1);
	team1->insertSoccerPlayer(player2);
	team1->insertSoccerPlayer(player3);
	team1->insertGoalKeeper(goalKeeper1);

	team2->insertSoccerPlayer(player4);
	team2->insertSoccerPlayer(player5);
	team2->insertSoccerPlayer(player6);
	team2->insertGoalKeeper(goalKeeper2);

	team1->showSoccerPlayerInformations();
	team2->showSoccerPlayerInformations();

	SoccerMatch soccerMatch = SoccerMatch(team1, team2);

	//soccerMatch.showTeams();

	soccerMatch.playMatch();
	
	return 0;
} 