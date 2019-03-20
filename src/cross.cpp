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
	if(!_upCar&&_upRoad)
		_upCar = _upRoad->getFrontCar(this);
	if(!_downCar&&_downRoad)
		_downCar = _downRoad->getFrontCar(this);
	if(!_leftCar&&_leftRoad)
		_leftCar = _leftRoad->getFrontCar(this);
	if(!_rightCar&&_rightRoad)
		_rightCar = _rightRoad->getFrontCar(this);
	
	//if some car's distination is this cross, just enter the carport
	if(_upCar->getEndCrossId() == _id)
	{
		_carport->arriveCarport(_upCar);
		_upCar = nullptr;
	}
	if(_downCar->getEndCrossId() == _id)
	{
		_carport->arriveCarport(_downCar);
		_downCar = nullptr;
	}
	if(_leftCar->getEndCrossId() == _id)
	{
		_carport->arriveCarport(_leftCar);
		_leftCar = nullptr;
	}
	if(_rightCar->getEndCrossId() == _id)
	{
		_carport->arriveCarport(_rightCar);
		_rightCar = nullptr;
	}
	
	//Step_2: move the car in every road and initialize the road receiver
	RoadReceiver* leftReceiver = nullptr;
	RoadReceiver* rightReceiver = nullptr;
	RoadReceiver* upReceiver = nullptr;
	RoadReceiver* downReceiver = nullptr;
	if(_leftRoad)
	{
		_leftRoad->move(this);
		leftReceiver = new RoadReceiver(_leftRoad,this);
		if(_rightCar&&_rightCar->getNextRoadId(_rightRoad->getId()) == _leftRoad->getId())
		{
			leftReceiver->setStraightCar(&_rightCar);
		}
		if(_downCar&&_downCar->getNextRoadId(_downRoad->getId()) == _leftRoad->getId())
		{
			leftReceiver->setLeftTurnCar(&_downCar);
		}
		if(_upCar&&_upCar->getNextRoadId(_upRoad->getId()) == _leftRoad->getId())
		{
			leftReceiver->setRightTurnCar(&_upCar);
		}
	}
	if(_rightRoad)
	{
		_rightRoad->move(this);
		rightReceiver = new RoadReceiver(_rightRoad,this);
		if(_leftCar&&_leftCar->getNextRoadId(_leftRoad->getId()) == _rightRoad->getId())
		{
			rightReceiver->setStraightCar(&_leftCar);
		}
		if(_upCar&&_upCar->getNextRoadId(_upRoad->getId()) == _rightRoad->getId())
		{
			rightReceiver->setLeftTurnCar(&_upCar);
		}
		if(_downCar&&_downCar->getNextRoadId(_downRoad->getId()) == _rightRoad->getId())
		{
			rightReceiver->setRightTurnCar(&_downCar);
		}		
	}
	if(_upRoad)
	{
		_upRoad->move(this);
		upReceiver = new RoadReceiver(_upRoad,this);
		if(_downCar&&_downCar->getNextRoadId(_downRoad->getId()) == _upRoad->getId())
		{
			upReceiver->setStraightCar(&_downCar);
		}
		if(_leftCar&&_leftCar->getNextRoadId(_leftRoad->getId()) == _upRoad->getId())
		{
			upReceiver->setLeftTurnCar(&_leftCar);
		}
		if(_rightCar&&_rightCar->getNextRoadId(_upRoad->getId()) == _upRoad->getId())
		{
			upReceiver->setRightTurnCar(&_rightCar);
		}		
	}
	if(_downRoad)
	{
		_downRoad->move(this);
		downReceiver = new RoadReceiver(_downRoad,this);
		if(_upCar&&_upCar->getNextRoadId(_downRoad->getId()) == _downRoad->getId())
		{
			downReceiver->setStraightCar(&_downCar);
		}
		if(_rightCar&&_rightCar->getNextRoadId(_upRoad->getId()) == _downRoad->getId())
		{
			downReceiver->setLeftTurnCar(&_rightCar);
		}
		if(_leftCar&&_leftCar->getNextRoadId(_leftRoad->getId()) == _downRoad->getId())
		{
			downReceiver->setRightTurnCar(&_leftCar);
		}		
	}
		
	//Step_3: let the road reveiver run
	if(leftReceiver)
	{
		leftReceiver->receiveCar();
	}
	if(rightReceiver)
	{
		rightReceiver->receiveCar();
	}
	if(upReceiver)
	{
		upReceiver->receiveCar();
	}
	if(downReceiver)
	{
		downReceiver->receiveCar();
	}
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

// return up road
Road* Cross::getUpRoad()
{
	if(_upId != -1)
		return _upRoad;
	return nullptr;
}

//return down road
Road* Cross::getDownRoad()
{
	if(_downId != -1)
		return _downRoad;
	return nullptr;
}

//return left road
Road* Cross::getLeftRoad()
{
	if(_leftId != -1)
		return _leftRoad;
	return nullptr;
}

//return right road
Road* Cross::getRightRoad()
{
	if(_rightId != -1)
		return _rightRoad;
	return nullptr;
}

//return up cross adjacent
Cross* Cross::getUpCross()
{
	if(_upId != -1)
	{
		return _id == _upRoad->getStartCrossId()?_upRoad->getEndCross():_upRoad->getStartCross();
	}
	return nullptr;
}

//return down cross adjacent
Cross* Cross::getDownCross()
{
	if(_downId != -1)
	{
		return _id == _downRoad->getStartCrossId()?_downRoad->getEndCross():_downRoad->getStartCross();
	}
	return nullptr;
}

//return left cross adjacent
Cross* Cross::getLeftCross()
{
	if(_leftId != -1)
	{
		return _id == _leftRoad->getStartCrossId()?_leftRoad->getEndCross():_leftRoad->getStartCross();
	}
	return nullptr;
}

//return right cross adjacent
Cross* Cross::getRightCross()
{
	if(_rightId != -1)
	{
		return _id == _rightRoad->getStartCrossId()?_rightRoad->getEndCross():_rightRoad->getStartCross();
	}
	return nullptr;
}

