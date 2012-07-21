// ======================================================
// AIPlayer.cpp by Tag.
// ======================================================

#include "AIPlayer.h"

AIPlayer::AIPlayer(string name, PLAY_STYLE playStyle)
:Player(name, playStyle)
{
}

int AIPlayer::getChoice(Board* board)const
{
	cout << "AIPlayer getChoice()const called\n";
	return int(rand()*9 + 1);
}
