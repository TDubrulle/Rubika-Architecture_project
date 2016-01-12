#pragma once
#include "SimpleCharacterState.h"
class Block :
	public SimpleCharacterState
{
protected:
	float damageMult;
public:
	Block(float damageMult);
	~Block();

	bool doAction(Character *c) override;
	
};

