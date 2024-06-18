
#ifndef SOCCER_TEAM_HPP
#define SOCCER_TEAM_HPP

#include <iostream>
#include <array>
#include "SoccerPlayer.hpp"
#include "GoalKeeper.hpp"
#define TOTAL_PLAYERS 6
//#define PLAYERS_RESERVE_TEAM 3

class SoccerTeam {

private:
	std::string name;
	std::array<SoccerPlayer*, TOTAL_PLAYERS> soccerPlayers;
	//std::array<SoccerPlayer*, PLAYERS_RESERVE_TEAM> ReservePlayers;
	GoalKeeper* goalkeeper;
	size_t numPlayers;

public:
	SoccerTeam();
	
	std::string getName() const;
	void setName(const std::string& newName);
	void insertSoccerPlayer(SoccerPlayer* soccerPlayer);
	void insertGoalKeeper(GoalKeeper* goalkeeper);
	GoalKeeper *getGoalKepper() const;

	void showSoccerPlayerInformations();

	std::array<SoccerPlayer*, TOTAL_PLAYERS> getSoccerPlayers() const;
	void setSoccerPlayers(std::array<SoccerPlayer*, TOTAL_PLAYERS> _soccerPlayers);
	void updateResistanceTeam();
	void updateResistanceTeam(int PLAYERS_PER_TEAM, float decreaseResistance);
	int getShirtPlayerPosition(SoccerTeam *team, int position);
	void swapPlayer(int in, int out);

	~SoccerTeam();
};

#endif // !SOCCER_TEAM_HPP