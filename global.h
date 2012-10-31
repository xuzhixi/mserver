//===============================================
/**
 *  @file global.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-30 22:12:11
 *  Last   modified:  2012-10-31 11:42:43
 *
 *  Description: 
 */
//================================================

#ifndef __GLOBAL_H
#define __GLOBAL_H

#include <cstring>
#include <string>
#include "OPS_TcpServer.h"
#include "OPS_Queue.h"
#include "Buffer.h"

using OPS::Socket;
using OPS::TcpServer;
using OPS::Queue;
using std::string;

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


/// 数据包
class Pack
{
	public:
		Pack()
		{
			memset(this, 0, sizeof(*this));
		}
		Socket *sk;
		char data[MAX_PACKAGE_SIZE];	///< 数据
		size_t len;						///< 数据包的总大小
		size_t curLen;					///< 数据包当前大小
		int status;						///< 数据包的状态, 0表示未开始接收, 1	
};

extern TcpServer server;
extern Queue<Pack *> recvPacks;				///< 已接收的数据包
//extern Hash_Map<int, Buffer *> buffers;		///< 接收数据缓冲区
//
//extern Hash_Map<string, Socket *> users;		///< 在线用户
//extern Hash_Map<string, Socket *> aliasUsers;	///< 在线用户别名
//extern Hash_Map<string, list<Socket *> > tagUsers;	///< 在线用户标签队列的hash_map

#endif // __GLOBAL_H
