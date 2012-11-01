//===============================================
/**
 *  @file global.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-30 22:12:15
 *  Last   modified:  2012-11-01 11:02:21
 *
 *  Description: 
 */
//================================================

#include "global.h"
#include "OPS_TcpServer.h"
#include "OPS_ThreadPool.h"
#include "OPS_HashMap.h"
#include "OPS_Mutex.h"
#include "OPS_MutexGuard.h"
#include "OPS_DbConnectPool.h"

using OPS::TcpServer;
using OPS::ThreadPool;
using OPS::Mutex;
using OPS::MutexGuard;
using OPS::DbConnectPool;

TcpServer g_server;
ThreadPool *g_analyse_pools;
DbConnectPool g_dbconnect_pools;

