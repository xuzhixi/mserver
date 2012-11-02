//===============================================
/**
 *  @file main.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-29 13:55:26
 *  Last   modified:  2012-11-02 10:42:48
 *
 *  Description: 
 */
//================================================

#include "ky_log.h"
#include "OPS_MultiThread.h"
#include "OPS_Socket.h"
#include "OPS_ThreadPool.h"
#include "MThread.h"
#include "global.h"
#include "SendThreadPool.h"

using OPS::MultiThread;
using OPS::ThreadPool;

int main()
{
	MultiThread<MThread> acceptPools(5);	// accept线程池
	g_analyse_pools = new ThreadPool(5);	// 分析数据包线程池
	g_send_pools = new SendThreadPool(5);	// 发送数据线程池

	if (g_server.init(SOCKET_ADDR_ANY, 8080, false) == false)
	{
		return 1;
	}
	if (g_server.listen(1000) == false)
	{
		return 1;
	}

	// 启动各个线程池
	KY_LOG_INFO("正在启动服务器......");
	//g_dbconnect_pools.load("dbconfig.xml");
	g_send_pools->start();
	g_analyse_pools->start();
	acceptPools.start();
	KY_LOG_INFO("启动服务器成功!");

	// 等待退出
	acceptPools.join();
	g_server.close();
	g_analyse_pools->stop();
	g_send_pools->stop();

	return 0;
}

