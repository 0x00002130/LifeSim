#pragma once
#include "Globals.h"
#include "Player.h"


extern GameScreen currentScreen;

class PlayerStats
{
	public:
	// Constructor
	PlayerStats() = default;
	// Destructor
	~PlayerStats() = default;
	
	// Button for going back to the interface
	Button backButton;

	// Buttons for player stats
	Button ageButton;
	Button healthButton;
	Button happinessButton;
	Button moneyButton;
	Button linguisticIntelligenceButton;
	Button logicalIntelligenceButton;
	Button spatialIntelligenceButton;
	Button bodilyIntelligenceButton;
	Button musicalIntelligenceButton;
	Button interpersonalIntelligenceButton;
	Button intrapersonalIntelligenceButton;
	Button naturalisticIntelligenceButton;

	
	

	// Function to draw player stats
	void DrawPlayerStats(Player& p);


	using StatValue = std::variant<int, float, double>;
	std::string StatValueToString(const StatValue& value);
};

