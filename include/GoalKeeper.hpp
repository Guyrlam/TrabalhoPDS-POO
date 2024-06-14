#ifndef GOAL_KEEPER_HPP
#define GOAL_KEEPER_HPP
#include "SoccerPlayerAttributes.hpp"

class GoalKeeper : public SoccerPlayerAttributes {

    private:
        int flexibility;
        int defense;

    public:
        
        int getFlexibility() const;
        void setFlexibility(int value);

        int getStrength() const;
        void setStrength(int value);

        void informations() const;      

        GoalKeeper();
        ~GoalKeeper();       

};

#endif //!GOAL_KEEPER_HPP
