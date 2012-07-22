// ======================================================
// HumanPlayer.cpp by Tag.
// ======================================================

#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(string name, PLAY_MARK playMark)
:Player(name, playMark)
{
}

HumanPlayer::~HumanPlayer()
{
}

int HumanPlayer::getChoice(Board* board)const
{
	string input;
	const char* strChoice;
	int         choice;
	char        spaces[9];
	
	// Load the state of the board into spaces.
	board->getSpaces(spaces);

	cout << Player::getName();
	cout << ", please select a position to play (1-9).\n";
	cin >> input;
	strChoice = input.c_str();
	choice = atoi(strChoice);

	while(!isdigit(strChoice[0]) || !(1 <= choice && choice <= 9) 
		|| spaces[choice-1] != '-')
	{
		cout << "That is an invalid position, please try again: \n";
		cin >> input;
		strChoice = input.c_str();
		choice = atoi(strChoice); 
	}

	return choice;	
}