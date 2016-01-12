#include "stdafx.h"
#include "Match.h"

#include <iostream>
#include <thread>
#include <string>
#include <SFML\Window\Keyboard.hpp>
#include "Character.h"
#include "CharacterState.h"
#include "idle.h"
#include "MoveLeft.h"
#include "MoveRight.h"
#include "Attack.h"
#include "KeyboardCharacterStateController.h"
#include <thread> 

using namespace std;
Match::Match(Character *p1, Character *p2)
{
	players = std::vector<Character*>();
	players.push_back(p1);
	players.push_back(p2);
	players[0]->addObserver(this);
	players[1]->addObserver(this);
	players[0]->setCurMatch(this);
	players[1]->setCurMatch(this);
	gameEnded = false;
}


Match::~Match()
{
}

void Match::update() {
	if (players[0]->getLife() <= 0.0f) {
		gameEnded = true;
		std::cout << "Game ended!" << endl;
		std::cout << players[1]->getName() << " wins!";
	}
	else if (players[1]->getLife() <= 0.0f) {
		gameEnded = true;
		std::cout << "Game ended!" << endl;
		std::cout << players[0]->getName() << " wins!";
	}
}

void Match::startGame() {
	//Thread creation
	std::thread *threadP1 = new thread(&Match::managePlayer,this,players[0]);
	std::thread *threadP2 = new thread(&Match::managePlayer, this, players[1]);
	//We wait for the game to end.
	threadP1->join();
	threadP2->join();
}


void Match::managePlayer(Character *p1) {
	while (!gameEnded) {
		//For the purpose of avoiding thousands of printed lines, we let a space of 1s between actions.
		//Todo: make it more real time by removing the sleep.
		this_thread::sleep_for(1s);
		p1->update();
	}
}

Character * Match::getOtherPlayer(Character * p)
{
	if (players[0] == p) {
		return players[1];
	}
	else {
		return players[0];
	}
}
