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
	//GoalKeeper* player4 = new Goalkeeper(); 
	//o goloreiro vai ser considerado um player 4?
	

	SoccerPlayer* player5 = new SoccerPlayer();
	SoccerPlayer* player6 = new SoccerPlayer();
	SoccerPlayer* player7 = new SoccerPlayer();
	SoccerPlayer* player8 = new SoccerPlayer();
	//GoalKeeper* player8 = new GoalKeeper();

	SoccerTeam* team1 = new SoccerTeam();
	SoccerTeam* team2 = new SoccerTeam();

	GoalKeeper *goalKepper = new GoalKeeper();

	/*player1->setName("Vini Jr");
	player1->setResistence(40);
	player1->setAgility(50); 
	player1->setStrenght(20); 
	player1->setDribbling(60); 
	player1->setShooting(60); 
	player1->setPassing(30); 

	player2->setName("Rodrygo");
	player2->setResistence(70);
	player2->setAgility(50); 
	player2->setStrenght(30); 
	player2->setDribbling(20); 
	player2->setShooting(50); 
	player2->setPassing(30); 
	
	player3->setName("Marcelo");
	player3->setResistence(40);
	player3->setAgility(50); 
	player3->setStrenght(40); 
	player3->setDribbling(40); 
	player3->setShooting(50); 
	player3->setPassing(70); 

	player4->setName("Victor");
	player4->setResistence(50);
	player4->setAgility(70); 
	player4->setStrenght(10); 
	player4->setFlexibility(20); 
	player4->setDefense(60); 
	 


	player5->setName("Kroos");
	player5->setResistence(20);
	player5->setAgility(50); 
	player5->setStrenght(40); 
	player5->setDribbling(70); 
	player5->setShooting(10); 
	player5->setPassing(30); 

	player6->setName("Modric");
	player6->setResistence(50);
	player6->setAgility(30); 
	player6->setStrenght(20); 
	player6->setDribbling(40); 
	player6->setShooting(30); 
	player6->setPassing(70); 

	player7->setName("Cristiano");
	player7->setResistence(40);
	player7->setAgility(20); 
	player7->setStrenght(50); 
	player7->setDribbling(40); 
	player7->setShooting(70); 
	player7->setPassing(20); 

	player4->setName("Fabio");
	player4->setResistence(50);
	player4->setAgility(40); 
	player4->setStrenght(30); 
	player4->setFlexibility(20); 
	player4->setDefense(50); 

	team1->insertSoccerPlayer(player1);
	team1->insertSoccerPlayer(player2);
	team1->insertSoccerPlayer(player3);
	team1->insertGoalKeeper(player4);

	team2->insertSoccerPlayer(player5);
	team2->insertSoccerPlayer(player6);
	team2->insertSoccerPlayer(player7);
	team2->insertGoalKeeper(player8);

	team1->showSoccerPlayerInformations();
	team2->showSoccerPlayerInformations();

	SoccerMatch soccerMatch = SoccerMatch(team1, team2);

	soccerMatch.showTeams();*/
	return 0;
} 