#pragma once
#include "Globals.h"

extern GameScreen currentScreen;

class StartMenu
{
public:
	Button play;
	Button load;
	Button settings;
	Button exit;
	
	Sound playSound;

	void InitMenu();
	int UpdateMenu();
};



