#pragma once
#include "Observer.h"
#include "Character.h"
#include <vector>
/**A class that represents a game as a whole.
It takes care of the conditions of the game's end.
@Author Thomas Dubrulle*/
class Match : Observer
{
private:
	//Indicates if the game has ended or not.
	bool gameEnded;
	//The player list.
	std::vector<Character*> players;

	/**Function called by the thread.*/
	void managePlayer(Character* player);
public:
	Match(Character *p1, Character *p2);
	~Match();
	void update() override;
	void startGame();
	Character *getOtherPlayer(Character *p);

};