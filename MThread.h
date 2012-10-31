//===============================================
/**
 *  @file MThread.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-30 22:15:47
 *  Last   modified:  2012-10-30 22:15:47
 *
 *  Description: 
 */
//================================================

#ifndef __MTHREAD_H
#define __MTHREAD_H

#include "OPS_IThread.h"

using OPS::IThread;

class MThread : public IThread
{
	public:
		void run();
};

#endif // __MTHREAD_H


