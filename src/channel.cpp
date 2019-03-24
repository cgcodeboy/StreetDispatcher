#include "channel.h"
#include "road.h"

Channel::Channel(Road* road):
_belongRoad(road)
{
	_carVec = new vector<Car*>;
}
	
// Brief: move the car in this channel
void Channel::move()
{
	if(_carVec->empty())
	{
		return;
	}
	Car* car = _carVec->front();
	int curDis = car->getLastDistance();
	int curSpeed = car->getCurrentSpeed();
	car->setLastDistance(curDis - car->getCurrentSpeed());
	for(vector<Car*>::iterator it = _carVec->begin()+1; it != _carVec->end(); it++)
	{
		car = *it;
		if(car->getLastDistance() - curDis < car->getCurrentSpeed())
		{
			int temp = car->getLastDistance();			
			car->setLastDistance(car->getLastDistance() - curDis);
			curDis = temp;
			temp = car->getCurrentSpeed();
			car->setCurrentSpeed(curSpeed);	
			curSpeed = temp;
		}
		else
		{
			int temp  = car->getLastDistance();
			car->setLastDistance(car->getLastDistance() - car->getCurrentSpeed());
			curDis = temp;
			curSpeed = car->getCurrentSpeed();
		}
	}
}

// Brief: This function will return whether this channel can push any car
bool Channel::canPushCar()
{
	if(_carVec->empty())
		return true;
	Car* car = _carVec->back();
	if(car->getLastDistance() == _belongRoad->getLength()-1)
		return false;
	return true;
}

// Brief: This function will return whether this channel has car will arrive the end
bool Channel::hasCarPassCross()
{
	if(_carVec->empty())
	{
		return false;
	}
	Car* car = _carVec->front();
	if(car->getLastDistance() < car->getCurrentSpeed())
	{
		return true;
	}
	return false;
}

// Brief: This function will pop out a car if there is a car will pass through the cross
Car* Channel::popPassCar()
{
	if(_carVec->empty())
		return nullptr;
	Car* car = _carVec->front();
	if(car->getLastDistance() < car->getCurrentSpeed())
	{
		_carVec->erase(_carVec->begin());
		return car;
	}
	return nullptr;
}

// Brief: This function will push a car which can put into this channel, and 
//		  we should put it in a right place, and set it's speed.
bool Channel::pushPassCar(Car* car)
{
	int lastDistance= car->getLastDistance();
	int distance = car->getCurrentSpeed() - lastDistance;
	//if this channel is empty
	if(_carVec->size() == 0)
	{
		car->setLastDistance(_belongRoad->getLength() - distance);
		car->setCurrentRoad(_belongRoad);	
		if(car->getMaxSpeed()< _belongRoad->getMaxSpeed())
		{
			car->setCurrentSpeed(car->getMaxSpeed());					
		}
		else
		{
			car->setCurrentSpeed(_belongRoad->getMaxSpeed());
		}
		_carVec->push_back(car);
		return true;		
	}
	
	int tailCarDistance = _belongRoad->getLength()- _carVec->at(_carVec->size() -1)->getLastDistance();
	//if this channel is full
	if(tailCarDistance == 0)
		return false;
	//if this channel is not empty or full, just have a car in the tail.
	car->setCurrentRoad(_belongRoad);
	//if the distance is enough, just go.
	if(tailCarDistance > distance)
	{
		car->setLastDistance(_belongRoad->getLength() - distance);
		if(car->getMaxSpeed()< _belongRoad->getMaxSpeed())
		{
			car->setCurrentSpeed(car->getMaxSpeed());					
		}
		else
		{
			car->setCurrentSpeed(_belongRoad->getMaxSpeed());
		}
	}
	//else go some step and follow the tail car
	else
	{
		car->setLastDistance(_belongRoad->getLength() - tailCarDistance);
		int speed = _carVec->at(_carVec->size() -1)->getCurrentSpeed();
		if(car->getMaxSpeed() > speed)
		{
			car->setCurrentSpeed(speed);
		}
		else
		{
			car->setCurrentSpeed(car->getMaxSpeed());
		}
	}
	_carVec->push_back(car);
	return true;		
}
