//===============================================
/**
 *  @file global.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-30 22:12:15
 *  Last   modified:  2012-10-30 22:12:15
 *
 *  Description: 
 */
//================================================

#include "global.h"
#include "OPS_TcpServer.h"
#include "OPS_Queue.h"

using OPS::TcpServer;
using OPS::Queue;

TcpServer server;
Queue<Pack *> recvPacks;
