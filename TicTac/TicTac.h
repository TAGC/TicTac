// ======================================================
// TicTac.h by Tag.
// 
// Creates a board and two player instances. Asks
// player / AI to pick a board position and updates the
// board until an endgame state is reached.
// ======================================================

#include "TicTacUtil.h"
#include "Board.h"
#include "AIPlayer.h"
#include "HumanPlayer.h"


class TicTac
{
public:
	TicTac();
	~TicTac();

	void setGameMode();
	void setupBoard();
	void runGame();

private:
	Board*  board;
	Player* players[2];
	int     numHumanPlayers;
	string  response;
	char    confirm;
};