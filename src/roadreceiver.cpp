#include "roadreceiver.h"
#include "cross.h"

RoadReceiver::RoadReceiver(Road* in_road, Cross* out_cross):
_road(in_road),_cross(out_cross)
{
	*_straightCar = nullptr;
	*_leftCar = nullptr;
	*_rightCar = nullptr;
}

bool RoadReceiver::canReceiveCar()
{
	return _road->canPushCar(_cross);
}

// Brief: this function is used to insert the three car into the road in order
void RoadReceiver::receiveCar()
{
	if(*_straightCar)
	{
		_road->pushCar(*_straightCar,_cross);
		*_straightCar = nullptr;
	}
	if(*_leftCar)
	{
		if(_road->pushCar(*_leftCar,_cross))
		{
			*_leftCar = nullptr;
		}
	}
	if(*_rightCar)
	{
		if(_road->pushCar(*_rightCar,_cross))
		{
			*_rightCar = nullptr;
		}
	}
}

// set the straight car which want pass through the correspond road
void RoadReceiver::setStraightCar(Car** straight_car)
{
	_straightCar = straight_car;
}

// set the left turn car which want pass through the correspond road
void RoadReceiver::setLeftTurnCar(Car** left_turn_car)
{
	_leftCar = left_turn_car;
}

// set the right turn car which want pass through the correspond road
void RoadReceiver::setRightTurnCar(Car** right_turn_car)
{
	_rightCar = right_turn_car;
}
