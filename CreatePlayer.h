#pragma once
#include "Globals.h"
#include "Player.h"

extern GameScreen currentScreen;

class CreatePlayer
{
private:
	Button countryButton;
	Button signButton;
	Button play;
public:
	void ForgePlayer(Player& p);
	void CountrySelect(Player& p);
	void SignSelect(Player& p);
};

