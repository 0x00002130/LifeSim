#pragma once
#include "Globals.h"
#include "Player.h"

extern GameScreen currentScreen;

class CreatePlayer
{
public:
	void ForgePlayer(Player& p);
	void CountrySelect(Player& p);
};

