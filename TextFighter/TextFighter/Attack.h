#pragma once
#include "SimpleCharacterState.h"
class Attack :
	public SimpleCharacterState
{
protected:
	bool done;
	float damages;
public:
	Attack(float damages);
	~Attack();

	bool doAction(Character *c) override;
};

