#include "car.h"
#include "road.h"

Car::Car(int id, int start_id, int end_id, int max_speed, unsigned int start_time):
_id(id),_startId(start_id),_endId(end_id),_maxSpeed(max_speed),_planTime(start_time)
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

const unsigned int Car::getPlanTime()
{
	return this->_planTime;
}

void Car::setRealStartTime(unsigned int time)
{
	_realTime = time;
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

// Brief: This function is used to set the route this car will pass through
void Car::setRoute(list<int>* route_list)
{
	_roadNumList = route_list;
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
	if(current_road_id == 0)
	{
		return _roadNumList->front();
	}
	for(list<int>::iterator it = _roadNumList->begin(); it != _roadNumList->end(); it++)
	{
		if(current_road_id == *it)
			return *it;			
	}
	return NULL;
}
