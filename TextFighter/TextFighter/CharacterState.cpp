#include "stdafx.h"
#include "CharacterState.h"
#include "Character.h"
#include "SimpleCharacterState.h"

CharacterState::CharacterState()
{
	warmupTime = -1.0f;
	executionTime = -1.0f;
	cooldownTime = -1.0f;
	possibleSimpleStates = std::vector<CharacterState*>();
	isDefault = true;
}


CharacterState::~CharacterState()
{
	//TTODO
}

CharacterState *CharacterState::playState(Character *character)
{
	/*TTODO:
	if(curWarmUpTime > warmUpTime && !actionDone) doAction();
	if(curExecutionTime < executionTime) {
		return false;
	} else {
		return true;
	}*/

	if (doAction(character)) {
		return getNextState();
	}

	return this;
}


void CharacterState::addPossibleState(CharacterState *newState) {
	possibleSimpleStates.push_back(newState);
}

CharacterState *CharacterState::getNextState() {
	CharacterState * newCharacterState = this;
	CharacterState *possibleCharacterState;
	//We check if we have to change the action.
	for (unsigned int i = 0; i < possibleSimpleStates.size(); ++i) {
		possibleCharacterState = possibleSimpleStates.at(i);
		if (possibleCharacterState->isDefaultState() && !this->isTriggered()) {
			newCharacterState = possibleCharacterState;
		}
		else if (possibleCharacterState->isTriggered()) {
			return possibleCharacterState;
		}
	}
	return newCharacterState;
}

bool CharacterState::isTriggered()
{
	if (controller) {
		return controller->isMakingAction();
	}
	else {
		return false;
	}
}

bool CharacterState::isDefaultState() {
	return isDefault;
}

std::vector<CharacterState*> CharacterState::getPossibleSimpleStates()
{
	return possibleSimpleStates;
}

void CharacterState::setPossibleStates(std::vector<CharacterState*> newStates)
{
	possibleSimpleStates = newStates;
}


void CharacterState::setController(CharacterStateController * newController) {
	controller = newController;
	if (controller) {
		isDefault = false;
	}
	else {
		isDefault = true;
	}
}

