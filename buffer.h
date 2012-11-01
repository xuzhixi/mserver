//===============================================
/**
 *  @file Buffer.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-30 14:24:33
 *  Last   modified:  2012-11-01 10:09:36
 *
 *  Description: 
 */
//================================================

#ifndef __BUFFER_H
#define __BUFFER_H

#include "OPS_IBuffer.h"
#include "OPS_Socket.h"

using OPS::IBuffer;
using OPS::Socket;

class Buffer : public IBuffer
{
	public:
		Buffer(Socket *sk);
		~Buffer();
		void append(char *data, int len);
	
	protected:
		char *searchChar(char *buf, char *finish, char c);
		int residueCpy(char *dst, char *src, char *finish);
		void postPack(char *data, int len);

	private:
		Socket *sk;
		char *buffer;
		int useSize;
		int totalSize;
		char *useEnd;		///< 已接收数据的尾部
		char *pBegin;		///< 数据包起始位置
		char *dBegin;		///< 数据起始位置
		char *lastPos;		///< 最后的搜索位置
		char *sep;			///< 分隔 数据长度和数据 的位置
		int dataLen;		///< 数据的长度
		int status;			///< 3种状态; 1表示查找数据包起始点 2表示查找数据长度与数据的分隔符 3表示直到有足够的数据,就投递一个数据包
};

#endif // __BUFFER_H
