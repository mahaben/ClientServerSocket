#include "stdafx.h"
#include "BloomFilterService.h"


BloomFilterService::BloomFilterService(unsigned int port) : Server(port)
{
	// do some tasks to initialize the bloom filter parameters
}


BloomFilterService::~BloomFilterService()
{

}

void BloomFilterService::init()
{
	// do some tasks to construct the bloom filter
}

void BloomFilterService::executeRequest(string query)
{
	cout << query<< endl;
}

void BloomFilterService::destroy()
{
	// do some tasks to destroy the bloom filter parameters
}