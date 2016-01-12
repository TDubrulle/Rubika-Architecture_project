#pragma once
#include "Character.h"
class CharacterView
{
protected:
	Character *character;
public:
	CharacterView(Character * character);
	virtual void playAttack() = 0;
	virtual void playDamage(float amount) = 0;
	virtual void playJump() = 0;
	virtual void playMoveLeft() = 0;
	virtual void playMoveRight() = 0;
	virtual void playIdle() = 0;
};

