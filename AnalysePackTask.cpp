//===============================================
/**
 *  @file AnalysePackTask.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-11-01 10:04:30
 *  Last   modified:  2012-11-01 10:26:16
 *
 *  Description: 
 */
//================================================

#include <stdlib.h>
#include "ky_log.h"
#include "OPS_IThread.h"
#include "AnalysePackTask.h"

using OPS::IThread;

AnalysePackTask::AnalysePackTask(Socket *sk, char *data)
{
	this->sk = sk;
	this->data = data;
}

AnalysePackTask::~AnalysePackTask()
{
	if ( this->data != NULL )
	{
		free( this->data );
	}
}

bool AnalysePackTask::execute()
{
	if ( this->data != NULL )
	{
		KY_LOG_DEBUG("thread(%u) analyse pack task, data: %s", IThread::currentTid(), data);
		return true;
	}

	return false;
}

