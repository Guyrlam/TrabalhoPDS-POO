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

std::string SoccerTeam::getName() const {
    return this->name;
}

void SoccerTeam::setName(const std::string& newName) {
    this->name = newName;
}

void SoccerTeam::showSoccerPlayerInformations() {

    std::cout << "Informacoes do time:" << std::endl;
    for (size_t i = 0; i < this->numPlayers; ++i) {
        this->soccerPlayers[i]->informations(); // Chama o método para imprimir informações sobre o objeto B
    }
}

SoccerTeam::~SoccerTeam() {

}