//===============================================
/**
 *  @file SendThread.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-11-02 10:32:17
 *  Last   modified:  2012-11-02 10:32:17
 *
 *  Description: 
 */
//================================================

#include "SendThread.h"


void SendThread::push(TcpSocket *sk)
{
	que.push( sk );
}

void SendThread::remove(TcpSocket *sk)
{
	que.remove( sk );
}

void SendThread::run()
{
	int total;
	TcpSocket *sk = NULL;

	while (1)
	{
		total = que.size();
		for (int i=0; i<total; i++)
		{
			que.pop( sk );
			sk->flushQueue();
			que.push( sk );
		}
		usleep( 1000 );
	}
}

