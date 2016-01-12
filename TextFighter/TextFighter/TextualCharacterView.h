#pragma once
#include "CharacterView.h"
#include <mutex>

/**A text based characterView that displays text in the console.*/
class TextualCharacterView :
	public CharacterView
{
private:
	static std::mutex coutLock;
public:
	TextualCharacterView(Character *character) : CharacterView(character) {};
	void playAttack() override;
	void playDamage(float amount) override;
	void playJump() override;
	void playMoveLeft() override;
	void playMoveRight() override;
	void playIdle() override;
};

