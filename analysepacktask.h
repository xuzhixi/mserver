//===============================================
/**
 *  @file AnalysePackTask.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-11-01 10:03:35
 *  Last   modified:  2012-11-01 10:23:33
 *
 *  Description: 
 */
//================================================

#ifndef __ANALYSEPACKTASK_H
#define __ANALYSEPACKTASK_H

#include "OPS_Task.h"
#include "OPS_TcpSocket.h"

using OPS::Task;
using OPS::TcpSocket;

/// 分析数据包
class AnalysePackTask : public Task
{
	public:
		AnalysePackTask(TcpSocket *sk, char *data);
		~AnalysePackTask();
		bool execute();

	private:
		TcpSocket *sk; 
		char *data; ///< 数据
};

#endif // __ANALYSEPACKTASK_H

