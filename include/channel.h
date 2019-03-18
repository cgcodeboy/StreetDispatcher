/*
* Description: This head file is for the channel of road
*/

#ifndef CHANNEL_H
#define CHANNEL_H

#include <vector>

#include "car.h"

class Road;

using namespace std;

class Channel{
private:
	Road* _belongRoad;
	
	vector<Car*>* _carVec;
	
public:
	Channel(Road* road);
	
	void move();
	
	Car* popPassCar();
	bool pushPassCar(Car* car);
};


#endif
