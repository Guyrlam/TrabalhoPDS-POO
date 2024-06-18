#include <iostream>
#include "../include/SoccerPlayer.hpp"
#include "../include/SoccerTeam.hpp"
#include "../include/SoccerMatch.hpp"
#include "../include/GoalKeeper.hpp"
#include "../include/sdl2.hpp"


void buildGame(){
	SoccerPlayer* player1 = new SoccerPlayer();
	SoccerPlayer* player2 = new SoccerPlayer();
	SoccerPlayer* player3 = new SoccerPlayer();
	SoccerPlayer* player4 = new SoccerPlayer();
	SoccerPlayer* player5 = new SoccerPlayer();
	SoccerPlayer* player6 = new SoccerPlayer();
	GoalKeeper* goalKeeper1 = new GoalKeeper();

	SoccerPlayer* player7 = new SoccerPlayer();
	SoccerPlayer* player8 = new SoccerPlayer();
	SoccerPlayer* player9 = new SoccerPlayer();
	SoccerPlayer* player10 = new SoccerPlayer();
	SoccerPlayer* player11 = new SoccerPlayer();
	SoccerPlayer* player12 = new SoccerPlayer();
	GoalKeeper* goalKeeper2 = new GoalKeeper();

	SoccerTeam* team1 = new SoccerTeam();
	SoccerTeam* team2 = new SoccerTeam();
	//Time Atletico
	player1->setName("Hulk");
	player1->setResistance(1.0);
	player1->setAgility(75);
	player1->setStrength(90);
	player1->setDribbling(60);
	player1->setShooting(95);
	player1->setPassing(60);
	player1->setShirtNumber(7);

	player2->setName("Tardelli");
	player2->setResistance(1.0);
	player2->setAgility(45);
	player2->setStrength(40);
	player2->setDribbling(40);
	player2->setShooting(60);
	player2->setPassing(40);
	player2->setShirtNumber(9);

	player3->setName("Ronaldinho Gaucho");
	player3->setResistance(1.0);
	player3->setAgility(50);
	player3->setStrength(50);
	player3->setDribbling(90);
	player3->setShooting(95);
	player3->setPassing(90);
	player3->setShirtNumber(10);

	player4->setName("Rever");
	player4->setResistance(1.0);
	player4->setAgility(70);
	player4->setStrength(90);
	player4->setDribbling(30);
	player4->setShooting(30);
	player4->setPassing(45);
	player4->setShirtNumber(4);

	player5->setName("Luan");
	player5->setResistance(1.0);
	player5->setAgility(50);
	player5->setStrength(40);
	player5->setDribbling(55);
	player5->setShooting(60);
	player5->setPassing(80);
	player5->setShirtNumber(17);

	player6->setName("Donizete");
	player6->setResistance(1.0);
	player6->setAgility(40);
	player6->setStrength(50);
	player6->setDribbling(65);
	player6->setShooting(65);
	player6->setPassing(45);
	player6->setShirtNumber(8);

	goalKeeper1->setName("Vitor");
	goalKeeper1->setResistance(1.0);
	goalKeeper1->setAgility(30);
	goalKeeper1->setStrength(40);
	goalKeeper1->setFlexibility(90);
	goalKeeper1->setDefense(95);

	//Time Cruzeiro
	player7->setName("Ronaldo fenomeo");
	player7->setResistance(1.0);
	player7->setAgility(95);
	player7->setStrength(70);
	player7->setDribbling(90);
	player7->setShooting(95);
	player7->setPassing(50);
	player7->setShirtNumber(9);

	player8->setName("Tostao");
	player8->setResistance(1.0);
	player8->setAgility(60);
	player8->setStrength(35);
	player8->setDribbling(45);
	player8->setShooting(55);
	player8->setPassing(55);
	player8->setShirtNumber(7);

	player9->setName("Everton Ribeiro");
	player9->setResistance(1.0);
	player9->setAgility(60);
	player9->setStrength(50);
	player9->setDribbling(55);
	player9->setShooting(70);
	player9->setPassing(50);
	player9->setShirtNumber(17);

	player10->setName("Alex");
	player10->setResistance(1.0);
	player10->setAgility(40);
	player10->setStrength(70);
	player10->setDribbling(65);
	player10->setShooting(35);
	player10->setPassing(45);
	player10->setShirtNumber(10);

	player11->setName("Sorin");
	player11->setResistance(1.0);
	player11->setAgility(45);
	player11->setStrength(55);
	player11->setDribbling(60);
	player11->setShooting(60);
	player11->setPassing(75);
	player11->setShirtNumber(6);

	player12->setName("Marcelo Moreno");
	player12->setResistance(1.0);
	player12->setAgility(45);
	player12->setStrength(50);
	player12->setDribbling(55);
	player12->setShooting(70);
	player12->setPassing(50);
	player12->setShirtNumber(19);

	goalKeeper2->setName("Fabio");
	goalKeeper2->setResistance(1.0);
	goalKeeper2->setAgility(35);
	goalKeeper2->setStrength(45);
	goalKeeper2->setFlexibility(85);
	goalKeeper2->setDefense(90);

	team1->setName("Atletico");
	
	team1->insertSoccerPlayer(player1);
	team1->insertSoccerPlayer(player2);
	team1->insertSoccerPlayer(player3);
	team1->insertSoccerPlayer(player4);
	team1->insertSoccerPlayer(player5);
	team1->insertSoccerPlayer(player6);
	team1->insertGoalKeeper(goalKeeper1);

	team2->setName("Cruzeiro");
	team2->insertSoccerPlayer(player7);
	team2->insertSoccerPlayer(player8);
	team2->insertSoccerPlayer(player9);
	team2->insertSoccerPlayer(player10);
	team2->insertSoccerPlayer(player11);
	team2->insertSoccerPlayer(player12);
	team2->insertGoalKeeper(goalKeeper2);

	SoccerMatch soccerMatch = SoccerMatch(team1, team2);
	soccerMatch.playMatch();
}


