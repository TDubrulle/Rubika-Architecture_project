#include "stdafx.h"
#include "TextualCharacterView.h"

#include <iostream>

using namespace std;

std::mutex TextualCharacterView::coutLock{};
void TextualCharacterView::playAttack()
{
	coutLock.lock();
	cout << character->getName() << " is attacking!"<< endl;
	coutLock.unlock();
}

void TextualCharacterView::playDamage(float amount)
{
	coutLock.lock();
	cout << character->getName() << " (" << character->getLife() << "hp) has taken a serious hit! (-" << amount << "hp)" << endl;
	coutLock.unlock();
}

void TextualCharacterView::playJump()
{
	coutLock.lock();
	cout << character->getName() << " is bunny hopping! Incredible!" << endl;
	coutLock.unlock();
}

void TextualCharacterView::playMoveLeft()
{
	coutLock.lock();
	cout << character->getName() << " is running right to the left!" << endl;
	coutLock.unlock();
}

void TextualCharacterView::playMoveRight()
{
	coutLock.lock();
	cout << character->getName() << " is running to the right! Oh! He almost left the arena!" << endl;
	coutLock.unlock();
}

void TextualCharacterView::playIdle()
{
	coutLock.lock();
	cout << character->getName() << " is waiting! What an audacious (non-)move!" << endl;
	coutLock.unlock();
}
