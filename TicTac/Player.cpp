// ======================================================
// Player.cpp by Tag.
// ======================================================

#include "Player.h"

Player::Player(string name, PLAY_MARK playMark)
{
	this->name     = name;
	this->playMark = playMark;
}

Player::~Player()
{
}

string Player::getName()const
{
	return name;
}