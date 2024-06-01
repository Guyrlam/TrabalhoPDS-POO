#ifndef SOCCER_MATCH_HPP
#define SOCCER_MATCH_HPP
#include <iostream>
#include "SoccerTeam.hpp"
#include PLAYERS_PER_TEAM 4

class SoccerMatch {

private:
	SoccerTeam teamA; // Será o time a inciar a partida
	SoccerTeam teamB;
	int teamAScore;
	int teamBScore;
	int round;
	//void nextRound();

public:
	SoccerMatch(SoccerTeam& leftSideTeam, SoccerTeam& rightSideTeam);
	void showTeams();
	~SoccerMatch();

};



#endif // !GAME_HPP
