﻿
/*
* breeze License
* Copyright (C) 2014 YaweiZhang <yawei_zhang@foxmail.com>.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/


/*
*  文件说明
*  网络管理类
*  提供服务节点的网络模块配置启动,维护网络的连接/断开,心跳脉冲, 节点注册, 默认消息处理等.
*  提供所有人较原始的网络访问接口.
*/



#ifndef _NET_MANAGER_H_
#define _NET_MANAGER_H_
#include <ServerConfig.h>
#include <ProtoDefine.h>
#include <ProtoAuth.h>
#include "../core/GlobalFacade.h"
#include <unordered_map>
/*
* NetManager
*/


class CNetManager
{
public:
	CNetManager();
	//连接所有认证服务和中央服务
	bool Start();
	void event_OnSessionEstablished(SessionID sID);
	void event_OnSessionDisconnect(SessionID sID);

	void msg_SessionServerAuth(SessionID sID, ProtoID pID, ReadStreamPack & rs);

	void msg_DefaultSessionReq(SessionID sID, ProtoID pID, ReadStreamPack & rs);
	
	void event_OnSessionPulse(SessionID sID, unsigned int pulseInterval);
	void msg_OnSessionPulse(SessionID sID, ProtoID pID, ReadStreamPack & rs);


private:
	bool m_bListening = false;
	tagAcceptorConfigTraits m_configListen; //保存监听配置
	std::unordered_map<SessionID, tagConnctorConfigTraits> m_configConnect; //cID 对应的连接配置
	std::vector<ServerAuthSession> m_onlineSession;
};




































#endif
