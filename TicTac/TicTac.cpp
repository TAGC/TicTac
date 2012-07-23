// ======================================================
// TicTac.cpp by Tag.
// ======================================================

#include "TicTac.h"

TicTac::TicTac()
:board(0)
{	
	setGameMode();
	setupBoard();
}

void TicTac::runGame()
{
	while(!board->checkGameOver())
	{
		// Do game stuff.
		board->nextTurn();
		board->displayBoard();
	}


}

// Selects for AI-only, single player or multiplayer mode.
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
			numHumanPlayers = 0;
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
			cout << "\nUnrecognised response. Please select game mode A/S/M: ";
			cin.ignore(1000, '\n');
		}
	}
}

// Queries human player's names, creates Player instances and
// initialises the board.
void TicTac::setupBoard()
{
	string name;
	char   cName[2];
	PLAY_MARK playMark;

	for(int i = 0; i < numHumanPlayers; i++)
	{
		cout << "Player " << (i+1) << ", please enter your name: ";

		while(true)
		{
		
			cin >> name;
			cout << "\nYour name is " << name
				<< ". Is this correct? Y/N\n";
			cin >> confirm;

			if(confirm == 'Y' || confirm == 'y')
			{

				playMark = (i == 0) ? NOUGHTS : CROSSES;
				cout << name << ", you're playing using ";
				cout << (char)(playMark) << "'s.\n\n";
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
		playMark = ((numHumanPlayers + i) == 1) ? CROSSES : NOUGHTS;
		name = "BOT-" + string(itoa(i+1, cName, 10));
		cout << name << " is playing using " << (char)playMark << "'s.\n\n";
		AIPlayer* p = new AIPlayer(name, playMark);
		players[numHumanPlayers+i] = dynamic_cast<Player*>(p);
	}

	cout << "Player 1: " << players[0]->getName() << endl;
	cout << "Player 2: " << players[1]->getName() << endl;

	board = new Board(players);
	board->displayBoard();
}

int main(int argc, char* argv)
{

	TicTac* game = new TicTac();
	game->runGame();
	cout << endl;
	system("PAUSE");

	return 0;
}