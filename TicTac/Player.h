// ======================================================
// Player.h by Tag.
//
// The player is able to place noughts or crosses on free
// spaces on a board during their turn with that board.
// ======================================================

#ifndef PLAYER_H
#define PLAYER_H

#include "TicTacUtil.h"
#include "Board.h"

class Player
{
public:
	Player(string name, PLAY_STYLE playStyle);
	virtual ~Player();

	virtual int getChoice(Board* board)const = 0;
	string getName()const;

protected:
	string name;
	PLAY_STYLE playStyle;
};

#endif