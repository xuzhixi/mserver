//===============================================
/**
 *  @file MServer.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-30 22:12:52
 *  Last   modified:  2012-11-03 11:37:17
 *
 *  Description: 
 */
//================================================

#include <errno.h>
#include "ky_log.h"
#include "OPS_TcpSocket.h"
#include "OPS_TcpServer.h"
#include "OPS_ThreadPool.h"
#include "OPS_IThread.h"
#include "OPS_IBuffer.h"
#include "MServer.h"
#include "global.h"
#include "Buffer.h"

using OPS::TcpSocket;
using OPS::TcpServer;
using OPS::ThreadPool;
using OPS::IThread;

void MServer::handleConnect(Socket *sk, Reactor *rat)
{
	TcpServer *svr = (TcpServer *)sk;
	TcpSocket *client;

	while ( (client=svr->accept(false)) != NULL )
	{
		KY_LOG_INFO("thread(%lu) coming connect socket(%d) peerIp: %s peerPort: %d", IThread::currentTid(), client->getFd(), client->getPeerIp(), client->getPeerPort());
		client->setRecvBuffer( new Buffer(client) );	// 给新进入的连接，创建一个缓冲区
		g_send_pools->push( client );
		rat->add(client, Reactor::IN, MServer::readyRead);
		//rat->add(client, Reactor::OUT, MServer::readyWrite);
	}

}

void MServer::readyRead(Socket *sk, Reactor *rat)
{
	TcpSocket *socket = (TcpSocket *)sk;
	IBuffer *buffer = socket->getRecvBuffer(); // 获取buffer
	char data[RECEIVE_SIZE];
	ssize_t recvLen;

	while (1)
	{
		recvLen = socket->recv(data, RECEIVE_SIZE);

		if ( recvLen > 0 )			// 有数据可读
		{
			KY_LOG_DEBUG("recv data size %d", recvLen);
			buffer->append( data, recvLen );		
		}
		else if ( recvLen == 0 )	// socket连接断开
		{
			KY_LOG_INFO("peer socket(%d) close", socket->getFd());
			g_send_pools->remove( socket );
			rat->delOwn( socket );
			break;
		}
		else
		{
			if ( errno != EAGAIN )	// 如果不是EAGAIN(表示没有可读数据), 表示发生错误
			{
				KY_LOG_ERROR("socket recv happen error, already close fd=%d", socket->getFd());
				g_send_pools->remove( socket );
				rat->delOwn( socket );
			}
			break;
		}
	}
}

void MServer::readyWrite(Socket *sk, Reactor *rat)
{
	// 第一次连接进来会被触发一次
	KY_LOG_INFO("readyWrite socket(%d)", sk->getFd());
}

