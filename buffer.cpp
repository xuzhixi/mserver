//===============================================
/**
 *  @file Buffer.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-30 14:24:26
 *  Last   modified:  2012-10-31 12:51:53
 *
 *  Description: 
 */
//================================================

#include "ky_log.h"
#include "OPS_String.h"
#include "global.h"
#include "Buffer.h"

using OPS::String;

Buffer::Buffer()
{
	this->buffer = (char *)malloc( MAX_PACKAGE_SIZE );
	memset( this->buffer, 0, MAX_PACKAGE_SIZE );
	this->useSize = 0;
	this->totalSize = MAX_PACKAGE_SIZE;
	this->lastPos = this->buffer;
	this->status = 0;
}

Buffer::~Buffer()
{
	free( this->buffer );
}

void Buffer::append(char *data, int len)
{
	if ( (totalSize-useSize) < len)		// 缓冲区剩余空间不足，则创建更大的缓冲区
	{
		totalSize += MAX_PACKAGE_SIZE;
		char *newBuffer = (char *)malloc( totalSize );
		memset( newBuffer, 0, totalSize );
		memcpy( newBuffer, buffer, useSize );
		free( buffer );
		buffer = newBuffer;
	}
	memcpy( buffer+useSize, data, len );	// 拷贝新的数据
	useSize += len;
	useEnd = buffer + useSize;

	while (1)
	{
		if ( status == 0 )
		{
			char *pos = searchChar(lastPos, useEnd, PACKAGE_BEGIN);
			if ( pos != NULL )
			{
				pBegin = pos;
				lastPos = pBegin + 1;
				status = 1;		// 跳到下一步
				continue;
			}
			lastPos = useEnd;
			break;
		}
		else if ( status == 1 )
		{
			sep = searchChar(lastPos, useEnd, SEPARATOR);	// 字符','用来分隔数据长度和数据的
			if ( sep != NULL )
			{
				int numLen = ( sep-pBegin-1 );
				if ( numLen > 0 && numLen <=5 )	// 数据长度要在5个字符之内
				{
					*sep = '\0';
					dataLen = String::toInt(pBegin+1); 
					if ( dataLen > 0 )
					{
						status = 2;		// 跳到下一步
						continue;
					}
					*sep = SEPARATOR;
				}
				lastPos = pBegin+1;		// 数据长度格式错误，重新搜索包头
				status = 0;
				continue;
			}
			lastPos = useEnd;
			break;
		}
		else if ( status == 2 )
		{
			if ( (useEnd-sep-2) >= dataLen )
			{
				if ( sep[dataLen+1] == PACKAGE_END )	// 找到数据包
				{
					this->postPack(sep+1, dataLen);
					residueCpy(buffer, sep+dataLen+2, useEnd);	// 剩下的内容复制到buffer的首部，重新处理
					useSize -= (sep-pBegin+dataLen+2); 
					useEnd = buffer + useSize;
					lastPos = buffer;
					status = 0;			// 重新开始第一步
					continue;	
				}
				*sep = SEPARATOR;		// 还原分隔符
				lastPos = pBegin+1;		// 包尾格式错误，重新搜索包头
				status = 0;
				continue;
			}
			break;
		}
	}
}

// protected
char *Buffer::searchChar(char *buf, char *finish, char c)
{
	while ( buf != finish )
	{
		if ( *buf == c )
		{
			return buf;
		}
		buf++;
	}

	return NULL;
}

void Buffer::postPack(char *data, int len)
{
	KY_LOG_INFO("recv a package len: %d", len);
}

void Buffer::residueCpy(char *dst, char *src, char *finish)
{
	while ( src != finish )
	{
		*dst = *src;
		dst++;
		src++;
	}
}
