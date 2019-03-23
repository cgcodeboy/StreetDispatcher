/*
* Description: This head file is for car, the car need id, start cross id, *			   end cross id, maxspeed and start time.
*/

#ifndef CAR_H
#define CAR_H

#include <list>
#include <iostream>

using namespace std;

class Road;

class Car{
private:
	int _id;
	int _startId;
	int _endId;
	int _maxSpeed;
	unsigned int _planTime;
	unsigned int _realTime;
	int _curSpeed;
	Road* _curRoad;
	int _curDistance;
	
	list<int>* _roadNumList;
	
public:
	Car(){}
	Car(int id, int start_id, int end_id, int max_speed, unsigned int start_time);

	void init();

	/*
	void setId(int id);
	void setStartCrossId(int start_id);
	void setEndCrossId(int end_id);
	void setMaxSpeed(int max_speed);
	void setStartTime(unsigned int start_time);
	*/

	const int getId();
	const int getStartCrossId();
	const int getEndCrossId();
	const int getMaxSpeed();
	const unsigned int getPlanTime();
	
	void setRealStartTime(unsigned int time);
	
	void setCurrentSpeed(int speed);
	int getCurrentSpeed();
	void setCurrentRoad(Road* road);
	
	const list<int>* getRoute();
	void setRoute(list<int>* route_list);
	
	void setLastDistance(int distance);
	int getLastDistance();
	
	int getNextRoadId(int current_road_id);
};


#endif
