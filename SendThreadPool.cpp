//===============================================
/**
 *  @file SendThreadPool.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-11-02 10:32:56
 *  Last   modified:  2012-11-02 10:40:48
 *
 *  Description: 
 */
//================================================

#include "SendThreadPool.h"


SendThreadPool::SendThreadPool(size_t size)
{
	this->threads = new SendThread[size];
	this->size = size;
	this->isStart = false;
}

SendThreadPool::~SendThreadPool()
{
	this->stop();
	delete[] this->threads;
}

void SendThreadPool::push(TcpSocket *sk)
{
	int pos = sk->getFd() % this->size;
	threads[ pos ].push( sk );
}

void SendThreadPool::remove(TcpSocket *sk)
{
	int pos = sk->getFd() % this->size;
	threads[ pos ].remove( sk );
}

void SendThreadPool::start()
{
	if ( !this->isStart )
	{
		this->isStart = true;
		for (size_t i=0; i<(this->size); i++)
		{
			this->threads[i].start();
		}
	}
}
void SendThreadPool::stop()
{
	if ( this->isStart )
	{
		this->isStart = false;
		for (size_t i=0; i<(this->size); i++)
		{
			this->threads[i].stop();
		}
	}   
}

