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
	char spaces[9];
	int  scores[9];
	int  currentBestPosition;
	int  currentBestScore;

	cout << Player::getName() << " is thinking...\n";
	Sleep(((float)rand()/(float)RAND_MAX)*5000 + 1000);

	// Old Bot AI here.
	/*
	srand((unsigned) time(0));
	board->getSpaces(spaces);
	do
	{
		choice = ((float)rand()/(float)RAND_MAX)*9 + 1;
	}
	while(spaces[choice-1] != '-');
	*/

	board->getSpaces(spaces);
	currentBestPosition = 1;
	currentBestScore    = INT_MIN;

	for(int i=0; i < 9; i++)
	{
		if(spaces[i] == '-')
		{
			// Set fourth parameter (depth) = -1 to explore entire state space.
			scores[i] = considerBoard(board, i+1, true, 2);
			cout << "POS: " << (i+1) << ", SCORE: " << scores[i] << endl;
		}
		else
		{
			scores[i] = INT_MIN;
		}

		if(scores[i] > currentBestScore)
		{
			currentBestScore    = scores[i];
			currentBestPosition = i+1;
		}
	}

	return currentBestPosition;
}

int AIPlayer::considerBoard(Board* board, int position, bool self,
	int depth)const
{
	Board*    consideredBoard;
	PLAY_MARK opponentMark;
	bool      gameOver;
	Player*   winningPlayer;
	char      spaces[9];
	int       gameScore;

	// Set consideredBoard to the same state as board
	board->getSpaces(spaces);
	consideredBoard = new Board(board->players);
	for(int i=0; i < 9; i++)
	{
		if(spaces[i] == NOUGHTS)
		{
			consideredBoard->updateBoard(i+1, NOUGHTS);
		}
		else if(spaces[i] == CROSSES)
		{
			consideredBoard->updateBoard(i+1, CROSSES);
		}
	}

	playMark == NOUGHTS ? opponentMark = CROSSES : opponentMark = NOUGHTS;
	consideredBoard->updateBoard(position, (self ? playMark : opponentMark));

	cout << "Considering board if " << (self ? "BOT " : "OPPONENT ");
	cout << "plays on position " << position << endl;

	consideredBoard->displayBoard();

	getchar();

	winningPlayer = 0;
	gameOver = consideredBoard->checkGameOver(winningPlayer);
	// Endgame state - the AI either won or lost the game (base case).
	if(gameOver && winningPlayer)
	{
		if(winningPlayer == this)
		{
			cout << "WIN!\n";
			getchar();
			return 1;
		}
		else
		{
			cout << "LOSS!\n";
			getchar();
			return -1;
		}
	}
	// Endgame state - the AI and opponent tied (base case).
	else if (gameOver)
	{
		cout << "TIE!\n";
		getchar();
		return 0;
	}
	// Maximum recursion depth reached (base case).
	else if (!depth)
	{
		return 0;
	}
	// Intermediate state - recurse.
	else
	{
		cout << "Within considerBoard() recursing!\n";
		// Update spaces to reflect state of consideredBoard.
		consideredBoard->getSpaces(spaces);
		gameScore = 0;

		// Assume, in turn, that the considered player (AI or its opponent)
		// plays on each valid position.
		//
		// If the player made a particular move, how would that affect
		// the AI's chances of winning?
		//
		// If the currently considered player is the AI itself, increment
		// gameScore for each scenario that derives from the hypothetical
		// one that ends in victory.
		//
		// If the currently considered player is the opponent, decrement
		// instead.
		for(int i=0; i < 9; i++)
		{
			if(spaces[i] == '-')
			{
				gameScore += considerBoard(consideredBoard, i+1, !self, depth-1);
			}
		}

		return gameScore;
	}

}
