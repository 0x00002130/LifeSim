#include "Globals.h"
#include "StartMenu.h"
#include "Player.h"
#include "CreatePlayer.h"
#include "GameMenu.h"
#include "PlayerStats.h"
#include "Jobs.h"

Font font;
StartMenu sm;
Player p;
CreatePlayer cp;
GameMenu gm;
PlayerStats ps;
Jobs j;

GameScreen currentScreen = SCREEN_START_MENU;


int main()
{
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
	InitWindow(SCREENWIDTH, SCREENHEIGHT, "Life Simulator");

	SetTargetFPS(TARGET_FPS);

	// Initialize font
	font = LoadFont("assets/fonts/Roboto-Italic-VariableFont_wdth,wght.ttf");
	SetTextureFilter(font.texture, TEXTURE_FILTER_BILINEAR);

	if (font.baseSize == 0) {
		std::cerr << "Error loading font.\n";
		return -1;
	} else {
		TraceLog(LOG_INFO, "Font loaded successfully.");
	}

	// Initialize audio device
	InitAudioDevice();
	sm.playSound = LoadSound("assets/sounds/pop-331049.mp3");
	if (sm.playSound.frameCount == 0) {
		std::cerr << "Error loading sound.\n";
		return -1;
	} else {
		TraceLog(LOG_INFO, "Sound loaded successfully.");
	}


	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(WHITE);
		switch (currentScreen) {
		case SCREEN_START_MENU:
			sm.InitMenu();
			sm.UpdateMenu();
			break;
		case SCREEN_CREATE_PLAYER:
			p.InitPlayer();
			cp.ForgePlayer(p);
			break;
		case SCREEN_COUNTRY_SELECT:
			cp.CountrySelect(p);
			break;
		case SCREEN_SIGN_SELECT:
			cp.SignSelect(p);
			break;
		case SCREEN_INTERFACE:
			gm.DrawStartMenu();
			break;
		case SCREEN_PLAYER_STATS:
			ps.DrawPlayerStats(p);
			break;
		case SCREEN_JOBS:
			j.DrawJobs(p);
			break;
		case SCREEN_LOAD:
			break;
		case SCREEN_SETTINGS:
			break;
		case SCREEN_EXIT:
			UnloadFont(font);
			CloseWindow();
			return 0;
		default:
			std::cout << "Error: current screen not found.\n";
		}

		EndDrawing();
	}

	UnloadFont(font);
	UnloadSound(sm.playSound);
	CloseAudioDevice();
	CloseWindow();

	return 0;
}