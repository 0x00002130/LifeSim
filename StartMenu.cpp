#include "StartMenu.h"


void StartMenu::InitMenu()
{
	ClearBackground(BLACK);
	float btnWidth = 250;
	float btnHeight = 60;
	float spacing = 20;
	int numButtons = 4;

	float totalHeight = btnHeight * numButtons + spacing * (numButtons - 1);
	float startY = (GetScreenHeight() - totalHeight) / 2;
	float x = (GetScreenWidth() - btnWidth) / 2;


	play.bounds = { x, startY + (btnHeight + spacing) * 0, btnWidth, btnHeight };
	play.color = BLUE;
	play.text = "Play";
	play.textColor = WHITE;

	load.bounds = { x, startY + (btnHeight + spacing) * 1, btnWidth, btnHeight };
	load.color = BLUE;
	load.text = "Load";
	load.textColor = WHITE;

	settings.bounds = { x, startY + (btnHeight + spacing) * 2, btnWidth, btnHeight };
	settings.color = BLUE;
	settings.text = "Settings";
	settings.textColor = WHITE;

	exit.bounds = { x, startY + (btnHeight + spacing) * 3, btnWidth, btnHeight };
	exit.color = BLUE;
	exit.text = "Exit";
	exit.textColor = WHITE;

	DrawButton(play);
	DrawButton(load);
	DrawButton(settings);
	DrawButton(exit);
}

int StartMenu::UpdateMenu()
{
	if (IsButtonClicked(play)) {
		return currentScreen = SCREEN_CREATE_PLAYER;
	}
	if (IsButtonClicked(load)) {
		return currentScreen = SCREEN_LOAD;
	}
	if (IsButtonClicked(settings)) {
		return currentScreen = SCREEN_SETTINGS;
	}
	if (IsButtonClicked(exit)) {
		return currentScreen = SCREEN_EXIT;
	}
	return currentScreen;
}

