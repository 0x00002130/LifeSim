#include "CreatePlayer.h"

void CreatePlayer::ForgePlayer(Player& p)
{
    float boxWidth = 300;
    float boxHeight = 50;
    float spacing = 30;
    float numBoxes = 2; // Nome e Cognome

    float boxX = (GetScreenWidth() - boxWidth) / 2;
    float boxY = (GetScreenHeight() - (boxHeight * numBoxes + spacing * (numBoxes - 1))) / 2;

    static int activeBox = 0; // 0 = name, 1 = surname
    static bool showError = false;
    static int errorTimer = 0;
    const int errorDuration = 120; // frame (2 secondi a 60fps)

    // Casella per il nome
    static TextBox boxName = { Rectangle{boxX, boxY, boxWidth, boxHeight}, "" };
    boxName.fontSize = 24;
    boxName.boxColor = LIGHTGRAY;
    boxName.borderColor = DARKGRAY;
    boxName.textColor = BLACK;
    boxName.spacing = 1.0f;
    boxName.maxLength = 32;

    // Casella per il cognome
    static TextBox boxSurname = { Rectangle{boxX, boxY + boxHeight + spacing, boxWidth, boxHeight}, "" };
    boxSurname.fontSize = 24;
    boxSurname.boxColor = LIGHTGRAY;
    boxSurname.borderColor = DARKGRAY;
    boxSurname.textColor = BLACK;
    boxSurname.spacing = 1.0f;
    boxSurname.maxLength = 32;

    // Imposta il box attivo
    boxName.active = (activeBox == 0);
    boxSurname.active = (activeBox == 1);

    // Cambia focus con TAB
    if (IsKeyPressed(KEY_TAB)) {
        activeBox = (activeBox + 1) % 2;
    }

    // Gestione caselle
    IsTextBoxActive(boxName);
    UpdateTextBox(boxName);
    IsTextBoxActive(boxSurname);
    UpdateTextBox(boxSurname);

    // Validazione e feedback visivo
    std::string name = GetTextBoxContent(boxName);
    std::string surname = GetTextBoxContent(boxSurname);

    // Reset colori bordo
    boxName.borderColor = DARKGRAY;
    boxSurname.borderColor = DARKGRAY;

    // Conferma entrambi i campi con Invio solo se non sono vuoti
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
        }
    }

    // Etichette sopra le caselle, centrate orizzontalmente
    Vector2 labelNameSize = MeasureTextEx(font, "Nome", 24, 1);
    Vector2 labelNamePos = { boxX + (boxWidth - labelNameSize.x) / 2, boxY - labelNameSize.y - 6 };
    DrawTextEx(font, "Nome", labelNamePos, 24, 1, DARKGRAY);

    Vector2 labelSurnameSize = MeasureTextEx(font, "Cognome", 24, 1);
    Vector2 labelSurnamePos = { boxX + (boxWidth - labelSurnameSize.x) / 2, boxY + boxHeight + spacing - labelSurnameSize.y - 6 };
    DrawTextEx(font, "Cognome", labelSurnamePos, 24, 1, DARKGRAY);

    // Disegna le caselle con il colore corretto
    DrawTextBox(boxName);
    DrawTextBox(boxSurname);

    // DA VEDERE
    // Mostra messaggio di errore se necessario
    if (showError) {
		Vector2 positionText = { boxX + boxWidth / 2, boxY + boxHeight * 2 + spacing };
        DrawTextEx(font, "Compila tutti i campi!", positionText, 24, 1, RED);
        if (--errorTimer <= 0) showError = false;
    }
}
