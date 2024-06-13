#ifndef GOAL_KEEPER_HPP
#define GOAL_KEEPER_HPP
#include "SoccerPlayerAttributes.hpp"

class GoalKeeper : public SoccerPlayerAttributes {

    private:
        std::string name;
        int flexibility;
        int strength;

    public:
        
        std::string getName() const;
        void setName(const std::string& newName);

        int getFlexibility() const;
        virtual void setFlexibility(int value);

        int getStrength() const;
        virtual void setStrength(int value);

        void informations() const;      

        GoalKeeper();
        ~GoalKeeper();       

};

#endif //!GOAL_KEEPER_HPP
