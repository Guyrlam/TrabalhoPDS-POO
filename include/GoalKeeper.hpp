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

        std::string getName() const override;
    	void setName(const std::string& newName) override;
        
        int getFlexibility() const;
        void setFlexibility(int value);

        int getDefense() const;
        void setDefense(int value);

        int getAgility() const override;
        void setAgility(int value) override;

        int getStrength() const override;
        void setStrength(int value) override;

        int getResistance() const override;
        void setResistance(int value) override;

        void informations() const override;      

        

};

#endif //!GOAL_KEEPER_HPP
