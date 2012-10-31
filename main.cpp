//===============================================
/**
 *  @file main.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-29 13:55:26
 *  Last   modified:  2012-10-30 04:16:02
 *
 *  Description: 
 */
//================================================

#include "OPS_MultiThread.h"
#include "OPS_Socket.h"
#include "MThread.h"
#include "global.h"

using OPS::MultiThread;

int main()
{
	MultiThread<MThread> threads(5);		// 线程池

	if (server.init(SOCKET_ADDR_ANY, 8080, false) == false)
	{
		return 1;
	}
	if (server.listen(1000) == false)
	{
		return 1;
	}

	threads.start();	// 启动
	threads.join();

	return 0;
}
