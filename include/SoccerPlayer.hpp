/*
int speed; // velocidade do jogador
	int shooting; // chute do jogador
	int passing; // Avalia a precis�o e a t�cnica de passe do jogador.
	int dribbling; // habilidade do jogador em manter o controle da bola
*/

#ifndef SOCCER_PLAYER
#define SOCCER_PLAYER

#include <iostream>

class SoccerPlayer {

private:
	std::string name;
	int attack;
	int defense;

public:
	SoccerPlayer();
	~SoccerPlayer();
	
	std::string getName() const;
	void setName(const std::string& newName);

	int getAttack() const;
	void setAttack(int value);
	int getDefense() const;
	void setDefense(int value);
	void informations();

};

#endif