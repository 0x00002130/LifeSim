#include "Jobs.h"

void Jobs::DrawJobs(Player& p)
{
	ClearBackground(LIME);
	// Disegna il pulsante per tornare all'interfaccia
	backButton.bounds = { 10, 10, 100, 40 };
	backButton.color = BLUE;
	backButton.text = "Back";
	backButton.textColor = BLACK;
	DrawButton(backButton);
	// Gestione del click sul pulsante "Back"
	if (IsButtonClicked(backButton)) {
		currentScreen = SCREEN_INTERFACE;
	}
	float btnWidth = 300;
	float btnHeight = 50;
	float spacing = 10;
	float centerX = GetScreenWidth() * 0.5f;
	float xLeft = centerX - btnWidth - 10;  // Margine tra colonne
	float xRight = centerX + 10;
	std::vector<std::pair<std::string, std::string>> jobs = {
		{"Job 1", "Description of Job 1"},
		{"Job 2", "Description of Job 2"},
		{"Job 3", "Description of Job 3"},
		{"Job 4", "Description of Job 4"},
		{"Job 5", "Description of Job 5"},
		{"Job 6", "Description of Job 6"},
		{"Job 7", "Description of Job 7"},
		{"Job 8", "Description of Job 8"},
		{"Job 9", "Description of Job 9"},
		{"Job 10", "Description of Job 10"}
	};
	size_t totalButtons = jobs.size();
	size_t numRows = (totalButtons + 1) / 2;
	float totalHeight = numRows * btnHeight + (numRows - 1) * spacing;
	float startY = (GetScreenHeight() - totalHeight) / 2;
	std::vector<Button> buttons;
	// INSERIRE NEL CICLO GLI IF PER I VARI LAVORI
	for (size_t i = 0; i < totalButtons; i++) {
		size_t row = i / 2;
		float y = startY + (btnHeight + spacing) * row;
		float x = (i % 2 == 0) ? xLeft : xRight;
		Button b;
		b.bounds = { x, y, btnWidth, btnHeight };
		b.color = BLUE;
		b.textColor = BLACK;
		b.text = jobs[i].first + ": " + jobs[i].second;
		DrawButton(b);
	}
	p.GetJob(); // Usato per evitare warning di variabile non usata
}
