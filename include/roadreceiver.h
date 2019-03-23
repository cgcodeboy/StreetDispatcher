/*
* Description: This head file is for the car receiver for every road, when the cars need 
*			   to turn into the same road, it can handle the order in which they are
*			   inserted.
*/

#ifndef ROAD_RECEIVER_H
#define ROAD_RECEIVER_H

#include "road.h"

class Cross;

class RoadReceiver{
private:
	Road* _road;
	Cross* _cross;
	Car** _straightCar;
	Car** _leftCar;
	Car** _rightCar;
	
public:
	RoadReceiver(Road* in_road, Cross* out_cross);
	
	void receiveCar();
	bool canReceiveCar();
	
	void setStraightCar(Car** straight_car);
	void setLeftTurnCar(Car** left_turn_car);
	void setRightTurnCar(Car** right_turn_car);
};




#endif
