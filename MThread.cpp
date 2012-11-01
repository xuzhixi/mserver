//===============================================
/**
 *  @file MThread.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-30 03:52:40
 *  Last   modified:  2012-10-30 04:12:40
 *
 *  Description: 
 */
//================================================

#include "MServer.h"
#include "MThread.h"
#include "OPS_Reactor.h"
#include "global.h"

using OPS::Reactor;

void MThread::run()
{
	Reactor rat;

	rat.init(10000, Reactor::ET);
	rat.add( &g_server, Reactor::IN, MServer::handleConnect);
	rat.eventLoop();
}
