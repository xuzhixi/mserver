//===============================================
/**
 *  @file Online.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-11-01 13:53:39
 *  Last   modified:  2012-11-02 12:25:24
 *
 *  Description: 
 */
//================================================

#ifndef __ONLINE_H
#define __ONLINE_H

#include <string>
#include <list>
#include "OPS_Socket.h"
#include "OPS_HashMap.h"
#include "OPS_Mutex.h"

using std::string;
using std::list;
using OPS::Socket;
using OPS::Mutex;

class Online
{
	public:
		void appendByName(string name, Socket *sk);			///< 添加一个在线用户
		void appendByAlias(string aliasName, Socket *sk);	///< 添加一个在线别名用户
		void appendByDevice(string deviceName, Socket *sk);	///< 为指定设备组添加一个在线用户
		void appendByTag(string tagName, Socket *sk);		///< 为指定标签组添加一个在线用户
		//bool isOnlineUser(string name);					///< 判断某用户是否在线(多个服务器怎么判断?)
		void sendToName(string name, char *msg);		///< 给用户(用户名或别名)发送一条消息
		void sendToTag(string tagName, char *msg);		///< 给标签组发送一条消息 
		void sendToAllDevice(char *msg);				///< 给所有设备发送一条消息
		void sendToAllUser(char *msg);					///< 给所有用户发送一条消息

	protected:
		Socket *getSocketByName(string userName);		///< 根据用户名获取socket
		Socket *getSocketByAlias(string aliasName);     ///< 根据用户别名获取socket

	private:
		HASH_MAP<string, Socket *> users;				///< 在线用户
		Mutex usersMutex;	
		HASH_MAP<string, Socket *> aliasUsers;      	///< 在线别名用户
		Mutex aliasUsersMutex;
		HASH_MAP<string, list<Socket *> > devices;  	///< 在线设备组队列
		Mutex devicesMutex;
		HASH_MAP<string, list<Socket *> > tagUsers; 	///< 在线标签组队列
		Mutex tagUsersMutex;
};

#endif // __ONLINE_H

