/*
* Description: This head file is for cross, the cross need id, up road id, *			   down road id,left road id, right road id.
*/

#ifndef CROSS_H
#define CROSS_H

#include <queue>

#include "carport.h"
#include "roadreceiver.h"

class Road;
class Car;

class Cross{
private:
	int _id;
	int _upId;
	int _downId;
	int _leftId;
	int _rightId;
	
	Carport* _carport;
	Road* _upRoad;
	Road* _downRoad;
	Road* _leftRoad;
	Road* _rightRoad;
	

	Car* _upCar;
	Car* _downCar;
	Car* _leftCar;
	Car* _rightCar;

	queue<Car*>* _upCarQueue;
	queue<Car*>* _downCarQueue;
	queue<Car*>* _rightCarQueue;
	queue<Car*>* _leftCarQueue;
	
public:
	Cross(){}
	Cross(int id, int up_id, int right_id, int down_id, int left_id);
	
	void init();
	
	/*
	void setId(int id);
	void setUpRoadId(int up_id);
	void setDownRoadId(int down_id);
	void setLeftRoadId(int left_id);
	void setRightRoadId(int right_id);
	*/
	
	const int getId();
	const int getUpRoadId();
	const int getDownRoadId();
	const int getLeftRoadId();
	const int getRightRoadId();
	
	void setUpRoad(Road* road);
	void setDownRoad(Road* road);
	void setLeftRoad(Road* road);
	void setRightRoad(Road* road);
	
	Road* getUpRoad();
	Road* getDownRoad();
	Road* getLeftRoad();
	Road* getRightRoad();
	
	Cross* getUpCross();
	Cross* getDownCross();
	Cross* getLeftCross();
	Cross* getRightCross();
	
	void insertStartCar(Car* car);
	
	int getHorizontalCarSize();
	int getVerticalCarSize();
	
	void move(int time);
};


#endif
