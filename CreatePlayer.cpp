#include "CreatePlayer.h"

void CreatePlayer::ForgePlayer(Player& p)
{
	static TextBox tb = { Rectangle{100, 100, 300, 40}, "" };
	tb.fontSize = 24;
	tb.boxColor = LIGHTGRAY;
	tb.borderColor = DARKGRAY;
	tb.textColor = BLACK;
	tb.spacing = 1.0f;
	tb.maxLength = 32;

	IsTextBoxActive(tb);
	UpdateTextBox(tb);
	DrawTextBox(tb);
	if (IsTextBoxConfirmed(tb)) {
		p.SetName(GetTextBoxContent(tb));
		tb.active = false;
		TraceLog(LOG_INFO, TextFormat("Player name confirmed: %s", p.GetName().c_str()));
	}
}
