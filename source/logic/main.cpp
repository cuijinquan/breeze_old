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

#include "Application.h"
#include <zsummerX/frameX.h>
#include <unordered_map>
using namespace zsummer::log4z;




void sigInt(int sig)
{
	LOGI("catch SIGINT.");
	Appliction::getRef().Stop();
}

int main(int argc, char* argv[])
{

#ifndef _WIN32
//! linux下需要屏蔽的一些信号
	signal( SIGHUP, SIG_IGN );
	signal( SIGALRM, SIG_IGN );
	signal( SIGPIPE, SIG_IGN );
	signal( SIGXCPU, SIG_IGN );
	signal( SIGXFSZ, SIG_IGN );
	signal( SIGPROF, SIG_IGN ); 
	signal( SIGVTALRM, SIG_IGN );
	signal( SIGQUIT, SIG_IGN );
	signal( SIGCHLD, SIG_IGN);
#endif
	signal(SIGINT, &sigInt);
	signal(SIGTERM, &sigInt);

	
	
	std::string filename = "../ServerConfig.xml";
	unsigned int serverIndex = 0;
	if (argc > 1)
	{
		serverIndex = atoi(argv[1]);
	}
	if (argc > 2)
	{
		filename = argv[2];
	}
	bool ret = false;
	ILog4zManager::GetInstance()->Config("../log.config");
	ret = ILog4zManager::GetInstance()->Start();
	if (!ret)
	{
		std::cout << "ILog4zManager start false." << std::endl;
		return ret;
	}


	if (!Appliction::getRef().Init(filename, serverIndex))
	{
		LOGE("Appliction init false.");
		return 1;
	}
	Appliction::getRef().RunPump();

	LOGI("Appliction exit.");

	return 0;
}

