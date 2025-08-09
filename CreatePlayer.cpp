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
    
	// Button countrySelect positioned down Name and Surname;
	countryButton.bounds = { Rectangle{ boxX, boxY + boxHeight * 3 + spacing, boxWidth, 40}};
    countryButton.color = BLUE;
    countryButton.text = "Choose Country";
    countryButton.textColor = BLACK;

	DrawButton(countryButton);

	// Button signSelect positioned down the countrySelect button
    signButton.bounds = { Rectangle{ boxX, boxY + boxHeight * 3 + spacing * 3, boxWidth, 40}};
    signButton.color = BLUE;
    signButton.text = "Choose Sign";
    signButton.textColor = BLACK;

	DrawButton(signButton);

	play.bounds = { Rectangle{ boxX, boxY + boxHeight * 3 + spacing * 5, boxWidth, 40} };
    play.color = GOLD;
    play.text = "Play";
	play.textColor = BLACK;

	DrawButton(play);

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

    if (IsButtonClicked(countryButton)) {
        currentScreen = SCREEN_COUNTRY_SELECT; // SET NEXT SCREEN
        TraceLog(LOG_INFO, "Country selection initiated.");
	}

    if (IsButtonClicked(signButton)) {
        currentScreen = SCREEN_SIGN_SELECT; // SET NEXT SCREEN
        TraceLog(LOG_INFO, "Sign selection initiated.");
    }

    // Confirm both fields with Enter only if they are not empty
    if (IsKeyPressed(KEY_ENTER) || IsButtonClicked(play)) {
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
			currentScreen = SCREEN_INTERFACE; // SET NEXT SCREEN
        }
    }


    // Labels above boxes, centered horizontally
    Vector2 labelNameSize = MeasureTextEx(font, "Nome", 24, 1);
    Vector2 labelNamePos = { boxX + (boxWidth - labelNameSize.x) / 2, boxY - labelNameSize.y - 6 };
    DrawTextEx(font, "Name", labelNamePos, 24, 1, WHITE);

    Vector2 labelSurnameSize = MeasureTextEx(font, "Cognome", 24, 1);
    Vector2 labelSurnamePos = { boxX + (boxWidth - labelSurnameSize.x) / 2, boxY + boxHeight + spacing - labelSurnameSize.y - 6 };
    DrawTextEx(font, "Surname", labelSurnamePos, 24, 1, WHITE);

    // -------------------------------------------------
	// Label to press Enter key to confirm
	// Vector2 confirmTextSize = MeasureTextEx(font, "Premi Invio per confermare", 24, 1);
	// Vector2 confirmTextPos = { boxX + (boxWidth - confirmTextSize.x) / 2, boxY + boxHeight * numBoxes + spacing * (numBoxes - 1) + 10 };
	// DrawTextEx(font, "Press Enter to confirm", confirmTextPos, 24, 1, WHITE);
    // -------------------------------------------------
    
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

    static std::vector<std::string> countries = LoadCountriesFromJson("C:\\Users\\marco\\source\\repos\\LifeSim\\assets\\countries_data\\countries.json");
    static int selectedIndex = 0;

    // === SCROLL WITH MOUSE WHEEL ===
    float wheel = GetMouseWheelMove();
    if (wheel < 0) selectedIndex = (selectedIndex + 1) % countries.size();
    if (wheel > 0) selectedIndex = (selectedIndex - 1 + static_cast<int>(countries.size())) % static_cast<int>(countries.size());

    // === SCROLL WITH ARROW KEYS ===
    if (IsKeyPressed(KEY_DOWN)) {
        selectedIndex = (selectedIndex + 1) % countries.size();
    }
    if (IsKeyPressed(KEY_UP)) {
        selectedIndex = (selectedIndex - 1 + static_cast<int>(countries.size())) % static_cast<int>(countries.size());
    }

    // === SELECTION CONFIRM ===
    if (IsKeyPressed(KEY_ENTER)) {
        p.SetNationality(countries[selectedIndex]);
        TraceLog(LOG_INFO, TextFormat("Selected country: %s", p.GetNationality().c_str()));
        currentScreen = SCREEN_CREATE_PLAYER;
    }

    // === VISUALIZATION ===
    float boxWidth = 400;
    float boxHeight = 40;
    float boxX = (GetScreenWidth() - boxWidth) / 2;
    float boxY = (GetScreenHeight() - boxHeight) / 2;

    for (int i = 0; i < 5 && i < countries.size(); ++i) {
        int idx = (selectedIndex + i - 2 + static_cast<int>(countries.size())) % static_cast<int>(countries.size());
        Vector2 pos = { boxX, boxY + (i * boxHeight) };
        Rectangle box = { pos.x, pos.y, boxWidth, boxHeight };

        // === CLICK WITH MOUSE ===
        if (CheckCollisionPointRec(GetMousePosition(), box) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            selectedIndex = idx;
        }

        Color color = (idx == selectedIndex) ? YELLOW : LIGHTGRAY;
        DrawRectangleRec(box, color);
        DrawTextEx(font, countries[idx].c_str(), { pos.x + 10, pos.y + 8 }, 24, 1, BLACK);
    }

    Vector2 infoPos = { boxX, boxY - 50 };
    DrawTextEx(font, "Scroll with mouse wheel or click. Enter to confirm.", infoPos, 24, 1, WHITE);
}



