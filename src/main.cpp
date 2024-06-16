#include <iostream>
#include "../include/SoccerPlayer.hpp"
#include "../include/SoccerTeam.hpp"
#include "../include/SoccerMatch.hpp"
#include "../include/GoalKeeper.hpp"
#include "../include/sdl2.hpp"

int main(int argc, char* args[])
{

	SoccerPlayer* player1 = new SoccerPlayer();
	SoccerPlayer* player2 = new SoccerPlayer();
	SoccerPlayer* player3 = new SoccerPlayer();
	GoalKeeper* goalKeeper1 = new GoalKeeper();

	SoccerPlayer* player4 = new SoccerPlayer();
	SoccerPlayer* player5 = new SoccerPlayer();
	SoccerPlayer* player6 = new SoccerPlayer();
	GoalKeeper* goalKeeper2 = new GoalKeeper();

	SoccerTeam* team1 = new SoccerTeam();
	SoccerTeam* team2 = new SoccerTeam();

	player1->setName("Vini Jr");
	player1->setResistance(40);
	player1->setAgility(50);
	player1->setStrength(20);
	player1->setDribbling(60);
	player1->setShooting(60);
	player1->setPassing(30);

	player2->setName("Rodrygo");
	player2->setResistance(70);
	player2->setAgility(50);
	player2->setStrength(30);
	player2->setDribbling(20);
	player2->setShooting(50);
	player2->setPassing(30);

	player3->setName("Marcelo");
	player3->setResistance(40);
	player3->setAgility(50);
	player3->setStrength(40);
	player3->setDribbling(40);
	player3->setShooting(50);
	player3->setPassing(70);

	player4->setName("Kroos");
	player4->setResistance(20);
	player4->setAgility(40);
	player4->setStrength(40);
	player4->setDribbling(70);
	player4->setShooting(10);
	player4->setPassing(30);

	player5->setName("Modric");
	player5->setResistance(50);
	player5->setAgility(30);
	player5->setStrength(20);
	player5->setDribbling(40);
	player5->setShooting(30);
	player5->setPassing(70);

	player6->setName("Cristiano");
	player6->setResistance(40);
	player6->setAgility(20);
	player6->setStrength(50);
	player6->setDribbling(40);
	player6->setShooting(70);
	player6->setPassing(20);

	goalKeeper1->setName("Fabio");
	goalKeeper1->setResistance(50);
	goalKeeper1->setAgility(80);
	goalKeeper1->setStrength(30);
	goalKeeper1->setFlexibility(20);
	goalKeeper1->setDefense(80);

	goalKeeper2->setName("Victor");
	goalKeeper2->setResistance(60);
	goalKeeper2->setAgility(50);
	goalKeeper2->setStrength(30);
	goalKeeper2->setFlexibility(20);
	goalKeeper2->setDefense(100);

	team1->insertSoccerPlayer(player1);
	team1->insertSoccerPlayer(player2);
	team1->insertSoccerPlayer(player3);
	team1->insertGoalKeeper(goalKeeper1);

	team2->insertSoccerPlayer(player4);
	team2->insertSoccerPlayer(player5);
	team2->insertSoccerPlayer(player6);
	team2->insertGoalKeeper(goalKeeper2);

	team1->showSoccerPlayerInformations();
	team2->showSoccerPlayerInformations();

	SoccerMatch soccerMatch = SoccerMatch(team1, team2);

	//soccerMatch.showTeams();

	soccerMatch.playMatch();

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

	return 0;
}