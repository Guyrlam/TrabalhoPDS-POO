// #ifndef SOCCER_PLAYER_HPP
// #define SOCCER_PLAYER_HPP

// #include <iostream>
// #include <string>
// #include "SoccerPlayerAttributes.hpp"

// class SoccerPlayer : public SoccerPlayerAttributes {

// private:
// 	std::string name;
// 	int resistance;
// 	int qi;

// public:
// 	SoccerPlayer();
// 	~SoccerPlayer();
	
// 	std::string getName() const override;
// 	void setName(const std::string& newName) override;

// 	int getResistance() const;
// 	virtual void setResistance(int value);
	
// 	int getQi() const;
// 	virtual void setQi(int value);

// 	void informations() const;

// };

// #endif //!SOCCER_PLAYER_HPP

#ifndef SOCCER_PLAYER_HPP
#define SOCCER_PLAYER_HPP

#include <iostream>

class SoccerPlayer {

private:
	std::string name;
	int attack;
	int defense;
	bool isGoalkeeper;

public:
	SoccerPlayer();
	~SoccerPlayer();
	
	std::string getName() const;
	void setName(const std::string& newName);

	int getAttack() const;
	void virtual setAttack(int value);
	
	int getDefense() const;
	void virtual setDefense(int value);
	
	void changeToGoalkeeper();
	void informations() const;

};

#endif //!SOCCER_PLAYER_HPP