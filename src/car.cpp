#include "car.h"
#include "road.h"

Car::Car(int id, int start_id, int end_id, int max_speed, unsigned int start_time):
_id(id),_startId(start_id),_endId(end_id),_maxSpeed(max_speed),_startTime(start_time)
{
	
}

void Car::init()
{
	_roadNumList = new list<int>;
}

/*
void Car::setId(int id)
{
	this->_id = id;
}

void Car::setStartCrossId(int start_id)
{
	this->_startId = start_id;
}

void Car::setEndCrossId(int end_id)
{
	this->_endId = end_id;
}

void Car::setMaxSpeed(int max_speed)
{
	this->_maxSpeed = max_speed;
}

void Car::setStartTime(unsigned int start_time)
{
	this->_startTime = start_time;
}
*/

const int Car::getId()
{
	return this->_id;
}

const int Car::getStartCrossId()
{
	return this->_startId;
}

const int Car::getEndCrossId()
{
	return this->_endId;
}

const int Car::getMaxSpeed()
{
	return this->_maxSpeed;
}

const unsigned int Car::getStartTime()
{
	return this->_startTime;
}

// Brief: set the current speed this car will run at
void Car::setCurrentSpeed(int speed)
{
	_curSpeed = speed;
}

// Brief: return the current speed
int Car::getCurrentSpeed()
{
	return _curSpeed;
}

// Brief: set the current road this car goes through
void Car::setCurrentRoad(Road* road)
{
	_roadNumList->push_back(road->getId());
}

// Brief: This function is used to output the road ids which this car has go through
const list<int>* Car::getRoute()
{
	return _roadNumList;
}

void Car::setLastDistance(int distance)
{
	_curDistance = distance;
}
int Car::getLastDistance()
{
	return _curDistance;
}

int Car::getNextRoadId(int current_road_id)
{
	for(list<int>::iterator it = _roadNumList->begin(); it != _roadNumList->end(); it++)
	{
		if(current_road_id == *it)
			return *it;			
	}
	return NULL;
}
