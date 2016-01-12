#pragma once
#include <string>
#include "Observable.h"
#include <vector>
#include "SimpleCharacterState.h"

class CharacterState;
class CharacterView;
//TTODO: remove this dependency to Match.cpp
class Match;
/**Character is a class that represents a character.
	A character is determined by its status (life, name...) and an action state.
	The action state tells what the character is doing.
	@Author Thomas Dubrulle*/
class Character : public Observable
{
protected:
	/**Current life.*/
	float life = 0.0f;
	/**Current name.*/
	std::string name = "";
	/**CharacterView*/
	CharacterView *characterView;
	/**Current action.*/
	CharacterState * currentState;
	//TTODO: remove this dependency to Match.cpp
	Match *curMatch;
public:
	Character(std::string name, float life);
	Character(std::string name, float life, CharacterView *characterView);
	~Character();
	/**Return the character's current life.*/
	float getLife();
	/**Return the character's name*/
	std::string getName();

	/**Make the player attack*/
	void attack(float amount);
	/**Damage this player by a certain amount.*/
	void damage(float amount);
	/**Make the player jump*/
	void jump();
	/**Make the player move left*/
	void moveLeft();
	/**Make the player move right*/
	void moveRight();
	/**Make the player do nothing.*/
	void idle();
	/**Update the player's state once.*/
	void update();
	/**Return the player's current State.*/
	CharacterState *getCurrentState();
	/**set the player's current State.*/
	void setCurrentState(CharacterState *state);
	/**set the player's current match.*/
	void setCurMatch(Match *curMatch);
};