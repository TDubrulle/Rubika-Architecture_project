#pragma once

#include <vector>
#include "Observer.h"

/**An abstract class that allows to update the state of its observers by a single call to notifyObservers(). Follow the observer design pattern*/
class Observable
{
protected:
	/**The observers that should be updated.*/
	std::vector<Observer *> observers;
public:
	Observable();
	~Observable();
	virtual void addObserver(Observer *observer);
	void notifyObservers();
};

