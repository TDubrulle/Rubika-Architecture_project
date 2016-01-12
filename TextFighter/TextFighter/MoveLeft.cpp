#include "stdafx.h"
#include "MoveLeft.h"
#include "Character.h"



MoveLeft::~MoveLeft()
{
}

bool MoveLeft::doAction(Character *c)
{
	c->moveLeft();
	return true;
}