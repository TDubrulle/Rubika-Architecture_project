#pragma once
#include "Move.h"
class MoveLeft :
	public Move
{
protected:
	bool doAction(Character *c) override;
public:
	~MoveLeft();

};

