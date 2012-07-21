// ======================================================
// HumanPlayer.cpp by Tag.
// ======================================================

#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(string name, PLAY_MARK playMark)
:Player(name, playMark)
{
}

int HumanPlayer::getChoice(Board* board)const
{
	const char* strChoice;
	int         choice;
	char        spaces[9];
	
	// Load the state of the board into spaces.
	board->getSpaces(spaces);

	cout << getName();
	cout << ", please select a position to play (1-9).\n";
	cin >> choice;
	choice = atoi(strChoice);
	
	while(!isdigit(choice) || !(1 <= choice <= 9) || spaces[choice-1] != '-')
	{
		cout << "That is an invalid position, please try again: \n";
		cin >> choice;
		choice = atoi(strChoice);
	}

	return choice;
}