#pragma once
#include "Move.h"
class MoveRight :
	public Move
{
protected:
	bool doAction(Character *c) override;
public:
	~MoveRight();

};

