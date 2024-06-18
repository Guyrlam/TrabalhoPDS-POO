#include "../include/SoccerTeam.hpp"
#include "../include/SoccerPlayer.hpp"
#include "../include/GoalKeeper.hpp"

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

GoalKeeper* SoccerTeam::getGoalKepper() const{
    return this->goalkeeper;
}

std::string SoccerTeam::getName() const {
    return this->name;
}

void SoccerTeam::setName(const std::string& newName) {
    this->name = newName;
}

void SoccerTeam::showSoccerPlayerInformations() {
    std::cout << "Informacoes do time:" << std::endl;

    // Exibir informacoes dos jogadores de linha
    for (size_t i = 0; i < this->numPlayers; ++i) {
        this->soccerPlayers[i]->informations();
    }

    // Exibir informacoes do goleiro, se houver
    if (this->goalkeeper != nullptr) {
        this->goalkeeper->informations();
    }
}

std::array<SoccerPlayer*, TOTAL_PLAYERS> SoccerTeam::getSoccerPlayers() const {
    return this->soccerPlayers;
}


void SoccerTeam::updateResistanceTeam(int PLAYERS_PER_TEAM, float decreaseResistance){

	for(int i =0; i< PLAYERS_PER_TEAM; i++){
		SoccerPlayer *player = this->getSoccerPlayers()[i];
		float resistance = player->getResistance();
		player->setResistance(resistance - decreaseResistance);
	}
}

void SoccerTeam::updateResistanceTeam(){

	for(int i =0; i< TOTAL_PLAYERS; i++){
		SoccerPlayer *player = this->getSoccerPlayers()[i];
		player->setResistance(1.0);
	}
}




/* Criar um array para jogadores do banco

std::array<SoccerPlayer*, PLAYERS_RESERVE_TEAM> SoccerTeam::getSoccerPlayers() const {
    return this->ReservePlayers;

*/

/* Funcao para estanciar jogadores do banco

void SoccerTeam::insertReservePlayer(SoccerPlayer* player) {
    
    if (this->numPlayers < PLAYERS_RESERVE_TEAM) {
        this->ReservePlayers[this->numPlayers++] = player;
    }
    else {
        // Lidar com o caso de tentativa de adicionar mais objetos do que o permitido
    }
}



*/
SoccerTeam::~SoccerTeam() {

}