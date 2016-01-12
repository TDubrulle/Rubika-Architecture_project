#include "stdafx.h"
#include "Observable.h"


Observable::Observable()
{
}


Observable::~Observable()
{
}

void Observable::addObserver(Observer *observer) {
	observers.push_back(observer);
}

void Observable::notifyObservers() {
	for (unsigned int i = 0; i < observers.size(); ++i) {
		observers.at(i)->update();
	}
}
