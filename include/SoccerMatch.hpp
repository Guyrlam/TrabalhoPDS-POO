#ifndef SOCCER_MATCH_HPP
#define SOCCER_MATCH_HPP
#include <iostream>
#include "SoccerTeam.hpp"
#define PLAYERS_PER_TEAM 3


class SoccerMatch {

private:
	SoccerTeam *teamA; // Sera o time a inciar a partida
	SoccerTeam *teamB;
	int teamAScore;
	int teamBScore;
	int round;
	//void nextRound();
	void nextRound();
	int playersConfrontation(SoccerPlayer* attacker, SoccerPlayer* defender);
    void updateScore(SoccerTeam* scoringTeam);
    bool attemptGoal(int attackValue, GoalKeeper* keeper);

public:
	SoccerMatch(SoccerTeam* leftSideTeam, SoccerTeam* rightSideTeam);
	void showTeams();
	void playMatch();
	//void positionPlayers(SoccerTeam* team);
	~SoccerMatch();
	//void playerDuel(SoccerPlayer *playerA, SoccerPlayer *playerB);
	// to do: Fazer um método pra confronto e método reposicionar 

};



#endif // !SOCCER_MATCH_HPP
