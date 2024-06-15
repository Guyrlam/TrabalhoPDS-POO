#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include "../include/Paths.hpp"
#include "../include/Utils.hpp"
#include "../include/SoccerMatch.hpp"

// Criando um gerador de numeros aleatorios
std::random_device rd;
std::mt19937 gen(rd()); // Mersenne Twister 19937 gerador de numeros aleatorios

// Definindo a distribuicao dos numeros aleatorios (de 1 a 100)
std::uniform_int_distribution<> dis(1, 100);

// Construtor SoccerMatch: Quando instanciado inicia o placar 0 x 0 e define que sera o time a inciar os turno, lembrando o time A sempre comeca
SoccerMatch::SoccerMatch(SoccerTeam *leftSideTeam, SoccerTeam *rightSideTeam) 
	: teamAScore(0), teamBScore(0), round(1){

	if (dis(gen) % 2 == 0) {

		this->teamA = leftSideTeam;
		this->teamB = rightSideTeam;
	}
	else {
		this->teamA = rightSideTeam; 
		this->teamB = leftSideTeam;
	}
}

void SoccerMatch::showTeams() {

	std::string soccerField = Utils::readFile("..\\game_graphics\\soccerField.txt");

	// Verificando se o conteudo foi lido corretamente
	if (!soccerField.empty()) {
		// Exibindo o conteudo do arquivo
		std::cout << "Conteudo do arquivo:" << std::endl;
		std::cout << soccerField;
	}
	else {
		std::cerr << "Erro ao ler o arquivo." << std::endl;
	}

}

/* TENTATIVA DE FUNÇAÕ PARA ESCOLHERMOS OS JOGADORES:

void SoccerMatch::positionPlayers(SoccerTeam* team) {

	std::array<SoccerPlayer*, TOTAL_PLAYERS> playersTeam = this->team->getSoccerPlayers();
	std::array<SoccerPlayer*, PLAYERS_PER_TEAM> positions;

	std::cout << "Jogadores disponíveis:" << std::endl;
    for (int i = 0; i < TOTAL_PLAYERS; ++i) {
        std::cout << i + 1 << ": " << playersTeam[i]->getName() << std::endl;
    }

    // Escolher quais jogadores vão atacar quais jogadores do time adversário
    for (int i = 0; i < PLAYERS_PER_TEAM; ++i) {
        int choice;
        std::cout << "Escolha o jogador " << i + 1 << " que vai atacar: ";
        std::cin >> choice;
        while (choice < 1 || choice > TOTAL_PLAYERS) {
            std::cout << "Escolha inválida. Tente novamente: ";
            std::cin >> choice;
        }
        positions[i] = playersTeam[choice - 1];
    }

    // Exibir as escolhas para confirmação
    std::cout << "Posições dos jogadores escolhidos para atacar:" << std::endl;
    for (int i = 0; i < PLAYERS_PER_TEAM; ++i) {
        std::cout << "Jogador " << i + 1 << ": " << positions[i]->getName() << std::endl;
    }

    // Armazenar as posições dos jogadores na equipe
    this->team->setSoccerPositions(positions);
}
*/


// To do: Refatorar funcao
void SoccerMatch::nextRound(){
	
	std::array<SoccerPlayer*, TOTAL_PLAYERS> playersTeamA = this->teamA->getSoccerPlayers();
	std::array<SoccerPlayer*, TOTAL_PLAYERS> playersTeamB = this->teamB->getSoccerPlayers();

	int attackVictory = 0;
	int restAttack = 0;

	if(round % 2 != 0){

		// Realizando todos os confrontos
		for(int i = 0; i < PLAYERS_PER_TEAM; i++){
			// Se a funcao confronto retornar um valor positivo o ataque individual funcionou
			int returnConfrontation = playersConfrontation(playersTeamA[i], playersTeamB[i]);
			
			if(returnConfrontation > 0){
				restAttack += returnConfrontation;
				attackVictory++;
			}
		}

		// O empate eh da defesa, só podera realizar o chute ao gol se tiver duas ou mais vitorias no ataque
		if(attackVictory >= 2){

			if(this->attemptGoal(restAttack, this->teamB->getGoalKepper()))
				this->updateScore(this->teamA);
		}
	}else{

		// Realizando todos os confrontos
		for(int i = 0; i < PLAYERS_PER_TEAM; i++){
			// Se a funcao confronto retornar um valor positivo o ataque individual funcionou
			int returnConfrontation = playersConfrontation(playersTeamB[i], playersTeamA[i]);
			
			if(returnConfrontation > 0){
				restAttack += returnConfrontation;
				attackVictory++;
			}
		}

		// O empate eh da defesa, só podera realizar o chute ao gol se tiver duas ou mais vitorias no ataque
		if(attackVictory >= 2 && this->attemptGoal(restAttack, this->teamA->getGoalKepper())){
			this->updateScore(this->teamB);
		}

	}

	// Vai para o proximo round
	round++;
}

// Criar um método de confronto entre jogadores
int SoccerMatch::playersConfrontation(SoccerPlayer* attacker, SoccerPlayer* defender) {

    int attackValue = attacker->getAttack();
    int defenseValue = defender->getDefense();

	// Aqui podera ser adicionado aleatoriedade da partida. Ex.: Esta chovendo ou muito quente (afeta o coletivo). Discutir se sera adionado em eventos da partida
	int restAttack = attackValue - defenseValue;

    return restAttack;
}

// Metodo para chance de gol

bool SoccerMatch::attemptGoal(int attackValue, GoalKeeper* keeper) {
    int defenseGoalKeeper = keeper->getDefense() + keeper->getFlexibility();

    return attackValue > defenseGoalKeeper;
}

//Metodo para atualizar o placar

void SoccerMatch::updateScore(SoccerTeam* scoringTeam) {
    if (scoringTeam == teamA) {
        teamAScore++;
    } else {
        teamBScore++;
    }
    std::cout << "Placar atualizado: Team A " << teamAScore << " - " << teamBScore << " Team B" << std::endl;
}


void SoccerMatch::playMatch() {
    while (teamAScore < 3 && teamBScore < 3) {
		nextRound();
    }
}

SoccerMatch::~SoccerMatch(){

}

#pragma region  Implementacao substituição jogadores

/*Funcao para mostrar todos os jogadores do time
void SoccerMatch::printArray(int arr[], TOTAL_PLAYERS) {
    std::array<SoccerPlayer*, TOTAL_PLAYERS> playersTeamA = this->teamA->getSoccerPlayers();
	
	
	
	for(int i = 0; i < TOTAL_PLAYERS; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void swapElements(int arr[], int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;



*/




#pragma endregion
