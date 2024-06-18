#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <vector>
#include <sstream>
#include "../include/SoccerPlayer.hpp"
#include "../include/SoccerTeam.hpp"
#include "../include/SoccerMatch.hpp"
#include "../include/GoalKeeper.hpp"

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 800

// Define o enum do estado da tela
enum ScreenState
{
	SELECT_TEAM_A,
	SELECT_TEAM_B,
	SELECT_TEAM_A_INITIAL,
	SELECT_TEAM_B_INITIAL,
	ATTACK_TEAM_A,
	ATTACK_TEAM_B,
	START,
	END
};

// Estrutura para representar os jogadores
struct Player
{
	SDL_Texture *texture; // Textura do jogador
	SDL_Rect rect;		  // Retângulo para renderização da textura
};

// Função para renderizar texto
void renderText(SDL_Renderer *renderer, TTF_Font *font, const std::string &text, int x, int y)
{
	SDL_Color color = {255, 255, 255}; // Branco
	SDL_Surface *surface = TTF_RenderText_Blended(font, text.c_str(), color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_Rect destRect = {x, y, surface->w, surface->h};
	SDL_RenderCopy(renderer, texture, NULL, &destRect);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

// Função para carregar texturas
SDL_Texture *loadTexture(std::string path, SDL_Renderer *renderer)
{
	SDL_Texture *newTexture = nullptr;
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == nullptr)
	{
		std::cerr << "Unable to load image " << path << "! SDL_image Error: " << IMG_GetError() << std::endl;
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}



int startgame(SoccerMatch soccerMatch, SoccerTeam *soccerteamA, SoccerTeam *soccerteamB){

// SDL config

	// Define a tela START como a inicial
	ScreenState currentScreen = START;

	// Inicializa as bibliotecas
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		return -1;
	}

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		std::cerr << "SDL_image could not initialize! IMG_Error: " << IMG_GetError() << std::endl;
		return -1;
	}

	if (TTF_Init() == -1)
	{
		std::cerr << "TTF could not initialize! TTF_Error: " << TTF_GetError() << std::endl;
		return -1;
	}

	// Cria a janela, o renderer e carrega as imagens
	SDL_Window *window = SDL_CreateWindow("FUT++", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (!window)
	{
		std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		return -1;
	}

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer)
	{
		std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		return -1;
	}

	SDL_Texture *backgroundTexture = IMG_LoadTexture(renderer, "game_graphics/Backgrounds/background.png");
	SDL_Texture *fieldTexture = IMG_LoadTexture(renderer, "game_graphics/Backgrounds/fieldBackground.png");
	if (!backgroundTexture || !fieldTexture)
	{
		std::cerr << "Failed to load background image! IMG_Error: " << IMG_GetError() << std::endl;
		return -1;
	}

	// Cores
	SDL_Color darkGreen = {0, 100, 0};
	SDL_Color whiteColor = {255, 255, 255};
	SDL_Color redColor = {255, 0, 0};
	SDL_Color greenColor = {0, 128, 0};
	SDL_Color backgroundButtonColor = whiteColor;
	SDL_Color goldColor = {255, 215, 0};
	SDL_Color blueColor = {0, 0, 255};	   // Azul sólido
	SDL_Color orangeColor = {255, 165, 0}; // Laranja
	SDL_Color purpleColor = {128, 0, 128}; // Púrpura

	// Fontes
	TTF_Font *titleFont = TTF_OpenFont("game_graphics/Fonts/Roboto-Medium.ttf", 48);
	TTF_Font *fontStartButtom = TTF_OpenFont("game_graphics/Fonts/Roboto-Medium.ttf", 28);
	TTF_Font *font = TTF_OpenFont("game_graphics/Fonts/Roboto-Medium.ttf", 24);
	TTF_Font *font_round = TTF_OpenFont("game_graphics/Fonts/Roboto-Medium.ttf", 16);
	TTF_Font *font_terminal = TTF_OpenFont("game_graphics/Fonts/Roboto-Medium.ttf", 12);
	if (!font || !font_round || !titleFont || !fontStartButtom)
	{
		std::cerr << "Erro ao carregar a fonte: " << TTF_GetError() << std::endl;
		return -1;
	}

	// COMPONENTES DA TELA INICIAL

	// Cria o titulo da tela inicial
	SDL_Surface *surfaceTitle = TTF_RenderText_Solid(titleFont, "FUT++", whiteColor);
	SDL_Texture *titleTexture = SDL_CreateTextureFromSurface(renderer, surfaceTitle);
	int titleWidth = surfaceTitle->w;
	int titleHeight = surfaceTitle->h;
	SDL_Rect titleRect = {(WINDOW_WIDTH - titleWidth) / 2, 10, titleWidth, titleHeight};

	// Texto usado no botão central
	std::string buttonText = "START";

	// COMPONENTES DA TELA DE JOGO

	// Variáveis para o placar
	int cru_score = 0;
	int cam_score = 0;
	int round_count = 1;
	int score_total_width;	   // 10 pixels de espaço entre elese;
	int score_top_margin = 30; // Espaço do topo da janela
	std::string champion;

	// Variáveis para manipulação dos jogadores
	std::vector<Player> teamA(6), teamB(6);
	Player goleiroA, goleiroB;
	int card_width = 60;
	int card_height = 80;
	int selectedStarterA = -1, selectedReserveA = -1, selectedStarterB = -1, selectedReserveB = -1;
	std::vector<int> attackArrayA = {-1, -1, -1};
	std::vector<int> attackArrayB = {-1, -1, -1};
	int playerAttackA = -1, playerAttackB = -1, playerDeffenseA = -1, playerDeffenseB = -1;

	// Inicializa os jogadores do time A
	teamA[0].texture = loadTexture("game_graphics/TeamCruzeiro/miniatures/Ronaldofenomeno3.png", renderer);
	teamA[1].texture = loadTexture("game_graphics/TeamCruzeiro/miniatures/Tostão3.png", renderer);
	teamA[2].texture = loadTexture("game_graphics/TeamCruzeiro/miniatures/EvertonRibeiro3.png", renderer);
	teamA[3].texture = loadTexture("game_graphics/TeamCruzeiro/miniatures/Alex3.jpg", renderer);
	teamA[4].texture = loadTexture("game_graphics/TeamCruzeiro/miniatures/Sorin3.png", renderer);
	teamA[5].texture = loadTexture("game_graphics/TeamCruzeiro/miniatures/Marcelomoreno3.png", renderer);
	goleiroA.texture = loadTexture("game_graphics/TeamCruzeiro/miniatures/Fabio3.png", renderer);
	teamA[0].rect = {120, 100, card_width, card_height}; // x, y, width, height
	teamA[1].rect = {120, 280, card_width, card_height};
	teamA[2].rect = {200, 190, card_width, card_height};
	teamA[3].rect = {10, 10, card_width, card_height};
	teamA[4].rect = {card_width + 20, 10, card_width, card_height};
	teamA[5].rect = {(card_width * 2) + 30, 10, card_width, card_height};
	goleiroA.rect = {10, 220, card_width, card_height};

	// Inicializa os jogadores do time B
	teamB[0].texture = loadTexture("game_graphics/TeamGalo/miniatures/Hulk3.png", renderer);
	teamB[1].texture = loadTexture("game_graphics/TeamGalo/miniatures/Tardelli3.png", renderer);
	teamB[2].texture = loadTexture("game_graphics/TeamGalo/miniatures/RonaldinhoGaucho3.png", renderer);
	teamB[3].texture = loadTexture("game_graphics/TeamGalo/miniatures/Rever3.png", renderer);
	teamB[4].texture = loadTexture("game_graphics/TeamGalo/miniatures/Luan3.png", renderer);
	teamB[5].texture = loadTexture("game_graphics/TeamGalo/miniatures/Donizete3.png", renderer);
	goleiroB.texture = loadTexture("game_graphics/TeamGalo/miniatures/Vitor3.png", renderer);
	teamB[0].rect = {WINDOW_WIDTH - (card_width + 120), 100, card_width, card_height}; // x, y, width, height
	teamB[1].rect = {WINDOW_WIDTH - (card_width + 120), 280, card_width, card_height};
	teamB[2].rect = {WINDOW_WIDTH - (card_width + 200), 190, card_width, card_height};
	teamB[3].rect = {WINDOW_WIDTH - (card_width + 10), 10, card_width, card_height};
	teamB[4].rect = {WINDOW_WIDTH - (2 * card_width + 20), 10, card_width, card_height};
	teamB[5].rect = {WINDOW_WIDTH - (3 * card_width + 30), 10, card_width, card_height};
	goleiroB.rect = {WINDOW_WIDTH - (card_width + 10), 220, card_width, card_height};

	// variáveis do terminal
	SDL_StartTextInput();
	std::vector<std::string> lines;
	int topLineIndex = 0;
	Uint32 lastTime = 0, currentTime;
	int count = 0;
	SDL_Rect textContainer = {10, 400, 780, 190};

	bool running = true;
	SDL_Event e;
	while (running)
	{
		// ELEMENTOS DINAMICOS

		// Cria as linhas do terminal
		currentTime = SDL_GetTicks();
		if (currentTime - lastTime >= 500 && count < 50)
		{
			lastTime = currentTime;
			std::stringstream lineText;
			lineText << "exemplo " << count + 1;
			lines.push_back(lineText.str());
			count++;
		}

		// Cria o botão central
		SDL_Surface *buttonStart = TTF_RenderText_Solid(fontStartButtom, buttonText.c_str(), whiteColor);
		SDL_Texture *buttonTexture = SDL_CreateTextureFromSurface(renderer, buttonStart);
		SDL_Rect buttonStart_rect;
		int buttonStartWidth = buttonStart->w + 60;
		int buttonStartHeight = buttonStart->h + 40;
		buttonStart_rect.x = (WINDOW_WIDTH - buttonStartWidth) / 2;
		buttonStart_rect.y = 300;
		buttonStart_rect.w = buttonStartWidth;
		buttonStart_rect.h = buttonStartHeight;
		SDL_Rect text_rect;
		text_rect.x = buttonStart_rect.x + 30;
		text_rect.y = buttonStart_rect.y + 20;
		text_rect.w = buttonStart->w;
		text_rect.h = buttonStart->h;

		// Constrói o texto de campeão
		std::string champion_text = "Vencedor: " + champion;
		SDL_Surface *surface_champion = TTF_RenderText_Solid(titleFont, champion_text.c_str(), goldColor);
		SDL_Texture *champion_texture = SDL_CreateTextureFromSurface(renderer, surface_champion);
		SDL_Rect champion_rect = {(WINDOW_WIDTH - surface_champion->w) / 2, (WINDOW_HEIGHT - surface_champion->h) / 2, surface_champion->w, surface_champion->h};

		// Textos utilizados no placar
		std::string cru_text = "CRU " + std::to_string(cru_score);
		std::string cam_text = std::to_string(cam_score) + " CAM";
		std::string round_text = "Round " + std::to_string(round_count);
		// Cria os componentes do placar
		SDL_Surface *surface_cru = TTF_RenderText_Solid(font, cru_text.c_str(), whiteColor);
		SDL_Surface *surface_round = TTF_RenderText_Solid(font_round, round_text.c_str(), goldColor);
		SDL_Surface *surface_cam = TTF_RenderText_Solid(font, cam_text.c_str(), whiteColor);
		score_total_width = surface_cru->w + surface_round->w + surface_cam->w + 20;
		SDL_Texture *texture_cru = SDL_CreateTextureFromSurface(renderer, surface_cru);
		SDL_Texture *texture_round = SDL_CreateTextureFromSurface(renderer, surface_round);
		SDL_Texture *texture_cam = SDL_CreateTextureFromSurface(renderer, surface_cam);
		SDL_Rect cru_rect = {(WINDOW_WIDTH - score_total_width) / 2, score_top_margin, surface_cru->w, surface_cru->h};
		SDL_Rect round_rect = {cru_rect.x + surface_cru->w + 10, 35, surface_round->w, surface_round->h};
		SDL_Rect cam_rect = {round_rect.x + surface_round->w + 10, score_top_margin, surface_cam->w, surface_cam->h};
		SDL_Rect background_rect = {cru_rect.x - 10, score_top_margin - 5, score_total_width + 20, surface_cru->h + 10};

		// RENDERIZAÇÂO

		if (currentScreen == START)
		{
			SDL_RenderClear(renderer);
			SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

			// Desenha o título no topo da janela
			SDL_RenderCopy(renderer, titleTexture, NULL, &titleRect);

			// Renderiza o botão
			SDL_RenderFillRect(renderer, &buttonStart_rect);
			SDL_SetRenderDrawColor(renderer, backgroundButtonColor.r, backgroundButtonColor.g, backgroundButtonColor.b, 255);
			SDL_RenderCopy(renderer, buttonTexture, NULL, &text_rect);

			SDL_RenderPresent(renderer);
		}
		else if (currentScreen != END)
		{
			SDL_RenderClear(renderer);
			SDL_RenderCopy(renderer, fieldTexture, NULL, NULL);

			// Renderiza o placar
			SDL_RenderCopy(renderer, texture_cru, NULL, &cru_rect);
			SDL_RenderCopy(renderer, texture_round, NULL, &round_rect);
			SDL_RenderCopy(renderer, texture_cam, NULL, &cam_rect);

			// Renderiza os jogadores e desenha a margem de seleção
			for (int i = 0; i < teamA.size(); i++)
			{
				SDL_RenderCopy(renderer, teamA[i].texture, nullptr, &teamA[i].rect);
				SDL_RenderCopy(renderer, teamB[i].texture, nullptr, &teamB[i].rect);

				if (i == selectedStarterA)
				{
					SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF); // Vermelho para titular selecionado
					SDL_RenderDrawRect(renderer, &teamA[i].rect);
				}
				else if (i == selectedReserveA)
				{
					SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF); // Verde para reserva selecionado
					SDL_RenderDrawRect(renderer, &teamA[i].rect);
				}
				else if (i == selectedStarterB)
				{
					SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF); // Vermelho para titular selecionado
					SDL_RenderDrawRect(renderer, &teamB[i].rect);
				}
				else if (i == selectedReserveB)
				{
					SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF); // Verde para reserva selecionado
					SDL_RenderDrawRect(renderer, &teamB[i].rect);
				}
			}

			// Renderiza os goleiros
			SDL_RenderCopy(renderer, goleiroA.texture, nullptr, &goleiroA.rect);
			SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
			SDL_RenderDrawRect(renderer, &goleiroA.rect);
			SDL_RenderCopy(renderer, goleiroB.texture, nullptr, &goleiroB.rect);
			SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
			SDL_RenderDrawRect(renderer, &goleiroB.rect);

			// Renderiza o botão
			SDL_SetRenderDrawColor(renderer, backgroundButtonColor.r, backgroundButtonColor.g, backgroundButtonColor.b, 255);
			SDL_RenderFillRect(renderer, &buttonStart_rect);
			SDL_RenderCopy(renderer, buttonTexture, NULL, &text_rect);

			// renderiza o terminal
			SDL_SetRenderDrawColor(renderer, 10, 24, 72, 255); // Azul escuro
			SDL_RenderFillRect(renderer, &textContainer);
			int y = textContainer.y; // Inicia na margem superior do container
			int lineHeight = 14;	 // Espaço entre as linhas
			for (int i = topLineIndex; i < std::min(topLineIndex + 13, (int)lines.size()); i++)
			{
				if (y + lineHeight <= textContainer.y + textContainer.h)
				{ // Assegura que o texto fique dentro do container
					renderText(renderer, font_terminal, lines[i], textContainer.x, y);
					y += lineHeight;
				}
			}
			if (lines.size() > 13)
			{
				lines.erase(lines.begin(), lines.begin() + (lines.size() - 13));
			}

			SDL_RenderPresent(renderer);
		}
		else
		{
			SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
			SDL_RenderClear(renderer);

			// Renderiza o texto de campeão
			SDL_RenderCopy(renderer, champion_texture, NULL, &champion_rect);

			SDL_RenderPresent(renderer);
		}

		// EVENTOS

		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				running = false;
			}
			else if (e.type == SDL_MOUSEMOTION)
			{
				int mouseX = e.motion.x;
				int mouseY = e.motion.y;
				if (mouseX >= buttonStart_rect.x && mouseX <= (buttonStart_rect.x + buttonStart_rect.w) &&
					mouseY >= buttonStart_rect.y && mouseY <= (buttonStart_rect.y + buttonStart_rect.h))
				{
					backgroundButtonColor = redColor;
				}
				else
				{
					backgroundButtonColor = greenColor;
				}
			}
			else if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				int mouseX, mouseY;
				SDL_GetMouseState(&mouseX, &mouseY);
				if (mouseX >= buttonStart_rect.x && mouseX <= (buttonStart_rect.x + buttonStart_rect.w) &&
					mouseY >= buttonStart_rect.y && mouseY <= (buttonStart_rect.y + buttonStart_rect.h))
				{
					switch (currentScreen)
					{
					case START:
						buttonText = "ESCALAR";
						currentScreen = SELECT_TEAM_A;
						break;
					case SELECT_TEAM_A:
						buttonText = "ESCALAR";
						currentScreen = SELECT_TEAM_B;
						break;
					case SELECT_TEAM_B:
						buttonText = "ATACAR";
						currentScreen = ATTACK_TEAM_A;
						attackArrayA = {-1, -1, -1};
						attackArrayB = {-1, -1, -1};
						break;
					case ATTACK_TEAM_A:
						buttonText = "ATACAR";
						currentScreen = ATTACK_TEAM_B;
						attackArrayA = {-1, -1, -1};
						attackArrayB = {-1, -1, -1};
						break;
					case ATTACK_TEAM_B:
						champion = "Cruzeiro";
						currentScreen = END;
						break;
					default:
						break;
					}
				}
				else if (currentScreen == SELECT_TEAM_A || currentScreen == SELECT_TEAM_A_INITIAL)
				{
					for (int i = 0; i < teamA.size(); i++)
					{
						if (mouseX >= teamA[i].rect.x && mouseX <= (teamA[i].rect.x + teamA[i].rect.w) &&
							mouseY >= teamA[i].rect.y && mouseY <= (teamA[i].rect.y + teamA[i].rect.h))
						{
							if (i >= 3 && selectedReserveA == -1)
							{
								selectedReserveA = i;
							}
							else if (i < 3 && selectedStarterA == -1)
							{
								selectedStarterA = i;
							}
						}
					}

					// Trocar jogadores se ambos estiverem selecionados
					if (selectedReserveA != -1 && selectedStarterA != -1)
					{
						std::swap(teamA[selectedReserveA].texture, teamA[selectedStarterA].texture);
						soccerteamA->swapPlayer(soccerteamA->getShirtPlayerPosition(soccerteamA, selectedReserveA),soccerteamA->getShirtPlayerPosition(soccerteamA, selectedStarterA));
						selectedReserveA = -1;
						selectedStarterA = -1;
					}
				}
				else if (currentScreen == SELECT_TEAM_B || currentScreen == SELECT_TEAM_B_INITIAL)
				{
					for (int i = 0; i < teamB.size(); i++)
					{
						if (mouseX >= teamB[i].rect.x && mouseX <= (teamB[i].rect.x + teamB[i].rect.w) &&
							mouseY >= teamB[i].rect.y && mouseY <= (teamB[i].rect.y + teamB[i].rect.h))
						{
							if (i >= 3 && selectedReserveB == -1)
							{
								selectedReserveB = i;
							}
							else if (i < 3 && selectedStarterB == -1)
							{
								selectedStarterB = i;
							}
						}
					}

					// Trocar jogadores se ambos estiverem selecionados
					if (selectedReserveB != -1 && selectedStarterB != -1)
					{
						std::swap(teamB[selectedReserveB].texture, teamB[selectedStarterB].texture);
						soccerteamB->swapPlayer(soccerteamB->getShirtPlayerPosition(soccerteamB, selectedReserveB),soccerteamB->getShirtPlayerPosition(soccerteamB, selectedStarterB));
						selectedReserveB = -1;
						selectedStarterB = -1;
					}
				}
			}
			else if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_1:
					cru_score++;
					break;
				case SDLK_2:
					round_count++;
					break;
				case SDLK_3:
					cam_score++;
					break;
				default:
					break;
				}
			}
		}
	}

	for (auto &player : teamA)
	{
		if (player.texture)
			SDL_DestroyTexture(player.texture);
	}
	for (auto &player : teamB)
	{
		if (player.texture)
			SDL_DestroyTexture(player.texture);
	}
	SDL_StopTextInput();
	SDL_FreeSurface(surfaceTitle);
	SDL_DestroyTexture(titleTexture);
	SDL_DestroyTexture(backgroundTexture);
	TTF_CloseFont(titleFont);
	TTF_CloseFont(fontStartButtom);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();

}


void buildGame()
{
	SoccerPlayer *player1 = new SoccerPlayer();
	SoccerPlayer *player2 = new SoccerPlayer();
	SoccerPlayer *player3 = new SoccerPlayer();
	SoccerPlayer *player4 = new SoccerPlayer();
	SoccerPlayer *player5 = new SoccerPlayer();
	SoccerPlayer *player6 = new SoccerPlayer();
	GoalKeeper *goalKeeper1 = new GoalKeeper();

	SoccerPlayer *player7 = new SoccerPlayer();
	SoccerPlayer *player8 = new SoccerPlayer();
	SoccerPlayer *player9 = new SoccerPlayer();
	SoccerPlayer *player10 = new SoccerPlayer();
	SoccerPlayer *player11 = new SoccerPlayer();
	SoccerPlayer *player12 = new SoccerPlayer();
	GoalKeeper *goalKeeper2 = new GoalKeeper();

	SoccerTeam *team1 = new SoccerTeam();
	SoccerTeam *team2 = new SoccerTeam();
	// Time Atletico
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

	// Time Cruzeiro
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

	startgame(soccerMatch, team2, team1);

}




int main(int argc, char *args[])
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

	
	return 0;
}