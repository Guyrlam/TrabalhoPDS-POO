/*#ifndef ITEMS_HPP
#define ITEMS_HPP


#include <iostream>
#include <string>
#include "SoccerPlayerAttributes.hpp"


class Items : public SoccerPlayerAttributes {

    private:
        int powerup;
        int powerlow;

    public:
        
        Items();
        ~Items(); 

        std::string getName() const override;
    	void setName(const std::string& newName) override;
        
        

        void informations() const override;      

        

};







#endif //!ITEMS_HPP
*/