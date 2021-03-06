/**
 * Copyright (c) 2000-2013 Liferay, Inc. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 2.1 of the License, or (at your option)
 * any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
 * details.
 */

#include "LiferayNativityExtensionService.h"
#include "ThreadPool.h"
#include "ConfigurationConstants.h"
#include "ParserUtil.h"
#include "NativityMessage.h"

using namespace std;

LiferayNativityExtensionService::LiferayNativityExtensionService(PWSTR pszServiceName, BOOL fCanStop, BOOL fCanShutdown, BOOL fCanPauseContinue)
	: CServiceBase(pszServiceName, fCanStop, fCanShutdown, fCanPauseContinue)
{
	stopped = FALSE;

	stoppedEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
    
	if (stoppedEvent == NULL)
    {
	    throw GetLastError();
    }

	_receiveFromPlugInSocketClient = new CommunicationSocket(SOCKET_PORT_RECEIVE);
	_sendToPlugInSocketClient = new CommunicationSocket(SOCKET_PORT_SEND);

	_serviceWorker = new ServiceWorker();
}

LiferayNativityExtensionService::~LiferayNativityExtensionService(void)
{
    if (stoppedEvent != NULL)
    {
        CloseHandle(stoppedEvent);
        stoppedEvent = NULL;
    }
}

void LiferayNativityExtensionService::OnStart(DWORD dwArgc, LPWSTR *lpszArgv)
{
    WriteEventLogEntry(L"Liferay Nativity Service in OnStart", EVENTLOG_INFORMATION_TYPE);

    CThreadPool::QueueUserWorkItem(&LiferayNativityExtensionService::ServiceWorkerThread, this);
}

void LiferayNativityExtensionService::ServiceWorkerThread(void)
{
	WriteEventLogEntry(L"Liferay Nativity Extension Service worker thread", EVENTLOG_INFORMATION_TYPE);

    while (!stopped)
	{
		wstring* message = new wstring();

		if(_receiveFromPlugInSocketClient->ReceiveResponseOnly(message))
		{
			vector<NativityMessage*>* messages = new vector<NativityMessage*>();

			if(ParserUtil::ParseNativityMessageList(message, messages))
			{
				if(!_serviceWorker->ProcessMessages(messages))
				{
					WriteEventLogEntry(L"Unable to process message", EVENTLOG_INFORMATION_TYPE);
				}
			}
		}

		delete message;
    }

	WriteEventLogEntry(L"Liferay Nativity Extension Service worker thread stopping", EVENTLOG_INFORMATION_TYPE);

    SetEvent(stoppedEvent);
}

void LiferayNativityExtensionService::Test()
{
	ServiceWorkerThread();
}

//   Be sure to periodically call ReportServiceStatus() with 
//   SERVICE_STOP_PENDING if the procedure is going to take long time. 
//
void LiferayNativityExtensionService::OnStop()
{
    WriteEventLogEntry(L"Liferay Nativity Extension Service in OnStop", EVENTLOG_INFORMATION_TYPE);
   
	stopped = TRUE;
    
	if (WaitForSingleObject(stoppedEvent, INFINITE) != WAIT_OBJECT_0)
    {
        throw GetLastError();
    }
}

