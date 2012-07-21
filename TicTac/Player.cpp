// ======================================================
// Player.cpp by Tag.
// ======================================================

#include "Player.h"

Player::Player(string name, PLAY_MARK playMark)
{
	this->name      = name;
	this->playStyle = playMark;
}

string Player::getName()const
{
	return name;
}