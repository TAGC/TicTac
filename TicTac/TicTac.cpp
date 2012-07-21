// ======================================================
// TicTac.cpp by Tag.
// ======================================================

#include "TicTac.h"

TicTac::TicTac()
:board(0)
{	
	setGameMode();
	setupBoard();

	while(!board->checkGameOver())
	{
		// Do game stuff.
		board->nextTurn();
		board->displayBoard();
	}
}

// Selects for single player or multiplayer mode.
void TicTac::setGameMode()
{
	cout << "Would you like play AI-only, single player or multiplayer? "
		 << "A/S/M\n";
	while(true)
	{
		cin >> confirm;

		if(confirm == 'A' || confirm == 'a')
		{
			cout << "\nAI-only mode selected.\n";
			numHumanPlayers = 1;
			break;
		}
		else if(confirm == 'S' || confirm == 's')
		{
			cout << "\nSingle player mode selected.\n";
			numHumanPlayers = 1;
			break;
		}
		else if(confirm == 'M' || confirm == 'm')
		{
			cout << "\nMultiplayer mode selected.\n";
			numHumanPlayers = 2;
			break;
		}
		else
		{
			cout << "\nUnrecognised response. Please select game mode S/M: ";
		}
	}
}

// Queries human player's names, creates Player instances and
// initialises the board.
void TicTac::setupBoard()
{
	string name;
	PLAY_MARK playMark;

	for(int i = 0; i < numHumanPlayers; i++)
	{
		cout << "Player " << i << ", please enter your name: ";

		while(true)
		{
		
			cin >> name;
			cout << "\nYour name is " << name
				<< ". Is this correct? Y/N\n";
			cin >> confirm;

			if(confirm == 'Y' || confirm == 'y')
			{

				playMark = (i == 0) ? NOUGHTS : CROSSES;
				cout << name << ", you're playing with " << playMark << ".\n";
				HumanPlayer* p = new HumanPlayer(name, playMark);

				players[i] = dynamic_cast<Player*>(p);
				break;
			}
			else if(confirm == 'N' || confirm == 'n')
			{
				cout << "Ok, please re-enter your name: ";
			}
			else
			{
				cout << "Unrecognised response. Please re-enter your name: ";
			}
		}
	}

	for(int i=0; i < 2 - numHumanPlayers; i++)
	{
		name = "BOT-" + (i+1);
		playMark = (i == 1) ? NOUGHTS : CROSSES;
		cout << name << "is playing with " << playMark << ".\n";
		AIPlayer* p = new AIPlayer(name, playMark);
		players[1-i] = dynamic_cast<Player*>(p);
	}

	board = new Board(players);
}