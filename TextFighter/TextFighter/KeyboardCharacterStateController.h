#pragma once
#include "CharacterStateController.h"
#include <SFML\Window\Event.hpp>

/**Class to manage actions on a characterState. Its purpose is to check whether the action has been called by the user or not.
	It is part of the MVC architecture pattern.
	@Author Thomas Dubrulle.*/
class KeyboardCharacterStateController : CharacterStateController
{
private:
	//The key to press to "activate" this controller.
	sf::Keyboard::Key keyToPress;
public:
	/*Create a new Keyboard interaction with the given key to press*/
	KeyboardCharacterStateController(sf::Keyboard::Key keyToPress);
	~KeyboardCharacterStateController();

	/**Check whether if the action can be made or not.
	@return true if the action is being made, false otherwise.*/
	bool isMakingAction() override;
};

