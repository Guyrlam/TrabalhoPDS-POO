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
    int resistance;
    std::string name;

public:

    std::string getName() const;
    void setName(const std::string& newName);

    int getAgility() const;
    void setAgility(int value);

    int getStrength() const;
    void setStrength(int value);

    int getResistance() const;
    void setResistance(int value);

    virtual void informations() const;
};



#endif