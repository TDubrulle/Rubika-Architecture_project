#pragma once
#include <vector>
#include "CharacterStateController.h"
//Forward declaration to circumvent circular dependency.
class Character;
class SimpleCharacterState;
class CharacterStateDecorator;

/**The characterState interface is an interface that rules the Character actions.
@Author Thomas Dubrulle*/
class CharacterState
{
protected:
	/*Values for time*/
	/**Time to start the action*/
	float warmupTime;
	/**Time to execute the action*/
	float executionTime;
	/**Time between each action. A positive value will prevent this action from being played twice consecutively*/
	float cooldownTime;

	CharacterStateController *controller;
	/**Tell if the state is a default state, i.e. a state that doesn't need to be triggered to come back to it.*/
	bool isDefault;

	/**possible simple states that cannot be simultaneous with other simple states.*/
	std::vector<CharacterState*> possibleSimpleStates;

	/**Do the action of the state. Extending classes should implement this method to perform the actions linked to the class they're making.
	@return bool true if the state has been finished, false if it isn't.*/
	virtual bool doAction(Character * character) = 0;
public:
	/**Create a characterState. It will not have any cooldown or time to execute. It will also not have any state to switch on once finished.
	It will not change state if it is still being triggered.
	Finally, it will be considered as a default state: all states that can go to this state will go to it when all other states are checked.*/
	CharacterState();


	~CharacterState();
	/**Play this state. It will perform the action linked to the characterState if it is currently doable.
	@return CharacterState* the new characterState if the character state changed, otherwise this characterState.*/
	CharacterState *playState(Character *character);

	void addPossibleState(CharacterState * newState);
	/**Check if this action has been triggered*/
	bool isTriggered();
	/**Check if this action is a default state*/
	bool isDefaultState();
	/**Get possible simple states that cannot be simultaneous with other simple states.*/
	std::vector<CharacterState*> getPossibleSimpleStates();

	CharacterState *CharacterState::getNextState();

	/**set possible simple states that cannot be simultaneous with other simple states.*/
	void setPossibleStates(std::vector<CharacterState*>);

	void setController(CharacterStateController * newController);
};