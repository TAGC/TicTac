// ======================================================
// Board.h by Tag.
//
// A tictac board with 9 spaces that can be filled with
// noughts or crosses by each player in turn.
// ======================================================

#ifndef BOARD_H
#define BOARD_H

#include "TicTacUtil.h"
#include "Player.h"

class Board
{
public:
	Board(Player* players[2]);
	~Board();

	void nextTurn();
	Player* getCurrentPlayer()const;
	void    getSpaces(char[9]);
	bool    checkGameOver()const;
	void    displayBoard()const;

private:
	void    setCurrentPlayer(Player* player);
	void    declareWinner(Player* player)const;
	void    updateBoard(int position, PLAY_MARK playMark);

private:
	char    spaces[9];
	Player* players[2];
	Player* currentPlayer;
};

#endif