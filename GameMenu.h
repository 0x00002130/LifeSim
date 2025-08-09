#pragma once
#include "Globals.h"
#include "Player.h"

extern GameScreen currentScreen;

class GameMenu
{
	public:
	// Buttons for the game menu
	Button stats;

	GameMenu() = default;
	~GameMenu() = default;
	void DrawStartMenu();
	void DrawPlayerStats(Player& p);
};

