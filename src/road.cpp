#include "road.h"
#include "cross.h"

Road::Road(int id,int length,int max_speed,int channel_num,int start_id,int end_id,bool is_duplex):
_id(id),_length(length),_maxSpeed(max_speed),_channelNum(channel_num),_startId(start_id),_endId(end_id),_duplex(is_duplex),_startVecIndex(0),_endVecIndex(0)
{

}

void Road::init()
{
	_endChannelVec = new vector<Channel*>;
	for(int i = 0; i< _channelNum;i++)
	{
		_endChannelVec->push_back(new Channel(this));
	}
	if(_duplex)
	{
		_startChannelVec = new vector<Channel*>;
		for(int i = 0; i< _channelNum;i++)
		{
			_startChannelVec->push_back(new Channel(this));
		}
	}
}

/*
void Road::setId(int id)
{
	this->_id = id;
}

void Road::setLength(int length)
{
	this->_length = length;
}

void Road::setMaxSpeed(int max_speed)
{
	this->_maxSpeed = max_speed;
}

void Road::setChannelNum(int channel_num)
{
	this->_channelNum = channel_num;
}

void Road::setStartCrossId(int start_id)
{
	this->_startId = start_id;
}

void Road::setEndCrossId(int end_id)
{
	this->_endId = end_id;
}

void Road::setIsDuplex(bool is_duplex)
{
	this->_duplex = is_duplex;
}
*/

const int Road::getId()
{
	return this->_id;
}

const int Road::getLength()
{
	return this->_length;
}

const int Road::getMaxSpeed()
{
	return this->_maxSpeed;
}

const int Road::getChannelNum()
{
	return this->_channelNum;
}

const int Road::getStartCrossId()
{
	return this->_startId;
}

const int Road::getEndCrossId()
{
	return this->_endId;
}

const bool Road::getIsDuplex()
{
	return this->_duplex;
}

void Road::setStartCross(Cross* cross)
{
	_startCross = cross;
}

void Road::setEndCross(Cross* cross)
{
	_endCross = cross;
}

Cross* Road::getStartCross()
{
	return _startCross;
}

Cross* Road::getEndCross()
{
	return _endCross;
}

// Brief: This function is used to let all the car move toward
void Road::move(Cross* cross)
{
	if(cross == _startCross)
	{
		if(_duplex)
		{
			for(Channel* channel: *_startChannelVec)
				channel->move();
		}
	}
	else
	{
		for(Channel* channel: *_endChannelVec)
				channel->move();
	}
}

// Brief: This function will return the car that will pass through the cross
Car* Road::getFrontCar(Cross* pass_cross)
{
	if(pass_cross == _startCross)
	{
		// if we can get car from channel start index to the end of channels, just
		// return the car
		unsigned int cur = _startVecIndex%_channelNum;
		for(unsigned int i = cur; i < _startChannelVec->size(); i++)
		{
			Car* car = _startChannelVec->at(i)->popPassCar();
			if(car){
				_startVecIndex++;
				return car;
			}
			else{
				_startVecIndex++;
			}
		}
		// else we can try to get car from the begin of the channels to index-1,
		// if we can get car, just return the car
		for(unsigned int i = 0; i < cur; i++)
		{
			Car* car = _startChannelVec->at(i)->popPassCar();
			if(car){
				_startVecIndex++;
				return car;
			}
			else{
				_startVecIndex++;
			}
		}
		// now, it presents that there is no car will pass the cross.
		return nullptr;
	}
	else
	{
		// if we can get car from channel start index to the end of channels, just
		// return the car
		unsigned int cur = _endVecIndex%_channelNum;
		for(unsigned int i = cur; i < _endChannelVec->size(); i++)
		{
			Car* car = _endChannelVec->at(i)->popPassCar();
			if(car){
				_endVecIndex++;
				return car;
			}
			else{
				_endVecIndex++;
			}
		}
		// else we can try to get car from the begin of the channels to index-1,
		// if we can get car, just return the car
		for(unsigned int i = 0; i < cur; i++)
		{
			Car* car = _endChannelVec->at(i)->popPassCar();
			if(car){
				_endVecIndex++;
				return car;
			}
			else{
				_endVecIndex++;
			}
		}
		// now, it presents that there is no car will pass the cross.
		return nullptr;
	}	
}

//Brief: This function will push the car which will pass through this road
bool Road::pushCar(Car* car,Cross* pass_cross)
{
	//error!! it's duplex
	if(pass_cross == _startCross)
	{
		for(unsigned int i = 0;i < _endChannelVec->size(); i++)
		{
			if(_endChannelVec->at(i)->pushPassCar(car))
				return true;
		}
		return false;
	}
	else
	{
		for(unsigned int i = 0;i < _startChannelVec->size(); i++)
		{
			if(_startChannelVec->at(i)->pushPassCar(car))
				return true;
		}
		return false;
	}
}

