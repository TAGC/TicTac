// ======================================================
// AIPlayer.h by Tag.
//
// A type of player that is controlled by the AI using
// a variant of the minimax algorithm.
// ======================================================

#include "Player.h"
#include "Board.h"

class AIPlayer : public Player
{
public:
	AIPlayer(string name, PLAY_MARK playMark);
	~AIPlayer();

	int getChoice(Board* board)const;
	string getName()const;

private:
	int considerBoard(Board* board, int position, bool self,
		int currDepth, int maxDepth)const;
};

