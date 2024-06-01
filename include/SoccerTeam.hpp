
#ifndef SOCCER_TEAM
#define SOCCER_TEAM

#include <iostream>
#include <array>
#include "SoccerPlayer.hpp"
#define TOTAL_PLAYERS 7

class SoccerTeam {

private:
	std::string name;
	std::array<SoccerPlayer*, TOTAL_PLAYERS> soccerPlayers;
	size_t numPlayers;
public:
	SoccerTeam();
	
	std::string getName() const;
	void setName(const std::string& newName);
	void insertSoccerPlayer(SoccerPlayer* soccerPlayer);
	void showSoccerPlayerInformations();

	~SoccerTeam();
};

#endif