//===============================================
/**
 *  @file SendThread.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-11-02 10:32:20
 *  Last   modified:  2012-11-02 10:32:20
 *
 *  Description: 
 */
//================================================

#ifndef __SENDTHREAD_H
#define __SENDTHREAD_H

#include "OPS_IThread.h"
#include "OPS_Queue.h"
#include "OPS_TcpSocket.h"

using OPS::IThread;
using OPS::Queue;
using OPS::TcpSocket;

class SendThread : public IThread
{
	public:
		void push(TcpSocket *sk);
		void remove(TcpSocket *sk);

	protected:
		void run();
	
	private:
		Queue<TcpSocket *> que;
};

#endif // __SENDTHREAD_H
