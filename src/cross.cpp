#include "cross.h"
#include "road.h"
#include "car.h"

Cross::Cross(int id, int up_id, int right_id, int down_id, int left_id):
_id(id),_upId(up_id),_downId(down_id),_leftId(left_id),_rightId(right_id)
{

}
	
void Cross::init()
{
	_carport = new Carport;
	_upRoad = nullptr;
	_downRoad = nullptr;
	_leftRoad = nullptr;
	_rightRoad = nullptr; 
}

/*
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
*/
	
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

void Cross::setUpRoad(Road* road)
{
	_upRoad = road;
}

void Cross::setDownRoad(Road* road)
{
	_downRoad = road;
}

void Cross::setLeftRoad(Road* road)
{
	_leftRoad = road;
}

void Cross::setRightRoad(Road* road)
{
	_rightRoad = road;
}

// Brief: This function is used to put all the car which is planned to start from this cross
//		  into it's carport
void Cross::insertStartCar(Car* car)
{
	_carport->enterCarport(car);
}

// Brief: This function is used to diapatch all the cars which will pass through this cross
void Cross::move()
{
	//Step_1: get the cars which want to pass through this cross, so that the car in
	//		  the road can move front, so there will be blank position for other cars
	//		  which are pop out in other cross
	Car* upCar = _upRoad->getFrontCar(this);
	Car* downCar = _downRoad->getFrontCar(this);
	Car* leftCar = _leftRoad->getFrontCar(this);
	Car* rightCar = _rightRoad->getFrontCar(this);
	
	//if some car's distination is this cross, just enter the carport
	if(upCar->getEndCrossId() == _id)
		_carport->arriveCarport(upCar);
	if(downCar->getEndCrossId() == _id)
		_carport->arriveCarport(downCar);
	if(leftCar->getEndCrossId() == _id)
		_carport->arriveCarport(leftCar);
	if(rightCar->getEndCrossId() == _id)
		_carport->arriveCarport(rightCar);
	
	//Step_2: move the car in every road
	if(_leftRoad)
		_leftRoad->move(this);
	if(_rightRoad)
		_rightRoad->move(this);
	if(_upRoad)
		_upRoad->move(this);
	if(_downRoad)
		_downRoad->move(this);
		
	//Step_3: let the car poped out enter their next road in orders
	//if(upCar->get
}

// Brief: This function will get the size of cars in left_right orientation
int Cross::getHorizontalCarSize()
{
	// wait to implement
	return 0;
}

// Brief: This function will get the size of cars in up_down orientation
int Cross::getVerticalCarSize()
{
	// wait to implement
	return 0;
}

