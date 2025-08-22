#pragma once
#include "Globals.h"
#include "Player.h"
extern GameScreen currentScreen;

class Jobs
{
	public:
	// Constructor
	Jobs() = default;
	// Destructor
	~Jobs() = default;
	
	// Buttons for jobs
	Button job1Button;
	Button job2Button;
	Button job3Button;
	Button job4Button;
	Button job5Button;
	Button job6Button;
	Button job7Button;
	Button job8Button;
	Button job9Button;
	Button job10Button;
	// Button for going back to the interface
	Button backButton;
	// Function to draw jobs
	void DrawJobs(Player& p);
};

