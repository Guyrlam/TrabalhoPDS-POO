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

std::uniform_int_distribution<> seedDice(1, 6);


// Construtor SoccerMatch: Quando instanciado inicia o placar 0 x 0 e define que sera o time a inciar os turno, lembrando o time A sempre comeca
SoccerMatch::SoccerMatch(SoccerTeam *leftSideTeam, SoccerTeam *rightSideTeam) 
	: teamAScore(0), teamBScore(0), round(1){
	
	this->teamA = leftSideTeam;
	this->teamB = rightSideTeam;
	/*if (dis(gen) % 2 == 0) {

		this->teamA = leftSideTeam;
		this->teamB = rightSideTeam;
	}
	else {
		this->teamA = rightSideTeam; 
		this->teamB = leftSideTeam;
	}*/
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

	std::string teamAName = this->teamA->getName();
	std::string teamBName = this->teamB->getName();

	std::cout << "Round " << round << std::endl;

	if(round % 2 != 0){

		std::cout << "O time " << teamAName << " esta atacando" << std::endl;
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
			if(this->attemptGoal(restAttack, this->teamB->getGoalKepper(), teamAName, teamBName)){
				this->updateScore(this->teamA);
				this->teamA->updateResistanceTeam();
				this->teamB->updateResistanceTeam();
			}
		}else if(round > 1){
			std::cout << "Time " << teamAName << " perdeu a bola" << std::endl;
			this->teamA->updateResistanceTeam(PLAYERS_PER_TEAM, 0.2);
		}else
			std::cout << "Time " << teamAName << " comecou perdendo a bola" << std::endl;
		
	}else{

		std::cout << "O time " << teamBName << " esta atacando" << std::endl;
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
		if(attackVictory >= 2 && this->attemptGoal(restAttack, this->teamA->getGoalKepper(), teamBName, teamAName)){
			this->updateScore(this->teamB);
			this->teamA->updateResistanceTeam();
			this->teamB->updateResistanceTeam();
		}else if(round > 1){
			std::cout << "Time " << teamBName << " perdeu a bola" << std::endl;
			this->teamB->updateResistanceTeam(PLAYERS_PER_TEAM, 0.2);
		}else
			std::cout << "Time " << teamBName << " comecou perdendo a bola" << std::endl;

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

bool SoccerMatch::attemptGoal(int attackValue, GoalKeeper* keeper, const std::string& teamAttack, const std::string& teamDefense) {

	std::cout << "- O time: " << teamAttack << " esta atacando o gol " << " de " << keeper->getName() << " do time " << teamDefense << std::endl; 

    int defenseGoalKeeper = keeper->getDefense() + keeper->getFlexibility();

	int dice1;
	int dice2;

	if(attackValue > defenseGoalKeeper){
		dice1 = seedDice(gen);
		dice2 = seedDice(gen);
		return ((dice1 > 4) || (dice2 > 4)) ? true: false;
	}else{
		dice1 = seedDice(gen); 

		return dice1 > 4 ? true: false;
	}

	//std::cout << defenseGoalKeeper << std::endl;
    //return attackValue > defenseGoalKeeper;
}

//Metodo para atualizar o placar

void SoccerMatch::updateScore(SoccerTeam* scoringTeam) {
    if (scoringTeam == teamA) {
        teamAScore++;
    } else {
        teamBScore++;
    }
    std::cout << "Placar atualizado:\n" << this->teamA->getName() << "-" << teamAScore << "X" << teamBScore << " - " << this->teamB->getName() << std::endl;
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
void SoccerMatch::printArray(SoccerTeam* teamA) {
    std::array<SoccerPlayer*, TOTAL_PLAYERS> playersTeamA = this->teamA->getSoccerPlayers();
	std::array<SoccerPlayer*, PLAYERS_PER_TEAM> positions;
	
	
	for(int i = 0; i < TOTAL_PLAYERS; i++) {
        std::cout << i + 1 << ": " << playersTeam[i]->getName() << std::endl;
    }
    
}



	
void swapElements(SoccerTeam* teamA, int index1, int index2) {
    std::array<SoccerPlayer*, TOTAL_PLAYERS> playersTeamA = this->teamA->getSoccerPlayers();
	std::array<SoccerPlayer*, PLAYERS_PER_TEAM> positions;

	
	int temp = PlayersTeamA[index1];
    PlayersTeamA[index1] = PlayersTeamA[index2];
    PlayersTeamA[index2] = temp;



*/




#pragma endregion
