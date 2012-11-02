//===============================================
/**
 *  @file SendThreadPool.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-11-02 10:40:35
 *  Last   modified:  2012-11-02 10:40:35
 *
 *  Description: 
 */
//================================================

#ifndef __SENDTHREADPOOL_H
#define __SENDTHREADPOOL_H

#include "SendThread.h"

class SendThreadPool
{
	public:
		SendThreadPool(size_t size);
		~SendThreadPool();
		void push(TcpSocket *sk);
		void remove(TcpSocket *sk);
		void start();
		void stop();

	private:
		size_t size;
		bool isStart;
		SendThread *threads;
};

#endif // __SENDTHREADPOOL_H

