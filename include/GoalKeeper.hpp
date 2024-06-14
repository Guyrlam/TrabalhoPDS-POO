#ifndef GOAL_KEEPER_HPP
#define GOAL_KEEPER_HPP

#include "SoccerPlayerAttributes.hpp"
#include <iostream>
#include <string>

class GoalKeeper : public SoccerPlayerAttributes {

    private:
        int flexibility;
        int defense;

    public:
        
        GoalKeeper();
        ~GoalKeeper(); 

        int getFlexibility() const;
        void setFlexibility(int value);

        int getDefense() const;
        void setDefense(int value);

        void informations() const override;      

      

};

#endif //!GOAL_KEEPER_HPP
