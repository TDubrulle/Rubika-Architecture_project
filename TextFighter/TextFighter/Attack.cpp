#include "stdafx.h"
#include "Attack.h"
#include "Character.h"

Attack::Attack(float damages)
{
	this->damages = damages;
}

Attack::~Attack()
{
}

bool Attack::doAction(Character *c) {
	c->attack(damages);
	return true;
}
