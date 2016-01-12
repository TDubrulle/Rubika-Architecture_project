#include "stdafx.h"
#include "Timer.h"

#include <iostream>


Timer::Timer(float time)
{
	elapsedTime = 0.0f;
	this->maxTime = time;
}

Timer::~Timer()
{
}

void Timer::update()
{
	elapsedTime = elapsedTime + 1.0f;
	notifyObservers();
}

bool Timer::hasEnded() {
	return elapsedTime > maxTime;
}
