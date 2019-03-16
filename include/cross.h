/*
* Description:
* This head file is for cross, the cross need id, up road id, down road id,
* left road id, right road id.
*/

#ifndef CROSS_H
#define CROSS_H

class Cross{
private:
	int _id;
	int _upId;
	int _downId;
	int _leftId;
	int _rightId;
	
public:
	Cross(){}
	Cross(int id, int up_id, int right_id, int down_id, int left_id);
	
	void init();
	
	void setId(int id);
	void setUpRoadId(int up_id);
	void setDownRoadId(int down_id);
	void setLeftRoadId(int left_id);
	void setRightRoadId(int right_id);
	
	const int getId();
	const int getUpRoadId();
	const int getDownRoadId();
	const int getLeftRoadId();
	const int getRightRoadId();
};


#endif
