//===============================================
/**
 *  @file MServer.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-29 13:58:01
 *  Last   modified:  2012-10-29 16:30:24
 *
 *  Description: 
 */
//================================================

#ifndef __MSERVER_H
#define __MSERVER_H

#include "OPS_Socket.h"
#include "OPS_Reactor.h"

using OPS::Socket;
using OPS::Reactor;

class MServer
{
	public:
		static void handleConnect(Socket *sk, Reactor *rat);	// 处理进来的socket连接
		static void readyRead(Socket *sk, Reactor *rat);		// socket可读触发
		static void readyWrite(Socket *sk, Reactor *rat);		// socket可写触发
};
#endif // __MSERVER_H


