#include "crossthread.h"

CrossThread::CrossThread(Cross* cross):_cross(cross)
{
	//cout<<_cross->getId();
}
	
int CrossThread::run(void* thread_context)
{
	_time = *(static_cast<int*>(thread_context));
	int retCode = pthread_create(&_threadId,NULL,startThreadFunction,this);
	if(retCode != 0)
	{
		cout<<"thread create error, error code: "<<retCode<<endl;
		return -1;
	}
	return 0;
}

void* CrossThread::startThreadFunction(void* thread)
{
	CrossThread* thisThread = (CrossThread*)thread;
	//cout<<thisThread->_threadId;
	//cout<<"ya"<<thisThread->_cross->getId();
	thisThread->_cross->move(thisThread->_time);
	return 0;
}
