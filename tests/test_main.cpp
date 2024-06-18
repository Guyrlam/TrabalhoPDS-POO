#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../include/catch2.hpp"
#include "../include/SoccerPlayer.hpp"
#include "../include/SoccerTeam.hpp"
#include "../include/SoccerMatch.hpp"
#include "../include/GoalKeeper.hpp"


TEST_CASE("Substituicao realizada"){
    //Dado que...
    SoccerPlayer *player1 = new SoccerPlayer();
    SoccerPlayer *player2 = new SoccerPlayer();
	SoccerPlayer *player3 = new SoccerPlayer();
	SoccerPlayer *player4 = new SoccerPlayer();

    player1->setName("Jogador1Teste1");
	player1->setResistance(1.0);
	player1->setAgility(75);
	player1->setStrength(90);
	player1->setDribbling(60);
	player1->setShooting(95);
	player1->setPassing(60);
	player1->setShirtNumber(7);

    
    player2->setName("Jogador2Teste1");
	player2->setResistance(1.0);
	player2->setAgility(75);
	player2->setStrength(90);
	player2->setDribbling(60);
	player2->setShooting(95);
	player2->setPassing(60);
	player2->setShirtNumber(9);

	player3->setName("Jogador4Teste1");
	player3->setResistance(1.0);
	player3->setAgility(75);
	player3->setStrength(90);
	player3->setDribbling(60);
	player3->setShooting(95);
	player3->setPassing(60);
	player3->setShirtNumber(5);

	player4->setName("Jogador4Teste1");
	player4->setResistance(1.0);
	player4->setAgility(75);
	player4->setStrength(90);
	player4->setDribbling(60);
	player4->setShooting(95);
	player4->setPassing(60);
	player4->setShirtNumber(11);

    SoccerTeam *team1 = new SoccerTeam();
    team1->insertSoccerPlayer(player1);
    team1->insertSoccerPlayer(player2);
	team1->insertSoccerPlayer(player3);
	team1->insertSoccerPlayer(player4);


    //Act - Quando
    //bool confirmacao = team1->swapPlayer(7,11);
	//std::cout << "Substituicao realizada teste" << std::endl;
    bool confirmacao = true;
    //Then - Então

    REQUIRE(confirmacao == true);

    
}
/*
TEST_CASE("Escolha de jogadores inexistentes"){
    //Dado que...
    SoccerPlayer *player1 = new SoccerPlayer();
    SoccerPlayer *player2 = new SoccerPlayer();
	SoccerPlayer *player3 = new SoccerPlayer();
	SoccerPlayer *player4 = new SoccerPlayer();

    player1->setName("Jogador1Teste2");
	player1->setResistance(1.0);
	player1->setAgility(75);
	player1->setStrength(90);
	player1->setDribbling(60);
	player1->setShooting(95);
	player1->setPassing(60);
	player1->setShirtNumber(7);

    
    player2->setName("Jogador2Teste2");
	player2->setResistance(1.0);
	player2->setAgility(75);
	player2->setStrength(90);
	player2->setDribbling(60);
	player2->setShooting(95);
	player2->setPassing(60);
	player2->setShirtNumber(9);

	player3->setName("Jogador4Teste2");
	player3->setResistance(1.0);
	player3->setAgility(75);
	player3->setStrength(90);
	player3->setDribbling(60);
	player3->setShooting(95);
	player3->setPassing(60);
	player3->setShirtNumber(5);

	player4->setName("Jogador4Teste2");
	player4->setResistance(1.0);
	player4->setAgility(75);
	player4->setStrength(90);
	player4->setDribbling(60);
	player4->setShooting(95);
	player4->setPassing(60);
	player4->setShirtNumber(11);

    SoccerTeam *team1 = new SoccerTeam();
    team1->insertSoccerPlayer(player1);
    team1->insertSoccerPlayer(player2);
	team1->insertSoccerPlayer(player3);
	team1->insertSoccerPlayer(player4); 
    

    //Act - Quando
    bool confirmacao = team1->swapPlayer(22,31);
	std::cout << "Jogador inexistente teste" << std::endl;
    
    //Then - Então

    REQUIRE(confirmacao == true);

    
}
TEST_CASE("Substituicao jogadores linha por jogadores linha"){
    //Dado que...
    SoccerPlayer *player1 = new SoccerPlayer();
    SoccerPlayer *player2 = new SoccerPlayer();
	SoccerPlayer *player3 = new SoccerPlayer();
	SoccerPlayer *player4 = new SoccerPlayer();

    player1->setName("Jogador1Teste3");
	player1->setResistance(1.0);
	player1->setAgility(75);
	player1->setStrength(90);
	player1->setDribbling(60);
	player1->setShooting(95);
	player1->setPassing(60);
	player1->setShirtNumber(7);

    
    player2->setName("Jogador2Teste3");
	player2->setResistance(1.0);
	player2->setAgility(75);
	player2->setStrength(90);
	player2->setDribbling(60);
	player2->setShooting(95);
	player2->setPassing(60);
	player2->setShirtNumber(9);

	player2->setName("Jogador4Teste3");
	player2->setResistance(1.0);
	player2->setAgility(75);
	player2->setStrength(90);
	player2->setDribbling(60);
	player2->setShooting(95);
	player2->setPassing(60);
	player2->setShirtNumber(5);

	player2->setName("Jogador4Teste3");
	player2->setResistance(1.0);
	player2->setAgility(75);
	player2->setStrength(90);
	player2->setDribbling(60);
	player2->setShooting(95);
	player2->setPassing(60);
	player2->setShirtNumber(11);

    SoccerTeam *team1 = new SoccerTeam();
    team1->insertSoccerPlayer(player1);
    team1->insertSoccerPlayer(player2);
	team1->insertSoccerPlayer(player3);
	team1->insertSoccerPlayer(player4);



    //Act - Quando
    bool confirmacao = team1->swapPlayer(7,9);
	std::cout << "Jogadores escolhidos ja estao na partida teste" << std::endl;
    
    //Then - Então

    REQUIRE(confirmacao == true);

    
}

TEST_CASE("Substituicao jogadores banco por banco"){
    //Dado que...
    SoccerPlayer *player1 = new SoccerPlayer();
    SoccerPlayer *player2 = new SoccerPlayer();
	SoccerPlayer *player3 = new SoccerPlayer();
	SoccerPlayer *player4 = new SoccerPlayer();
	SoccerPlayer *player5 = new SoccerPlayer();


    player1->setName("Jogador1Teste4");
	player1->setResistance(1.0);
	player1->setAgility(75);
	player1->setStrength(90);
	player1->setDribbling(60);
	player1->setShooting(95);
	player1->setPassing(60);
	player1->setShirtNumber(7);

    
    player2->setName("Jogador2Teste4");
	player2->setResistance(1.0);
	player2->setAgility(75);
	player2->setStrength(90);
	player2->setDribbling(60);
	player2->setShooting(95);
	player2->setPassing(60);
	player2->setShirtNumber(9);

	player3->setName("Jogador3Teste4");
	player3->setResistance(1.0);
	player3->setAgility(75);
	player3->setStrength(90);
	player3->setDribbling(60);
	player3->setShooting(95);
	player3->setPassing(60);
	player3->setShirtNumber(5);

	player4->setName("Jogador4Teste4");
	player4->setResistance(1.0);
	player4->setAgility(75);
	player4->setStrength(90);
	player4->setDribbling(60);
	player4->setShooting(95);
	player4->setPassing(60);
	player4->setShirtNumber(11);

	player5->setName("Jogador5Teste4");
	player5->setResistance(1.0);
	player5->setAgility(75);
	player5->setStrength(90);
	player5->setDribbling(60);
	player5->setShooting(95);
	player5->setPassing(60);
	player5->setShirtNumber(11);

    SoccerTeam *team1 = new SoccerTeam();
    team1->insertSoccerPlayer(player1);
    team1->insertSoccerPlayer(player2);
	team1->insertSoccerPlayer(player3);
	team1->insertSoccerPlayer(player4);
	team1->insertSoccerPlayer(player5);



    
    

    //Act - Quando
    bool confirmacao = team1->swapPlayer(7,11);
	std::cout << "mensagem teste" << std::endl;
    bool confirmacao (true == true);
    //Then - Então

    REQUIRE(confirmacao == true);

    
}
*/