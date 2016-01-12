#include "stdafx.h"
#include "Jump.h"
#include "Character.h"


Jump::~Jump()
{
}

bool Jump::doAction(Character *c)
{
	c->jump();
	return true;
}
