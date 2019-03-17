/*
* Description: This head file is for car, the car need id, start cross id, *			   end cross id, maxspeed and start time.
*/

#ifndef CAR_H
#define CAR_H

class Car{
private:
	int _id;
	int _startId;
	int _endId;
	int _maxSpeed;
	unsigned int _startTime;
	
public:
	Car(){}
	Car(int id, int start_id, int end_id, int max_speed, unsigned int start_time);

	void init();

	void setId(int id);
	void setStartCrossId(int start_id);
	void setEndCrossId(int end_id);
	void setMaxSpeed(int max_speed);
	void setStartTime(unsigned int start_time);

	const int getId();
	const int getStartCrossId();
	const int getEndCrossId();
	const int getMaxSpeed();
	const unsigned int getStartTime();
};


#endif
