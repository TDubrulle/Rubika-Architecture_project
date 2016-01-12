#include "stdafx.h"
#include "MoveRight.h"
#include "Character.h"


MoveRight::~MoveRight()
{
}

bool MoveRight::doAction(Character *c)
{
	c->moveRight();
	return true;
}
