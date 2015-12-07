#pragma once
#include "Server.h"
class BloomFilterService :
	public Server
{
public:
	BloomFilterService(unsigned int port);
	~BloomFilterService();
	virtual void init();
	virtual void executeRequest(string query);
	virtual void destroy();
};

