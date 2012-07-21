// ======================================================
// HumanPlayer.h by Tag.
//
// A type of player that is controlled by a human being
// by accepting input from the keyboard.
// ======================================================

#include "TicTacUtil.h"
#include "Player.h"

class HumanPlayer : public Player
{
public:
	HumanPlayer(string name, PLAY_STYLE playStyle);
	~HumanPlayer();

	int getChoice(Board* board)const;
	string getName()const;
};