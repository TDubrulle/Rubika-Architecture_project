#include "stdafx.h"
#include "KeyboardCharacterStateController.h"

KeyboardCharacterStateController::KeyboardCharacterStateController(sf::Keyboard::Key keyToPress)
{
	this->keyToPress = keyToPress;
}


KeyboardCharacterStateController::~KeyboardCharacterStateController()
{
}


bool KeyboardCharacterStateController::isMakingAction() {
	return sf::Keyboard::isKeyPressed(keyToPress);
}