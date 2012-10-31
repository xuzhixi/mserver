//===============================================
/**
 *  @file Buffer.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-30 14:24:33
 *  Last   modified:  2012-10-31 12:32:10
 *
 *  Description: 
 */
//================================================

#ifndef __BUFFER_H
#define __BUFFER_H

class Buffer
{
	public:
		Buffer();
		~Buffer();
		void append(char *data, int len);
	
	protected:
		char *searchChar(char *buf, char *finish, char c);
		void postPack(char *data, int len);
		void residueCpy(char *dst, char *src, char *finish);

	private:
		char *buffer;
		int useSize;
		int totalSize;
		char *useEnd;		///< 已接收数据的尾部
		char *pBegin;		///< 数据包起始位置
		char *dBegin;		///< 数据起始位置
		char *lastPos;		///< 最后的搜索位置
		char *sep;			///< 分隔 数据长度和数据 的位置
		int dataLen;		///< 数据的长度
		int status;
};

#endif // __BUFFER_H
