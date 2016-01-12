// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Match.h"
#include "Idle.h"
#include "Attack.h"
#include "MoveLeft.h"
#include "MoveRight.h"
#include "Jump.h"
#include "KeyboardCharacterStateController.h"

using namespace std;

/*Todo: move this functionnality to the settings.*/
void setP1Controls(Character *p1) {
	//-CharacterState Creation
	CharacterState *idle = new Idle();
	CharacterState *movel = new MoveLeft();
	CharacterState *mover = new MoveRight();
	CharacterState *jump = new Jump();
	CharacterState *attack = new Attack(25.0f);

	//-Assigning an input to a state
	attack->setController((CharacterStateController*)new KeyboardCharacterStateController(sf::Keyboard::RControl));
	movel->setController((CharacterStateController*)new KeyboardCharacterStateController(sf::Keyboard::Left));
	mover->setController((CharacterStateController*)new KeyboardCharacterStateController(sf::Keyboard::Right));
	jump->setController((CharacterStateController*)new KeyboardCharacterStateController(sf::Keyboard::Up));

	//-Link states to make transitions.
	idle->addPossibleState(movel);
	idle->addPossibleState(mover);
	idle->addPossibleState(attack);
	idle->addPossibleState(jump);

	movel->addPossibleState(idle);
	movel->addPossibleState(mover);
	movel->addPossibleState(jump);
	//TTODO add attack state here.

	mover->addPossibleState(idle);
	mover->addPossibleState(movel);
	mover->addPossibleState(jump);
	mover->addPossibleState(attack);

	jump->addPossibleState(idle);
	jump->addPossibleState(movel);
	jump->addPossibleState(mover);
	jump->addPossibleState(attack);

	attack->addPossibleState(idle);
	attack->addPossibleState(movel);
	attack->addPossibleState(mover);
	attack->addPossibleState(jump);



	//Set the starting state.
	p1->setCurrentState(idle);

}

/*Todo: move this functionnality to the settings.*/
void setP2Controls(Character *p2) {
	//-CharacterState Creation
	CharacterState *idle = new Idle();
	CharacterState *movel = new MoveLeft();
	CharacterState *mover = new MoveRight();
	CharacterState *jump = new Jump();
	CharacterState *attack = new Attack(25.0f);

	//-Assigning an input to a state
	attack->setController((CharacterStateController*)new KeyboardCharacterStateController(sf::Keyboard::F));
	movel->setController((CharacterStateController*)new KeyboardCharacterStateController(sf::Keyboard::Q));
	mover->setController((CharacterStateController*)new KeyboardCharacterStateController(sf::Keyboard::D));
	jump->setController((CharacterStateController*)new KeyboardCharacterStateController(sf::Keyboard::Space));

	//-Link states to make transitions.
	idle->addPossibleState(movel);
	idle->addPossibleState(mover);
	idle->addPossibleState(attack);
	idle->addPossibleState(jump);

	movel->addPossibleState(idle);
	movel->addPossibleState(mover);
	movel->addPossibleState(jump);
	//TTODO add attack state here.

	mover->addPossibleState(idle);
	mover->addPossibleState(movel);
	mover->addPossibleState(jump);
	mover->addPossibleState(attack);

	jump->addPossibleState(idle);
	jump->addPossibleState(movel);
	jump->addPossibleState(mover);
	jump->addPossibleState(attack);

	attack->addPossibleState(idle);
	attack->addPossibleState(movel);
	attack->addPossibleState(mover);
	attack->addPossibleState(jump);



	//Set the starting state.
	p2->setCurrentState(idle);
}

int main()
{
	Character *p1 = new Character("p1", 100.0f);
	setP1Controls(p1);
	Character *p2 = new Character("p2", 100.0f);
	setP2Controls(p2);
	Match m = Match(p1, p2);
	m.startGame();
	while (true) {};
    return 0;
}

