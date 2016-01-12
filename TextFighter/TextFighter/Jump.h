#pragma once
#include "SimpleCharacterState.h"
class Jump :
	public SimpleCharacterState
{
protected:
	bool doAction(Character *c) override;
public:
	~Jump();
};

