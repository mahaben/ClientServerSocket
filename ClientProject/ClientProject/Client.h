#pragma once
#include <winsock2.h>
#include <stdlib.h>
#include <errno.h>
#include <iostream>
#include <stdio.h>
#define PORT	 2014
#define BUF_SIZE 1024
using namespace std;

class Client
{
public:
	Client();
	~Client();
	void app(const char *address);
	int init_connection(const char *address);
	void end_connection(int sock);
	int read_server(SOCKET sock, char *buffer);
	void write_server(SOCKET sock, const char *buffer);
	void init();
	void end();
};

