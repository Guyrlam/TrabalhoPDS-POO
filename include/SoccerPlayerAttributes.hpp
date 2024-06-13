#ifndef SOCCER_PLAYER_ATTIBUTES
#define SOCCER_PLAYER_ATTIBUTES

// Classe Abstrata
// get e set pra todos os atributos,

#include <string>

class SoccerPlayerAttributes
{
protected:
    int speed;
    int shooting;
    int passing;
    int dribbling;

public:
    SoccerPlayerAttributes();
    virtual ~SoccerPlayerAttributes() = 0;

    virtual std::string getName() const = 0;
    virtual void setName(const std::string& newName) = 0;

    int getSpeed() const;
    virtual void setSpeed(int value);

    int getShooting() const;
    virtual void setShooting(int value);

    int getPassing() const;
    virtual void setPassing(int value);

    int getDribbling() const;
    virtual void setDribbling(int value);

    virtual void informations() const = 0;

};



#endif