/*
* Description: This file is used to be a manager of the scene. 
*			   It will sort the relation between road and cross, and use
*			   algorithm to optimate the scene in order to let all the car
* 			   arrive the distination as earlier as possible.
*/

#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "filehandle.h"
#include "crossthread.h"

class Dispatcher{
private:
	vector<Car> *_carVec;
	vector<Road> *_roadVec;
	vector<Cross> *_crossVec;
	
	void sortSceneRelation();
	
public:
	Dispatcher(){}
	
	void setStreetScene(vector<Car>* car_vector, vector<Road>* road_vector, vector<Cross>* cross_vector);
	
	void trainScene();
	
	void dispatch();
};

#endif
