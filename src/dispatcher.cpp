#include "dispatcher.h"

int TIME = 0;

/*
* Brief: This function is used to set the car, road and cross information in the scene
*		 After setter, it will call the sort scene relation function inside to set the relation
*		 between car and road
*/
void Dispatcher::setStreetScene(vector<Car>* car_vector, vector<Road>* road_vector, vector<Cross>* cross_vector)
{
	this->_carVec = car_vector;
	this->_roadVec = road_vector;
	this->_crossVec = cross_vector;
	sortSceneRelation();
}

/*
* Brief: This function is used to train the scene use some algorithm
*/
void Dispatcher::trainScene()
{
	cout<<"Guys, let's train it"<<endl;
}

/*
* Brief: This function is used to dispatch the scene use the model which has been trained by algorithm.
*/
void Dispatcher::dispatch()
{
	cout<<"Guys, let's dispatch it"<<endl;
}

/*
* Brief: This function is used to sort scene relation function inside to set the relation
*		 between car and road
*/
void Dispatcher::sortSceneRelation()
{
	for(vector<Cross>::iterator crossIt = _crossVec->begin(); crossIt != _crossVec->end(); crossIt++)
	{
		Cross cross = *crossIt;
		cross.init();
		
		//insert all the car which are planned to start from this cross into this current cross
		for(vector<Car>::iterator it = _carVec->begin(); it != _carVec->end(); it++)
		{
			if((*it).getStartCrossId() == cross.getId())
			{
				cross.insertStartCar(&(*it));
			}
		}
	
		/*
		* Judge whether the road is start from or end at this cross, if so, just set their
		* relation between each other
		*/
		for(vector<Road>::iterator it = _roadVec->begin(); it != _roadVec->end(); it++)
		{
			//up road
			if(cross.getUpRoadId() != -1 && cross.getUpRoadId() == (*it).getId())
			{
				cross.setUpRoad(&(*it));
				if((*it).getStartCrossId() == cross.getUpRoadId())
				{
					(*it).setStartCross(&cross);
				}
				else
				{
					(*it).setEndCross(&cross);
				}
			}
			//down road
			if(cross.getDownRoadId() != -1 && cross.getDownRoadId() == (*it).getId())
			{
				cross.setDownRoad(&(*it));
				if((*it).getStartCrossId() == cross.getDownRoadId())
				{
					(*it).setStartCross(&cross);
				}
				else
				{
					(*it).setEndCross(&cross);
				}
			}
			//left road
			if(cross.getLeftRoadId() != -1 && cross.getLeftRoadId() == (*it).getId())
			{
				cross.setLeftRoad(&(*it));
				if((*it).getStartCrossId() == cross.getLeftRoadId())
				{
					(*it).setStartCross(&cross);
				}
				else
				{
					(*it).setEndCross(&cross);
				}
			}
			//right road
			if(cross.getRightRoadId() != -1 && cross.getRightRoadId() == (*it).getId())
			{
				cross.setRightRoad(&(*it));
				if((*it).getStartCrossId() == cross.getRightRoadId())
				{
					(*it).setStartCross(&cross);
				}
				else
				{
					(*it).setEndCross(&cross);
				}
			}
		}
	}
}
