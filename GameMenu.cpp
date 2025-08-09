#include "GameMenu.h"

void GameMenu::DrawStartMenu()
{
	ClearBackground(LIME);
	stats.bounds = { Rectangle{ 50, 50, 200, 50 } };
	stats.color = BLUE;
	stats.text = "Player Stats";
	stats.textColor = BLACK;
	DrawButton(stats);

	if (IsButtonClicked(stats)) {
		// Handle stats button click
		currentScreen = SCREEN_PLAYER_STATS;
	}
}