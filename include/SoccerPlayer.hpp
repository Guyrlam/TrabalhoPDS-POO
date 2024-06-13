/*
int speed; // velocidade do jogador
	int shooting; // chute do jogador
	int passing; // Avalia a precis�o e a t�cnica de passe do jogador.
	int dribbling; // habilidade do jogador em manter o controle da bola
*/

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