#include "carport.h"

// Brief: Construct function
Carport::Carport()
{
	_waitCarVec = new vector<Car*>;
	_arriveCarVec = new vector<Car*>;
}

// Brief: This function is used to store the initalize car into the carport.
void Carport::enterCarport(Car* init_car)
{
	_waitCarVec->push_back(init_car);
}

// Brief: This function is used to store the arriving car which has beed dispatched.
void Carport::arriveCarport(Car* arrive_car)
{
	_arriveCarVec->push_back(arrive_car);
}

// Brief: This function is used to get a car which is planned to start at the given time and
//		  has the fastest speed.
// Note: This function can be optimized use other method.
Car* Carport::getCarToRoad(unsigned int current_time,int road_id)
{
	if(_waitCarVec->empty())
		return nullptr;
	// get the cars which is planned to start at this time
	vector<Car*>* currentVec = new vector<Car*>;
	for(vector<Car*>::iterator it = _waitCarVec->begin(); it != _waitCarVec->end(); it++)
	{
		if((*it)->getPlanTime() <= current_time && (*it)->getNextRoadId(0) == road_id)
		{
			currentVec->push_back(*it);
			it = _waitCarVec->erase(it);
		}
	}
	
	//get the car which has the most fastest speed
	int fastSpeed = 0;
	vector<Car*>::iterator fastSpeed_it = currentVec->end();//this iterator stores car which has the fastest speed
	for(vector<Car*>::iterator it = currentVec->begin(); it != currentVec->end(); it++)
	{
		if((*it)->getMaxSpeed() > fastSpeed){
			fastSpeed_it = it;
			fastSpeed = (*it)->getMaxSpeed();
		}
	}
	if(fastSpeed_it != currentVec->end())
	{
		Car* returnCar = *fastSpeed_it;
		returnCar->setRealStartTime(current_time);
		fastSpeed_it = currentVec->erase(fastSpeed_it);
		return returnCar;
	}
	return nullptr;
}

