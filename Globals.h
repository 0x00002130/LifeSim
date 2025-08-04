#pragma once
#include "raylib.h"
#include "iostream"
#include "Random.h"
#include "json.hpp"
#include "vector"
#include "fstream"

// WINDOW CONTROL
#define SCREENWIDTH 800
#define SCREENHEIGHT 600
#define TARGET_FPS 60

// FONT
extern Font font;

// SWITCH GAME SCREEN
enum GameScreen {
    SCREEN_EXIT,
    SCREEN_START_MENU,
    SCREEN_CREATE_PLAYER,
    SCREEN_LOAD,
    SCREEN_SETTINGS,
    SCREEN_COUNTRY_SELECT,
	SCREEN_SIGN_SELECT,
    SCREEN_INTERFACE
};

// STRUCT FOR CREATING BUTTONS
struct Button {
    Rectangle bounds{};
    Color color{};
    std::string text{};
    Color textColor{};
};

// STRUCT FOR CREATING A TEXT BOX
struct TextBox {
    Rectangle bounds;
    std::string text;
    float fontSize = 20;
    float spacing = 1.0f;
    Color boxColor = LIGHTGRAY;
    Color borderColor = BLACK;
    Color textColor = BLACK;
    bool active = false;
    int maxLength = 64;
};

// LOAD JSON FILES
std::vector<std::string> LoadCountriesFromJson(const std::string& filename);                                                           // LOAD COUNTRIES FROM JSON FILE


// LOAD SOUNDS
Sound LoadSoundFromFile(const std::string& filename);                                                                                 // LOAD SOUND FROM FILE

// HELPFUL FUNCTIONS
bool IsButtonClicked(Button& btn);                                                                                        // CHECK IF BUTTON IS CLICKED
Vector2 GetTextSize(const std::string& text, float fontSize = 20, float spacing = 1);                                    // GET THE SIZE OF A TEXT
void DrawTextCentered(const std::string& text, Rectangle bounds, float fontSize, Color color, float spacing = 1);       // DRAW A CENTERED TEXT IN A RECTANGLE
void DrawButton(const Button& button);                                                                                  // DRAW RECT WITH DrawTextCentered()
bool IsTextBoxActive(TextBox& tb);                                                                                      // CHECK IF THE BUTTON IS CLICKED ON THE TEXTBOX
void UpdateTextBox(TextBox& tb);                                                                                        // MANAGE THE TEXTBOX INPUT
void DrawTextBox(const TextBox& tb);                                                                                    // DRAW THE TEXTBOX ON SCREEN
const std::string& GetTextBoxContent(const TextBox& tb);
bool IsTextBoxConfirmed(const TextBox& tb);