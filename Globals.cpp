#include "Globals.h"

bool IsButtonClicked(Button& btn)
{
    Vector2 mouse = GetMousePosition();
    return CheckCollisionPointRec(mouse, btn.bounds) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

Vector2 GetTextSize(const std::string& text, float fontSize, float spacing) {
    return MeasureTextEx(font, text.c_str(), fontSize, spacing);
}

void DrawTextCentered(const std::string& text, Rectangle bounds, float fontSize, Color color, float spacing) {
    Vector2 textSize = MeasureTextEx(font, text.c_str(), fontSize, spacing);
    Vector2 position = {
        bounds.x + (bounds.width - textSize.x) / 2,
        bounds.y + (bounds.height - textSize.y) / 2
    };
    DrawTextEx(font, text.c_str(), position, fontSize, spacing, color);
}

void DrawButton(const Button& button)
{
    DrawRectangleRec(button.bounds, button.color);
    DrawTextCentered(button.text, button.bounds, 20, button.textColor);
}

bool IsTextBoxActive(TextBox& tb) {
    if (tb.active) return true;
    if (CheckCollisionPointRec(GetMousePosition(), tb.bounds) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        tb.active = true;
        return true;
    }
    return false;
}

void UpdateTextBox(TextBox& tb) {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
        !CheckCollisionPointRec(GetMousePosition(), tb.bounds)) {
        tb.active = false;
    }

    if (tb.active) {
        int key = GetCharPressed();
        while (key > 0) {
            if ((key >= 32) && (key <= 125) && ((int)tb.text.size() < tb.maxLength)) {
                tb.text += (char)key;
            }
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE) && !tb.text.empty()) {
            tb.text.pop_back();
        }
    }
}

void DrawTextBox(const TextBox& tb) {
    DrawRectangleRec(tb.bounds, tb.active ? tb.boxColor : Fade(tb.boxColor, 0.5f));
    DrawRectangleLinesEx(tb.bounds, 2, tb.borderColor);
    DrawTextCentered(tb.text, tb.bounds, tb.fontSize, tb.textColor, tb.spacing);
}

const std::string& GetTextBoxContent(const TextBox& tb) {
    return tb.text;
}

bool IsTextBoxConfirmed(const TextBox& tb) {
    return tb.active && IsKeyPressed(KEY_ENTER);
}

std::vector<std::string> LoadCountriesFromJson(const std::string& filename) {
    std::vector<std::string> countries;
    try {
        std::ifstream file(filename);
        if (!file.is_open()) {
            TraceLog(LOG_ERROR, TextFormat("Impossible to open file: %s", filename.c_str()));
            return countries;
        }
        nlohmann::json j;
        file >> j;
        countries = j.get<std::vector<std::string>>();
    }
    catch (const std::exception& e) {
        TraceLog(LOG_ERROR, TextFormat("Error in parsing JSON: %s", e.what()));
    }
    return countries;
}