/*
* Description:
* This head file is for road, the road need id,length,max speed,channel
* num,start cross id,end cross id, and whether it's duplex road.
*/
#ifndef ROAD_H
#define ROAD_H


class Road{
private:
	int _id;
	int _length;
	int _maxSpeed;
	int _channelNum;
	int _startId;
	int _endId;
	bool _duplex;

public:
	Road(){}
	Road(int id,int length,int max_speed,int channel_num,int start_id,int end_id,bool is_duplex);

	void init();

	void setId(int id);
	void setLength(int length);
	void setMaxSpeed(int max_speed);
	void setChannelNum(int channel_num);
	void setStartCrossId(int start_id);
	void setEndCrossId(int end_id);
	void setIsDuplex(bool is_duplex);

	const int getId();
	const int getLength();
	const int getMaxSpeed();
	const int getChannelNum();
	const int getStartCrossId();
	const int getEndCrossId();
	const bool getIsDuplex();
};



#endif

