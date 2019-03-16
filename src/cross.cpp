#include "cross.h"

Cross::Cross(int id, int up_id, int right_id, int down_id, int left_id):
_id(id),_upId(up_id),_downId(down_id),_leftId(left_id),_rightId(right_id)
{

}
	
void Cross::init()
{

}
	
void Cross::setId(int id)
{
	this->_id = id;
}

void Cross::setUpRoadId(int up_id)
{
	this->_upId = up_id;
}

void Cross::setDownRoadId(int down_id)
{
	this->_downId = down_id;
}

void Cross::setLeftRoadId(int left_id)
{
	this->_leftId = left_id;
}

void Cross::setRightRoadId(int right_id)
{
	this->_rightId = right_id;
}
	
const int Cross::getId()
{
	return this->_id;
}

const int Cross::getUpRoadId()
{
	return this->_upId;
}

const int Cross::getDownRoadId()
{
	return this->_downId;
}

const int Cross::getLeftRoadId()
{
	return this->_leftId;
}

const int Cross::getRightRoadId()
{
	return this->_rightId;
}

