#include "CreatePlayer.h"

void CreatePlayer::ForgePlayer(Player& p)
{
	ClearBackground(LIME);
    float boxWidth = 300;
    float boxHeight = 50;
    float spacing = 30;
    float numBoxes = 2; // Name and Surname

    float boxX = (GetScreenWidth() - boxWidth) / 2;
    float boxY = (GetScreenHeight() - (boxHeight * numBoxes + spacing * (numBoxes - 1))) / 2;

    static int activeBox = 0; // 0 = name, 1 = surname
    static bool showError = false;
    static int errorTimer = 0;
    const int errorDuration = 120; // frame (2 seconds at 60 FPS)

	// Name box position
    static TextBox boxName = { Rectangle{boxX, boxY, boxWidth, boxHeight}, "" };
    boxName.fontSize = 24;
    boxName.boxColor = LIGHTGRAY;
    boxName.borderColor = DARKGRAY;
    boxName.textColor = BLACK;
    boxName.spacing = 1.0f;
    boxName.maxLength = 32;

	// Surname box position
    static TextBox boxSurname = { Rectangle{boxX, boxY + boxHeight + spacing, boxWidth, boxHeight}, "" };
    boxSurname.fontSize = 24;
    boxSurname.boxColor = LIGHTGRAY;
    boxSurname.borderColor = DARKGRAY;
    boxSurname.textColor = BLACK;
    boxSurname.spacing = 1.0f;
    boxSurname.maxLength = 32;

	// Sets the active box based on the current activeBox index
    boxName.active = (activeBox == 0);
    boxSurname.active = (activeBox == 1);

	// Change focus with Tab key
    if (IsKeyPressed(KEY_TAB)) {
        activeBox = (activeBox + 1) % 2;
    }

    // Box management
    IsTextBoxActive(boxName);
    UpdateTextBox(boxName);
    IsTextBoxActive(boxSurname);
    UpdateTextBox(boxSurname);

    // Validation and visual feedback
    std::string name = GetTextBoxContent(boxName);
    std::string surname = GetTextBoxContent(boxSurname);

    // Reset border colors
    boxName.borderColor = DARKGRAY;
    boxSurname.borderColor = DARKGRAY;

    // Confirm both fields with Enter only if they are not empty
    if (IsKeyPressed(KEY_ENTER)) {
        if (name.empty() || surname.empty()) {
            showError = true;
            errorTimer = errorDuration;
            if (name.empty()) boxName.borderColor = RED;
            if (surname.empty()) boxSurname.borderColor = RED;
            TraceLog(LOG_WARNING, "First and/or last name cannot be blank!");
        } else {
            p.SetName(name);
            p.SetSurname(surname);
            boxName.active = false;
            boxSurname.active = false;
            showError = false;
            TraceLog(LOG_INFO, TextFormat("Player name confirmed: %s", p.GetName().c_str()));
            TraceLog(LOG_INFO, TextFormat("Player surname confirmed: %s", p.GetSurname().c_str()));
            currentScreen = SCREEN_COUNTRY_SELECT;
        }
    }

    // Labels above boxes, centered horizontally
    Vector2 labelNameSize = MeasureTextEx(font, "Nome", 24, 1);
    Vector2 labelNamePos = { boxX + (boxWidth - labelNameSize.x) / 2, boxY - labelNameSize.y - 6 };
    DrawTextEx(font, "Name", labelNamePos, 24, 1, WHITE);

    Vector2 labelSurnameSize = MeasureTextEx(font, "Cognome", 24, 1);
    Vector2 labelSurnamePos = { boxX + (boxWidth - labelSurnameSize.x) / 2, boxY + boxHeight + spacing - labelSurnameSize.y - 6 };
    DrawTextEx(font, "Surname", labelSurnamePos, 24, 1, WHITE);

	// Label to press Enter key to confirm
	Vector2 confirmTextSize = MeasureTextEx(font, "Premi Invio per confermare", 24, 1);
	Vector2 confirmTextPos = { boxX + (boxWidth - confirmTextSize.x) / 2, boxY + boxHeight * numBoxes + spacing * (numBoxes - 1) + 10 };
	DrawTextEx(font, "Press Enter to confirm", confirmTextPos, 24, 1, WHITE);

    // Draw the boxes with the correct color
    DrawTextBox(boxName);
    DrawTextBox(boxSurname);

    // Show error message if necessary
    if (showError) {
		Vector2 positionText = { boxX + boxWidth / 2, boxY + boxHeight * 2 + spacing };
        DrawTextEx(font, "Fill in all fields!", positionText, 24, 1, RED);
        if (--errorTimer <= 0) showError = false;
    }
}

void CreatePlayer::CountrySelect(Player& p)
{
    ClearBackground(LIME);

	// Load the list of countries from JSON file
    static std::vector<std::string> countries = LoadCountriesFromJson("C:\\Users\\marco\\source\\repos\\LifeSim\\assets\\countries_data\\countries.json");
    static int selectedIndex = 0;

	// Input handling
    if (IsKeyPressed(KEY_DOWN)) {
        selectedIndex = (selectedIndex + 1) % countries.size();
    }
    if (IsKeyPressed(KEY_UP)) {
        selectedIndex = (selectedIndex - 1 + static_cast<int>(countries.size())) % static_cast<int>(countries.size());
    }
    if (IsKeyPressed(KEY_ENTER)) {
        // Save the selected nation in the Player
        p.SetNationality(countries[selectedIndex]);
        TraceLog(LOG_INFO, TextFormat("Selected country: %s", p.GetNationality().c_str()));
        currentScreen = SCREEN_START_MENU; // SET NEXT SCREEN
    }

	// View the list of countries
    float boxWidth = 400;
    float boxHeight = 40;
    float boxX = (GetScreenWidth() - boxWidth) / 2;
    float boxY = (GetScreenHeight() - boxHeight) / 2;

	for (int i = 0; i < 5 && i < countries.size(); ++i) { // Show up to 5 countries
        // Cast countries.size() to int to avoid warning C4244 (conversion from size_t to int)
        int idx = (selectedIndex + i - 2 + static_cast<int>(countries.size())) % static_cast<int>(countries.size());
        Color color = (idx == selectedIndex) ? YELLOW : LIGHTGRAY;
        Vector2 pos = { boxX, boxY + (i * boxHeight) };
        DrawRectangleRec({ pos.x, pos.y, boxWidth, boxHeight }, color);
        DrawTextEx(font, countries[idx].c_str(), { pos.x + 10, pos.y + 8 }, 24, 1, BLACK);
    }

    // Instructions
    Vector2 infoPos = { boxX, boxY - 50 };
    DrawTextEx(font, "Select the country with the arrows and press Enter", infoPos, 24, 1, WHITE);
}
