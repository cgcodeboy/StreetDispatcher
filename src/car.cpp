#include "car.h"

Car::Car(int id, int start_id, int end_id, int max_speed, unsigned int start_time):
_id(id),_startId(start_id),_endId(end_id),_maxSpeed(max_speed),_startTime(start_time)
{
	
}

void Car::init()
{

}

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

