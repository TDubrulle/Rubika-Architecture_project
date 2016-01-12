#include "stdafx.h"
#include "Character.h"

#include "TextualCharacterView.h"
//TTODO: remove this dependency to Match.cpp
#include "Match.h"

Character::Character(std::string name, float life)
{
	this->name = name;
	this->life = life;
	this->characterView = new TextualCharacterView(this);
}

Character::Character(std::string name, float life, CharacterView *characterView)
{
	this->name = name;
	this->life = life;
	this->characterView = characterView;
}

Character::~Character()
{
	delete currentState;
}

float Character::getLife()
{
	return life;
}

std::string Character::getName()
{
	return name;
}

void Character::attack(float amount)
{
	characterView->playAttack();
	curMatch->getOtherPlayer(this)->damage(amount);
}

void Character::jump()
{
	characterView->playJump();
}

void Character::moveLeft()
{
	characterView->playMoveLeft();
}

void Character::moveRight()
{
	characterView->playMoveRight();
}

void Character::idle()
{
	characterView->playIdle();
}


void Character::damage(float amount)
{
	life -= amount;
	characterView->playDamage(amount);
	notifyObservers();
}

void Character::update()
{
	currentState = currentState->playState(this);
}

CharacterState * Character::getCurrentState()
{
	return currentState;
}

void Character::setCurrentState(CharacterState * curState)
{
	currentState = curState;
}

void Character::setCurMatch(Match *curMatch)
{
	this->curMatch = curMatch;
}
