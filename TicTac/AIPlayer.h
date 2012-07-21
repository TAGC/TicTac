// ======================================================
// AIPlayer.h by Tag.
//
// A type of player that is controlled by the AI using
// a variant of the minimax algorithm.
// ======================================================

#include "TicTacUtil.h"
#include "Player.h"

class AIPlayer : public Player
{
public:
	AIPlayer(string name, PLAY_STYLE playStyle);
	~AIPlayer();

	int getChoice(Board* board)const;
	string getName()const;
};

