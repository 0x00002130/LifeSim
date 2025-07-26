#include "Globals.h"
#include "StartMenu.h"
#include "Player.h"
#include "CreatePlayer.h"

Font font;
StartMenu sm;
Player p;
CreatePlayer cp;

GameScreen currentScreen = SCREEN_START_MENU;


int main()
{
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
	InitWindow(SCREENWIDTH, SCREENHEIGHT, "Life Simulator");

	SetTargetFPS(TARGET_FPS);

	font = LoadFont("C:\\Users\\marco\\source\\repos\\LifeSim\\assets\\fonts\\Roboto-Italic-VariableFont_wdth,wght.ttf");

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
	CloseWindow();

	return 0;
}