/*
* Description: This head file is for carport, it used to store the car which 
* 			   is start from this cross and arrive this cross.
*			   It's clearly that every cross have a carport.
*/

#ifndef CARPORT_H
#define CARPORT_H

#include <vector>

#include "car.h"

using namespace std;

class Carport{
private:
	vector<Car*>* _waitCarVec;
	vector<Car*>* _arriveCarVec;
	
public:
	Carport();
	
	void enterCarport(Car* init_car);
	void arriveCarport(Car* arrive_car);
	Car* leaveCarport(unsigned int current_time);
};



#endif
