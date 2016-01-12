#include "stdafx.h"
#include "Idle.h"
#include "Character.h"



Idle::~Idle()
{
}


bool Idle::doAction(Character *c)
{
	c->idle();
	return true;
}