int main(int argc, char* args[])
{

	buildGame();


	#pragma region Testes a serem executados

	// Um ou mais jogadores nao existem
	// team1->swapPlayer(50, 8); 
	// team1->swapPlayer(8, 50);
	// team1->swapPlayer(23, 1);
	// team1->swapPlayer(23, 23);
	
	// // troca de mesmo jogador
	// team2->swapPlayer(10, 10);

	// // troca de jogadores no banco

	// team2->swapPlayer(6, 19);
	// team2->swapPlayer(19, 6);

	#pragma endregion

	/*
	// Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		// Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			// Main loop flag
			bool quit = false;

			// Event handler
			SDL_Event e;

			// While application is running
			while (!quit)
			{
				// Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					// User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}

					// Handle button events
					for (int i = 0; i < TOTAL_BUTTONS; ++i)
					{
						gButtons[i].handleEvent(&e);
					}
				}

				// Clear screen
				SDL_SetRenderDrawColor(gRenderer, 0x87, 0xCE, 0xEB, 0xFF);
				SDL_RenderClear(gRenderer);

				// Render background
				gBackgroundTexture.render(0, 0);

				// Render containers (for visualization purposes, using rectangles)
				SDL_Rect containerA = {CONTAINER_MARGIN, CONTAINER_MARGIN, CONTAINER_WIDTH, CONTAINER_HEIGHT};
				SDL_Rect containerB = {CONTAINER_MARGIN + CONTAINER_WIDTH + CONTAINER_MARGIN, CONTAINER_MARGIN, CONTAINER_WIDTH, CONTAINER_HEIGHT};
				SDL_Rect containerInfo = {CONTAINER_MARGIN, CONTAINER_MARGIN + CONTAINER_HEIGHT + CONTAINER_MARGIN, SCREEN_WIDTH - 2 * CONTAINER_MARGIN, SCREEN_HEIGHT - CONTAINER_HEIGHT - 2 * CONTAINER_MARGIN};

				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF); // Red for Team A container
				SDL_RenderFillRect(gRenderer, &containerA);
				SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0x00, 0xFF); // Green for Team B container
				SDL_RenderFillRect(gRenderer, &containerB);
				SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0xFF, 0xFF); // Blue for Info container
				SDL_RenderFillRect(gRenderer, &containerInfo);

				// Render buttons
				for (int i = 0; i < TOTAL_BUTTONS; ++i)
				{
					gButtons[i].render();
				}

				// Update screen
				SDL_RenderPresent(gRenderer);
			}
		}
	}
	
	// Free resources and close SDL
	close();
	*/
	return 0;
}