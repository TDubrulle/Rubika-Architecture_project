#include "stdafx.h"
#include "QuickMatch.h"

#include "Match.h"
#include "Idle.h"
#include "Attack.h"
#include "MoveLeft.h"
#include "MoveRight.h"
#include "Jump.h"
#include "Block.h"
#include "KeyboardCharacterStateController.h"
#include "Character.h"


/*Todo: move this functionnality to the settings.*/
void setP1Controls(Character *p1) {
	//-CharacterState Creation
	CharacterState *idle = new Idle();
	CharacterState *movel = new MoveLeft();
	CharacterState *mover = new MoveRight();
	CharacterState *jump = new Jump();
	CharacterState *attack = new Attack(5.0f);
	//A simple combo: attack button + attack button = stronger Attack.
	CharacterState *attack2 = new Attack(10.0f);
	CharacterState *block = new Block(0.1f);

	//-Assigning an input to a state
	movel->setController((CharacterStateController*)new KeyboardCharacterStateController(sf::Keyboard::Left));
	mover->setController((CharacterStateController*)new KeyboardCharacterStateController(sf::Keyboard::Right));
	jump->setController((CharacterStateController*)new KeyboardCharacterStateController(sf::Keyboard::Up));
	attack->setController((CharacterStateController*)new KeyboardCharacterStateController(sf::Keyboard::RControl));
	attack2->setController((CharacterStateController*)new KeyboardCharacterStateController(sf::Keyboard::RControl));
	block->setController((CharacterStateController*) new KeyboardCharacterStateController(sf::Keyboard::RShift));

	//-Link states to make transitions.
	idle->addPossibleState(movel);
	idle->addPossibleState(mover);
	idle->addPossibleState(attack);
	//We can't do the finisher attack from idle.
	idle->addPossibleState(jump);
	idle->addPossibleState(block);

	movel->addPossibleState(idle);
	movel->addPossibleState(mover);
	movel->addPossibleState(jump);
	movel->addPossibleState(attack);
	//We can't do the finisher attack from move.
	movel->addPossibleState(block);

	mover->addPossibleState(idle);
	mover->addPossibleState(movel);
	mover->addPossibleState(jump);
	mover->addPossibleState(attack);
	//We can't do the finisher attack from move.
	mover->addPossibleState(block);

	jump->addPossibleState(idle);
	jump->addPossibleState(movel);
	jump->addPossibleState(mover);
	jump->addPossibleState(attack);
	//We can't do the finisher attack from jump.
	jump->addPossibleState(block);

	attack->addPossibleState(idle);
	attack->addPossibleState(movel);
	attack->addPossibleState(mover);
	attack->addPossibleState(jump);
	attack->addPossibleState(attack2);
	attack->addPossibleState(block);

	attack2->addPossibleState(idle);
	attack2->addPossibleState(movel);
	attack2->addPossibleState(mover);
	attack2->addPossibleState(jump);
	attack2->addPossibleState(block);

	block->addPossibleState(idle);
	block->addPossibleState(movel);
	block->addPossibleState(mover);
	block->addPossibleState(jump);
	block->addPossibleState(attack);
	//we can't do the finisher attack from block.

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
	CharacterState *attack = new Attack(5.0f);
	//A simple combo: attack button + attack button = stronger Attack.
	CharacterState *attack2 = new Attack(10.0f);
	CharacterState *block = new Block(0.1f);

	//-Assigning an input to a state
	movel->setController((CharacterStateController*)new KeyboardCharacterStateController(sf::Keyboard::Q));
	mover->setController((CharacterStateController*)new KeyboardCharacterStateController(sf::Keyboard::D));
	jump->setController((CharacterStateController*)new KeyboardCharacterStateController(sf::Keyboard::Space));
	attack->setController((CharacterStateController*)new KeyboardCharacterStateController(sf::Keyboard::F));
	attack2->setController((CharacterStateController*)new KeyboardCharacterStateController(sf::Keyboard::F));
	block->setController((CharacterStateController*) new KeyboardCharacterStateController(sf::Keyboard::E));

	//-Link states to make transitions.
	idle->addPossibleState(movel);
	idle->addPossibleState(mover);
	idle->addPossibleState(attack);
	//We can't do the finisher attack from idle.
	idle->addPossibleState(jump);
	idle->addPossibleState(block);

	movel->addPossibleState(idle);
	movel->addPossibleState(mover);
	movel->addPossibleState(jump);
	movel->addPossibleState(attack);
	//We can't do the finisher attack from move.
	movel->addPossibleState(block);

	mover->addPossibleState(idle);
	mover->addPossibleState(movel);
	mover->addPossibleState(jump);
	mover->addPossibleState(attack);
	//We can't do the finisher attack from move.
	mover->addPossibleState(block);

	jump->addPossibleState(idle);
	jump->addPossibleState(movel);
	jump->addPossibleState(mover);
	jump->addPossibleState(attack);
	//We can't do the finisher attack from jump.
	jump->addPossibleState(block);

	attack->addPossibleState(idle);
	attack->addPossibleState(movel);
	attack->addPossibleState(mover);
	attack->addPossibleState(jump);
	attack->addPossibleState(attack2);
	attack->addPossibleState(block);

	attack2->addPossibleState(idle);
	attack2->addPossibleState(movel);
	attack2->addPossibleState(mover);
	attack2->addPossibleState(jump);
	attack2->addPossibleState(block);

	block->addPossibleState(idle);
	block->addPossibleState(movel);
	block->addPossibleState(mover);
	block->addPossibleState(jump);
	block->addPossibleState(attack);
	//we can't do the finisher attack from block.

	//Set the starting state.
	p2->setCurrentState(idle);
}

QuickMatch::QuickMatch()
{
}

QuickMatch::~QuickMatch()
{
}

void QuickMatch::start()
{
	Character *p1 = new Character("p1", 100.0f);
	setP1Controls(p1);
	Character *p2 = new Character("p2", 100.0f);
	setP2Controls(p2);
	Match m = Match(p1, p2, 90.0f);
	m.startGame();
}