void CreatePlayer::SignSelect(Player& p) {
    ClearBackground(LIME);

    static std::vector<std::string> signs = {
        "Aries", "Taurus", "Gemini", "Cancer", "Leo",
        "Virgo", "Libra", "Scorpio", "Sagittarius",
        "Capricorn", "Aquarius", "Pisces"
    };
    static int selectedIndex = 0;

    // === SCROLL WITH MOUSE WHEEL ===
    float wheel = GetMouseWheelMove();
    if (wheel < 0) selectedIndex = (selectedIndex + 1) % signs.size();
    if (wheel > 0) selectedIndex = (selectedIndex - 1 + static_cast<int>(signs.size())) % static_cast<int>(signs.size());

    // === SCROLL WITH ARROW KEYS ===
    if (IsKeyPressed(KEY_DOWN)) {
        selectedIndex = (selectedIndex + 1) % signs.size();
    }
    if (IsKeyPressed(KEY_UP)) {
        selectedIndex = (selectedIndex - 1 + static_cast<int>(signs.size())) % static_cast<int>(signs.size());
    }

    // === SELECTION CONFIRM ===
    if (IsKeyPressed(KEY_ENTER)) {
        p.SetSign(signs[selectedIndex]);
        TraceLog(LOG_INFO, TextFormat("Selected sign: %s", p.GetSign().c_str()));
        currentScreen = SCREEN_CREATE_PLAYER;
    }

    // === VISUALIZATION ===
    float boxWidth = 400;
    float boxHeight = 40;
    float boxX = (GetScreenWidth() - boxWidth) / 2;
    float boxY = (GetScreenHeight() - boxHeight) / 2;

    for (int i = 0; i < 5 && i < signs.size(); ++i) {
        int idx = (selectedIndex + i - 2 + static_cast<int>(signs.size())) % static_cast<int>(signs.size());
        Vector2 pos = { boxX, boxY + (i * boxHeight) };
        Rectangle box = { pos.x, pos.y, boxWidth, boxHeight };

        // === CLICK WITH MOUSE ===
        if (CheckCollisionPointRec(GetMousePosition(), box) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            selectedIndex = idx;
        }

        Color color = (idx == selectedIndex) ? YELLOW : LIGHTGRAY;
        DrawRectangleRec(box, color);
        DrawTextEx(font, signs[idx].c_str(), { pos.x + 10, pos.y + 8 }, 24, 1, BLACK);
    }

    Vector2 infoPos = { boxX, boxY - 50 };
    DrawTextEx(font, "Scroll with mouse wheel or click. Enter to confirm.", infoPos, 24, 1, WHITE);
}
