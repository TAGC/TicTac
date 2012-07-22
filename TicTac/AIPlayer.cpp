// ======================================================
// AIPlayer.cpp by Tag.
// ======================================================

#include "AIPlayer.h"

AIPlayer::AIPlayer(string name, PLAY_MARK playMark)
:Player(name, playMark)
{
}

AIPlayer::~AIPlayer()
{
}

int AIPlayer::getChoice(Board* board)const
{
	int choice;
	char spaces[9];

	cout << Player::getName() << " is thinking...\n";
	Sleep(((float)rand()/(float)RAND_MAX)*5000 + 1000);

	srand((unsigned) time(0));
	board->getSpaces(spaces);
	do
	{
		choice = ((float)rand()/(float)RAND_MAX)*9 + 1;
	}
	while(spaces[choice-1] != '-');
	return choice;
}
