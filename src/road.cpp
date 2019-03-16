#include "road.h"

Road::Road(int id,int length,int max_speed,int channel_num,int start_id,int end_id,bool is_duplex):
_id(id),_length(length),_maxSpeed(max_speed),_channelNum(channel_num),_startId(start_id),_endId(end_id),_duplex(is_duplex)
{

}

void Road::init()
{

}


void Road::setId(int id)
{
	this->_id = id;
}

void Road::setLength(int length)
{
	this->_length = length;
}

void Road::setMaxSpeed(int max_speed)
{
	this->_maxSpeed = max_speed;
}

void Road::setChannelNum(int channel_num)
{
	this->_channelNum = channel_num;
}

void Road::setStartCrossId(int start_id)
{
	this->_startId = start_id;
}

void Road::setEndCrossId(int end_id)
{
	this->_endId = end_id;
}

void Road::setIsDuplex(bool is_duplex)
{
	this->_duplex = is_duplex;
}

const int Road::getId()
{
	return this->_id;
}

const int Road::getLength()
{
	return this->_length;
}

const int Road::getMaxSpeed()
{
	return this->_maxSpeed;
}

const int Road::getChannelNum()
{
	return this->_channelNum;
}

const int Road::getStartCrossId()
{
	return this->_startId;
}

const int Road::getEndCrossId()
{
	return this->_endId;
}

const bool Road::getIsDuplex()
{
	return this->_duplex;
}

