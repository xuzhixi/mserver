//===============================================
/**
 *  @file global.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-30 22:12:11
 *  Last   modified:  2012-11-01 11:02:31
 *
 *  Description: 
 */
//================================================

#ifndef __GLOBAL_H
#define __GLOBAL_H

#include <cstring>
#include <string>
#include "OPS_TcpServer.h"
#include "OPS_ThreadPool.h"
#include "OPS_DbConnectPool.h"

using std::string;
using OPS::TcpServer;
using OPS::ThreadPool;
using OPS::DbConnectPool;

/// 包起始点
#define PACKAGE_BEGIN	'['
/// 包结束点
#define PACKAGE_END		']'
/// 分隔符
#define SEPARATOR		','
/// 包的最大长度
#define MAX_PACKAGE_SIZE 1024
/// 每次接收数据的长度 
#define RECEIVE_SIZE	 512


extern TcpServer g_server;
extern ThreadPool *g_analyse_pools;			///< 分析已接收数据包的线程池
extern DbConnectPool g_dbconnect_pools;		///< 数据库连接池

//extern Hash_Map<string, Socket *> users;		///< 在线用户
//extern Hash_Map<string, Socket *> aliasUsers;	///< 在线用户别名
//extern Hash_Map<string, list<Socket *> > tagUsers;	///< 在线用户标签队列的hash_map

#endif // __GLOBAL_H
