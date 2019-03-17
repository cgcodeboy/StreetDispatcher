/*
* Description: This file is used to read the txt files and transform the 	*			   data into Object like road, car and cross. And it's also used *			   to write answer.
*/

#ifndef FILE_HANDLE_H
#define FILE_HANDLW_H

#include <iostream>
#include <assert.h>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <exception>

#include "car.h"
#include "road.h"
#include "cross.h"

using namespace std;

class FileHandle{
private:
	string _carFilePath;
	string _roadFilePath;
	string _crossFilePath;
	string _answerFilePath;
	
	vector<Car> *_carVec;
	vector<Road> *_roadVec;
	vector<Cross> *_crossVec;
	
	void transformCarData();
	void transformRoadData();
	void transformCrossData();
	
public:
	FileHandle();
	FileHandle(string car_file_path, string road_file_path, string cross_file_path, string answer_file_path);
	
	void setFilePath(string car_file_path, string road_file_path, string cross_file_path,string answer_file_path);
	void transformData();
	void writeAnswer();
	
	vector<Car>* getCarVector();
	vector<Road>* getRoadVector();
	vector<Cross>* getCrossVector();
};

#endif
