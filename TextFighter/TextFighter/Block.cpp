#include "stdafx.h"
#include "Block.h"
#include "Character.h"

Block::Block(float damageMult)
{
	this->damageMult = damageMult;
}

Block::~Block()
{
}

bool Block::doAction(Character *c) {
	if (isTriggered()) {
		c->setBlockDamageMultiplier(damageMult);
		return false;
	}
	else {
		c->resetBlockDamageMultiplier();
		return true;
	}
}

