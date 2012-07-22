// ======================================================
// HumanPlayer.h by Tag.
//
// A type of player that is controlled by a human being
// by accepting input from the keyboard.
// ======================================================

#include "Player.h"
#include "Board.h"

class HumanPlayer : public Player
{
public:
	HumanPlayer(string name, PLAY_MARK playMark);
	~HumanPlayer();

	int getChoice(Board* board)const;
	string getName()const;
};