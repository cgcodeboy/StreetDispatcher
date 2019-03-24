#include "crossthread.h"

CrossThread::CrossThread(Cross* cross):_cross(cross)
{

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
	thisThread->_cross->move(thisThread->_time);
	return 0;
}
