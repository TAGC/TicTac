// ======================================================
// Board.cpp by Tag.
// ======================================================

#include "Board.h"

Board::Board(Player* players[2])
{
	for(int i=0; i < 2; i++)
	{
		this->players[i] = players[i];
	}

	currentPlayer = players[0];

	for(int j=0; j < 9; j++)
	{
		spaces[j] = '-';
	}
}

Board::~Board()
{
	delete players;
	delete spaces;
	currentPlayer = NULL;
}

bool Board::checkGameOver()const
{
	for(int i=0; i < 3; i++)
	{
		// Test to see if chaining == operator works!

		// Check for horizontal line win.
		if(spaces[i*3] == spaces[i*3+1] == spaces[i*3+2])
		{
			switch(spaces[i*3])
			{
			case NOUGHTS:
				declareWinner(players[0]);
				return true;
			case CROSSES:
				declareWinner(players[1]);
				return true;
			}
		}

		// Check for vertical line win.
		else if(spaces[i] == spaces[3+i] == spaces[6+i])
		{
			switch(spaces[i])
			{
			case NOUGHTS:
				declareWinner(players[0]);
				return true;
			case CROSSES:
				declareWinner(players[1]);
				return true;
			}
		}
	}

	// Check for diagonal line win.
	if((spaces[0] == spaces[4] == spaces[8]) || 
	   (spaces[2] == spaces[4] == spaces[6]))
	{
		switch(spaces[4])
		{
		case NOUGHTS:
			declareWinner(players[0]);
			return true;
		case CROSSES:
			declareWinner(players[1]);
			return true;
		}
	}

	return false;
}

void Board::getSpaces(char emptySpaces[9])
{
	emptySpaces = spaces;
}

Player* Board::getCurrentPlayer()const
{
	return currentPlayer;
}

void Board::setCurrentPlayer(Player* player)
{
	currentPlayer = player;
}

void Board::declareWinner(Player* player)const
{
	string winnerName = player->getName();
	cout << winnerName << " wins the game!\n";
}

//PRE: position is a valid position on the board (1-9).
void Board::updateBoard(int position, PLAY_MARK playMark)
{
	spaces[position-1] = playMark;
}

void Board::nextTurn()
{
	int choice;

	// Switch current player.
	if(players[0] == getCurrentPlayer())
	{
		setCurrentPlayer(players[1]);
	}
	else
	{
		setCurrentPlayer(players[0]);
	}

	string name = getCurrentPlayer()->getName();
	cout << "Current player: " << name << "\n";

	//POST: choice is valid and corresponding position is available.
	choice = getCurrentPlayer()->getChoice(this);
	updateBoard(choice, currentPlayer == players[0] ? NOUGHTS : CROSSES);
}

void Board::displayBoard()const
{
	cout << "\n";
	for(int i = 0; i < 2; i++)
	{
		cout << spaces[i*3] << " " << spaces[i*3+1] << " " << spaces[i*3+2] << "\n";
	}
}