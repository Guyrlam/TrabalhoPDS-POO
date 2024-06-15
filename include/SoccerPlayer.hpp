#ifndef SOCCER_PLAYER_HPP
#define SOCCER_PLAYER_HPP

#include <iostream>
#include <string>
#include "SoccerPlayerAttributes.hpp"

class SoccerPlayer : public SoccerPlayerAttributes {

	private:
		int dribbling;
		int shooting;
		int passing;

	public:
 		SoccerPlayer();
		~SoccerPlayer();

		std::string getName() const override;
    	void setName(const std::string& newName) override;

		int getDribbling() const;
    	void setDribbling(int value);

		int getPassing() const;
    	void setPassing(int value);

		int getShooting() const;
    	void setShooting(int value);

		int getAttack() const;
		int getDefense() const;

		int getAgility() const override;
    	void setAgility(int value) override;

    	int getStrength() const override;
    	void setStrength(int value) override;

    	int getResistance() const override;
    	void setResistance(int value) override;
	
		void informations() const override;
 };

#endif //!SOCCER_PLAYER_HPP

/*
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
*/