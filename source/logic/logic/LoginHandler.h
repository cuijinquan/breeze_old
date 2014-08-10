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

#ifndef _LOGIN_HANDLER_H_
#define _LOGIN_HANDLER_H_

#include <MongoManager.h>
#include <BaseHander.h>
#include "../core/GlobalFacade.h"
#include <ProtoDefine.h>
#include <ProtoLogin.h>


class CLoginHandler : public CBaseHandler
{
public:
	CLoginHandler(){}
	~CLoginHandler(){}
	virtual bool Init() override final;
	void msg_GetAccountReq(AccepterID aID, SessionID sID, ProtocolID pID, ReadStreamPack & rs);
	void mongo_GetAccount(std::shared_ptr<mongo::DBClientCursor> & cursor, std::string &errMsg, AccepterID cID, SessionID sID, SessionInfo & info, const ProtoGetAccountInfoReq &req);

private:
};




































#endif
