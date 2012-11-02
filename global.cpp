//===============================================
/**
 *  @file global.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-30 22:12:15
 *  Last   modified:  2012-11-02 10:41:18
 *
 *  Description: 
 */
//================================================

#include "OPS_TcpServer.h"
#include "OPS_ThreadPool.h"
#include "OPS_DbConnectPool.h"
#include "global.h"
#include "Online.h"
#include "SendThreadPool.h"

using OPS::TcpServer;
using OPS::ThreadPool;
using OPS::DbConnectPool;

TcpServer g_server;
ThreadPool *g_analyse_pools;		///< 分析已接收数据包的线程池
DbConnectPool g_dbconnect_pools;	///< 数据库连接池
Online online;						///< 在线信息对象
SendThreadPool *g_send_pools;		///< 发送数据线程池

