#pragma once
#include "Observable.h"
class Timer :
	public Observable
{
protected:
	float elapsedTime;
	float maxTime;
public:
	Timer(float time);
	~Timer();
	void update();
	bool hasEnded();
};

