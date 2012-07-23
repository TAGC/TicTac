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

	
	for(int j=0; j < 9; j++)
	{
		spaces[j] = '-';
	}

	setCurrentPlayer(players[0]);
}

Board::~Board()
{
	delete[] players;
	delete[] spaces;
	currentPlayer = NULL;
}

// Returns whether the game is over and the winning player.
bool Board::checkGameOver(Player *& winningPlayerOut)const
{
	for(int i=0; i < 3; i++)
	{
		// Check for horizontal line win.

		if(spaces[i*3] == spaces[i*3+1] && spaces[i*3] == spaces[i*3+2])
		{
			switch(spaces[i*3])
			{
			case NOUGHTS:
				winningPlayerOut = players[0];
				return true;
			case CROSSES:
				winningPlayerOut = players[1];
				return true;
			}
		}

		// Check for vertical line win.
		else if(spaces[i] == spaces[3+i] && spaces[i] == spaces[6+i])
		{
			switch(spaces[i])
			{
			case NOUGHTS:
				winningPlayerOut = players[0];
				return true;
			case CROSSES:
				winningPlayerOut = players[1];
				return true;
			}
		}
	}

	// Check for diagonal line win.
	if((spaces[0] == spaces[4] && spaces[0] == spaces[8]) || 
	   (spaces[2] == spaces[4] && spaces[2] == spaces[6]))
	{
		switch(spaces[4])
		{
		case NOUGHTS:
			winningPlayerOut = players[0];
			return true;
		case CROSSES:
			winningPlayerOut = players[1];
			return true;
		}
	}

	for(int j=0; j < 9; j++)
	{
		if(spaces[j] == '-')
		{
			winningPlayerOut = 0;
			return false;
		}
	}

	winningPlayerOut = 0;
	return true;
}

// Finds the winning player (if one) and declares them the winner.
bool Board::checkGameOver()const
{
	Player* winningPlayer = 0;
	bool gameOver;

	gameOver = checkGameOver(winningPlayer);
	if(gameOver && winningPlayer)
	{
		declareWinner(winningPlayer);
		return true;
	}
	else if(gameOver)
	{
		declareWinner();
		return true;
	}
	else
	{
		return false;
	}
}

void Board::getSpaces(char emptySpaces[9])const
{
	for(int i=0; i < 9; i++)
	{
		emptySpaces[i] = spaces[i];
	}
}

Player* Board::getCurrentPlayer()const
{
	return currentPlayer;
}

void Board::setCurrentPlayer(Player* player)
{
	currentPlayer = player;
}

// Winner + loser.
void Board::declareWinner(Player* player)const
{
	string winnerName = player->getName();
	cout << winnerName << " wins the game!\n";
}

// Tie.
void Board::declareWinner()const
{
	cout << "Tie! Neither player wins.\n";
}

//PRE: position is a valid position on the board (1-9).
void Board::updateBoard(int position, PLAY_MARK playMark)
{
	spaces[position-1] = playMark;
}

void Board::nextTurn()
{
	promptMove();

	// Switch current player.
	if(players[0] == getCurrentPlayer())
	{
		setCurrentPlayer(players[1]);
	}
	else
	{
		setCurrentPlayer(players[0]);
	}
}

void Board::promptMove()
{
	int choice;

	string name = getCurrentPlayer()->getName();
	cout << "Current player: " << name << "\n";

	//POST: choice is valid and corresponding position is available.
	choice = getCurrentPlayer()->getChoice(this);
	updateBoard(choice, currentPlayer == players[0] ? NOUGHTS : CROSSES);
}

void Board::displayBoard()const
{
	cout << endl;
	for(int i = 0; i < 3; i++)
	{
		cout << spaces[i*3] << " " << spaces[i*3+1] << " " << spaces[i*3+2] << endl;
	}
	cout << endl;
}