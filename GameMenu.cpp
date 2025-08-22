#include "GameMenu.h"

void GameMenu::DrawStartMenu()
{
	ClearBackground(LIME);
	stats.bounds = { Rectangle{ 50, 50, 200, 50 } };
	stats.color = BLUE;
	stats.text = "Player Stats";
	stats.textColor = BLACK;
	DrawButton(stats);
	jobs.bounds = { Rectangle{ 50, 120, 200, 50 } };
	jobs.color = BLUE;
	jobs.text = "Jobs";
	jobs.textColor = BLACK;
	DrawButton(jobs);

	if (IsButtonClicked(stats)) {
		// Handle stats button click
		currentScreen = SCREEN_PLAYER_STATS;
	}
	if (IsButtonClicked(jobs)) {
		// Handle jobs button click
		currentScreen = SCREEN_JOBS;
	}
}