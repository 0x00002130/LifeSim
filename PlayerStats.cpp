#include "PlayerStats.h"


// DA CAMBIARE
void PlayerStats::DrawPlayerStats(Player& p)
{
    ClearBackground(LIME);
	// Disegna il pulsante per tornare all'interfaccia
	backButton.bounds = { 10, 10, 150, 40 };
	backButton.color = BLUE;
	backButton.text = "Back to Interface";
	backButton.textColor = BLACK;
	DrawButton(backButton);
	// Gestione del click sul pulsante "Back to Interface"
    if (IsButtonClicked(backButton)) {
        currentScreen = SCREEN_INTERFACE;
    }

    float btnWidth = 300;
    float btnHeight = 50;
    float spacing = 10;

    float centerX = GetScreenWidth() * 0.5f;
    float xLeft = centerX - btnWidth - 10;  // Margine tra colonne
    float xRight = centerX + 10;

    std::vector<std::pair<std::string, StatValue>> stats = {
        {"Age", p.GetAge()},
        {"Health", p.GetHealth()},
        {"Happiness", p.GetHappiness()},
        {"Money", p.GetMoney()},
        {"Linguistic Intelligence", p.GetLinguisticIntelligence()},
        {"Logical Intelligence", p.GetLogicalIntelligence()},
        {"Spatial Intelligence", p.GetSpatialIntelligence()},
        {"Bodily Intelligence", p.GetBodilyIntelligence()},
        {"Musical Intelligence", p.GetMusicalIntelligence()},
        {"Interpersonal Intelligence", p.GetInterpersonalIntelligence()},
        {"Intrapersonal Intelligence", p.GetIntrapersonalIntelligence()},
        {"Naturalistic Intelligence", p.GetNaturalisticIntelligence()}
    };

    size_t totalButtons = stats.size();
    size_t numRows = (totalButtons + 1) / 2;

    float totalHeight = numRows * btnHeight + (numRows - 1) * spacing;
    float startY = (GetScreenHeight() - totalHeight) / 2;

    std::vector<Button> buttons;

    for (size_t i = 0; i < totalButtons; i++) {
        size_t row = i / 2;
        float y = startY + (btnHeight + spacing) * row;
        float x = (i % 2 == 0) ? xLeft : xRight;

        Button b;
        b.bounds = { x, y, btnWidth, btnHeight };
        b.color = BLUE;
        b.textColor = BLACK;
        b.text = stats[i].first + ": " + StatValueToString(stats[i].second);

        buttons.push_back(b);
    }

    // Disegna tutti i pulsanti
    for (const Button& b : buttons) {
        DrawButton(b);
    }
}

std::string PlayerStats::StatValueToString(const StatValue& value)
{
    return std::visit([](auto&& arg) -> std::string {
        return std::to_string(arg);
        }, value);
}

