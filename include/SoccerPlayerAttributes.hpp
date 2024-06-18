#ifndef SOCCER_PLAYER_ATTIBUTES
#define SOCCER_PLAYER_ATTIBUTES

// Classe Abstrata
// get e set pra todos os atributos,

#include <string>

class SoccerPlayerAttributes
{
protected:
    int agility;
    int strength;
    float resistance;
    std::string name;

public:

    virtual std::string getName() const = 0;
    virtual void setName(const std::string& newName) = 0;

    virtual int getAgility() const = 0;
    virtual void setAgility(int value) = 0;

    virtual int getStrength() const = 0;
    virtual void setStrength(int value) = 0;

    virtual float getResistance() const = 0;
    virtual void setResistance(float value) = 0;

    virtual void informations() const = 0;
};



#endif