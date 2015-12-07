// NewImplementation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BloomFilterService.h"


int _tmain(int argc, _TCHAR* argv[])
{
	BloomFilterService bloomFilterService(2014);
	bloomFilterService.start();
	bloomFilterService.stop();
	system("pause");
	return 0;
}

