#include "dispatcher.h"

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

}
