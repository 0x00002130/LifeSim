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
            TraceLog(LOG_WARNING, "Nome e/o cognome non possono essere vuoti!");
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
    DrawTextEx(font, "Name", labelNamePos, 24, 1, DARKGRAY);

    Vector2 labelSurnameSize = MeasureTextEx(font, "Cognome", 24, 1);
    Vector2 labelSurnamePos = { boxX + (boxWidth - labelSurnameSize.x) / 2, boxY + boxHeight + spacing - labelSurnameSize.y - 6 };
    DrawTextEx(font, "Surname", labelSurnamePos, 24, 1, DARKGRAY);

	// Label to press Enter key to confirm
	Vector2 confirmTextSize = MeasureTextEx(font, "Premi Invio per confermare", 24, 1);
	Vector2 confirmTextPos = { boxX + (boxWidth - confirmTextSize.x) / 2, boxY + boxHeight * numBoxes + spacing * (numBoxes - 1) + 10 };
	DrawTextEx(font, "Press Enter to confirm", confirmTextPos, 24, 1, DARKGRAY);

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
    // Placeholder for country selection logic
    Vector2 position = { static_cast<float>(GetScreenWidth() / 2 - 100), static_cast<float>(GetScreenHeight() / 2 - 20) };
    DrawTextEx(font, "Country selection not implemented yet.", position, 24, 1, DARKGRAY);

    // Suppress warning C4100: 'p': parametro senza riferimenti
    (void)p;
}
