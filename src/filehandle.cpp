#include "filehandle.h"

// Brief: string split function
vector<string> split(const string& in, const string& delim) {
    regex re{ delim };
    return vector<string> {
        sregex_token_iterator(in.begin(), in.end(), re, -1),
            sregex_token_iterator()
    };
}

// Brief: Construct function
FileHandle::FileHandle()
{
	_carVec = new vector<Car*>;
	_roadVec = new vector<Road*>;
	_crossVec = new vector<Cross*>;
}

// Brief: Construct function
FileHandle::FileHandle(string car_file_path, string road_file_path, string cross_file_path,string answer_file_path):
_carFilePath(car_file_path),_roadFilePath(road_file_path),_crossFilePath(cross_file_path),_answerFilePath(answer_file_path)
{
	_carVec = new vector<Car*>;
	_roadVec = new vector<Road*>;
	_crossVec = new vector<Cross*>;
}

// Brief: This function is set the path of car file, road file and cross file
void FileHandle::setFilePath(string car_file_path, string road_file_path, string cross_file_path,string answer_file_path)
{
	this->_carFilePath = car_file_path;
	this->_roadFilePath = road_file_path;
	this->_crossFilePath = cross_file_path;
	this->_answerFilePath = answer_file_path;
}

/*
* Brief: This function is used to read three input files and transform into car,
* 		 road and cross information. In this function, it will call three
* 		 subfunction to handle the file separately.
*/	
void FileHandle::transformData()
{
	transformCarData();
	transformRoadData();
	transformCrossData();
}

/*
* Brief: This function is used to write answer to a txt file.
*/		
void FileHandle::writeAnswer()
{

}

/*
* Brief: This function a subfunction which is used to handle car file and
* 		 transform it to car information.
*/	
void FileHandle::transformCarData()
{
	ifstream readStream;
	readStream.open(_carFilePath.data(),ios::in);
	assert(readStream.is_open());
	
	string line;
	while(getline(readStream,line))
	{
		if(line.find("#") != string::npos)
			continue;
		line = line.substr(1,line.length()-2);
		
		unsigned int index = 0;
		while((index = line.find(' ',index)) != string::npos)
		{
			line.erase(index,1);
		}
		
		vector<string> dataVec = split(line,",");
		
		Car* car = new Car(stoi(dataVec.at(0)),stoi(dataVec.at(1)),stoi(dataVec.at(2)),stoi(dataVec.at(3)),stoi(dataVec.at(4)));
		
		try{
			_carVec->push_back(car);
		}
		catch(exception& e){
			cout<<e.what();
		}
	}
	readStream.close();
}

/*
* Brief: This function a subfunction which is used to handle road file and
* 		 transform it to road information.
*/	
void FileHandle::transformRoadData()
{
	ifstream readStream;
	readStream.open(_roadFilePath.data(),ios::in);
	assert(readStream.is_open());
	
	string line;
	while(getline(readStream,line))
	{
		if(line.find("#") != string::npos)
			continue;
		line = line.substr(1,line.length()-2);
		
		unsigned int index = 0;
		while((index = line.find(' ',index)) != string::npos)
		{
			line.erase(index,1);
		}
		
		vector<string> dataVec = split(line,",");
		
		Road* road = new Road(stoi(dataVec.at(0)),stoi(dataVec.at(1)),stoi(dataVec.at(2)),stoi(dataVec.at(3)),stoi(dataVec.at(4)),stoi(dataVec.at(5)),stoi(dataVec.at(6)));
		
		try{
			_roadVec->push_back(road);
		}
		catch(exception& e){
			cout<<e.what();
		}
	}
	readStream.close();
}

/*
* Brief: This function a subfunction which is used to handle cross file and
* 		 transform it to cross information.
*/	
void FileHandle::transformCrossData()
{
	ifstream readStream;
	readStream.open(_crossFilePath.data(),ios::in);
	assert(readStream.is_open());
	
	string line;
	while(getline(readStream,line))
	{
		if(line.find("#") != string::npos)
			continue;
		line = line.substr(1,line.length()-2);
		
		unsigned int index = 0;
		while((index = line.find(' ',index)) != string::npos)
		{
			line.erase(index,1);
		}
		
		vector<string> dataVec = split(line,",");
		
		Cross* cross = new Cross(stoi(dataVec.at(0)),stoi(dataVec.at(1)),stoi(dataVec.at(2)),stoi(dataVec.at(3)),stoi(dataVec.at(4)));
		
		try{
			_crossVec->push_back(cross);
		}
		catch(exception& e){
			cout<<e.what();
		}
	}
	readStream.close();
}

// Brief: output the car information
vector<Car*>* FileHandle::getCarVector()
{
	if(_carVec->size() != 0)
		return this->_carVec;
	else{
		cout<<"There is no car!"<<endl;
		return NULL;
	}
}

// Brief: output the road information
vector<Road*>* FileHandle::getRoadVector()
{
	if(this->_roadVec->size() != 0)
		return this->_roadVec;
	else{
		cout<<"There is no road!"<<endl;
		return NULL;
	}
}

// Brief: output the cross information
vector<Cross*>* FileHandle::getCrossVector()
{
	if(this->_crossVec->size() != 0)
		return this->_crossVec;
	else{
		cout<<"There is no cross!"<<endl;
		return NULL;
	}
}


