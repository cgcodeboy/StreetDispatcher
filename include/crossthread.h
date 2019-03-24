/*
* Description: This head file is for cross thread, it can run independently, and it need 
*			   the cross to provide the move function to run.
*/

#ifndef CROSS_THREAD_H
#define CROSS_THREAD_H

#include <pthread.h>
#include <unistd.h>
#include "cross.h"

class CrossThread{
private:
	Cross* _cross;
	pthread_t _threadId;
	int _time;
	static void* startThreadFunction(void* thread);
public:
	CrossThread(Cross* cross);
	
	int run(void* thread_context);
};

#endif
