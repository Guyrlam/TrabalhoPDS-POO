#include "../include/SoccerTeam.hpp"
#include "../include/SoccerPlayer.hpp"

SoccerTeam::SoccerTeam() : numPlayers(0) {

}

void SoccerTeam::insertSoccerPlayer(SoccerPlayer* player) {
    
    if (this->numPlayers < TOTAL_PLAYERS) {
        this->soccerPlayers[this->numPlayers++] = player;
    }
    else {
        // Lidar com o caso de tentativa de adicionar mais objetos do que o permitido
    }
}

void SoccerTeam::insertGoalKeeper(GoalKeeper* gk) {
    this->goalkeeper = gk;
}

GoalKeeper *SoccerTeam::getGoalKepper() const{
    this->goalkeeper;
}

std::string SoccerTeam::getName() const {
    return this->name;
}

void SoccerTeam::setName(const std::string& newName) {
    this->name = newName;
}

void SoccerTeam::showSoccerPlayerInformations() {

    std::cout << "Informacoes do time:" << std::endl;
    for (size_t i = 0; i < this->numPlayers; ++i) {
        this->soccerPlayers[i]->informations(); // Chama o m�todo para imprimir informa��es sobre o objeto
    }
}

std::array<SoccerPlayer*, TOTAL_PLAYERS> SoccerTeam::getSoccerPlayers() const{

    return this->soccerPlayers;
}



SoccerTeam::~SoccerTeam() {

}