/*
* Description:
* This head file is for car, the car need id, start cross id, end cross id, max
* speed and start time.
*/

#ifndef CAR_H
#define CAR_H

class Car{
private:
	int _id;
	int _startId;
	int _endId;
	int _maxSpeed;
	int _startTime;
	
public:
	Car(){}
	Car(int id, int start_id, int end_id, int max_speed, int start_time);

	void init();

	void setId(int id);
	void setStartCrossId(int start_id);
	void setEndCrossId(int end_id);
	void setMaxSpeed(int max_speed);
	void setStartTime(int start_time);

	const int getId();
	const int getStartCrossId();
	const int getEndCrossId();
	const int getMaxSpeed();
	const int getStartTime();

};


#endif