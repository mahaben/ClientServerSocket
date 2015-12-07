// ClientProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Client.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Client client;
	client.init();
	client.app("127.0.0.1");
	client.end();
	system("pause");
	return 0;
}

