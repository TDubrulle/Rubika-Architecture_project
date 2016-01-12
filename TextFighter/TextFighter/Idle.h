#pragma once
#include "SimpleCharacterState.h"
class Idle :
	public SimpleCharacterState
{
protected:
	bool doAction(Character *c) override;
public:
	~Idle();

};

