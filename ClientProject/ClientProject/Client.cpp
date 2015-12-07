#include "stdafx.h"
#include "Client.h"


Client::Client()
{
}


Client::~Client()
{
}

void Client::app(const char *address)
{
	SOCKET sock = init_connection(address);
	char buffer[BUF_SIZE];


	while (1)
	{

		cout << "Enter a request as:  ask NUMBER" << endl;
		cin.getline(buffer, sizeof(buffer));

		write_server(sock, buffer);
		if (read_server(sock, buffer) == -1)
		{
			continue;
		}
		else
		{
			cout << buffer << endl;
		}
	}
	end_connection(sock);
}



int Client::init_connection(const char *address)
{
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN sin = { 0 };
	struct hostent *hostinfo;

	if (sock == INVALID_SOCKET)
	{
		perror("socket()");
		exit(errno);
	}

	hostinfo = gethostbyname(address);  
	if (hostinfo == NULL)
	{
		fprintf(stderr, "Unknown host %s.\n", address);
		exit(EXIT_FAILURE);
	}

	sin.sin_addr = *(IN_ADDR *)hostinfo->h_addr;
	sin.sin_port = htons(PORT);
	sin.sin_family = AF_INET;

	if (connect(sock, (SOCKADDR *)&sin, sizeof(SOCKADDR)) == SOCKET_ERROR)
	{
		perror("connect()");
		exit(errno);
	}

	return sock;
}

void Client::end_connection(int sock)
{
	closesocket(sock);
}

int Client::read_server(SOCKET sock, char *buffer)
{
	int n = 0;

	if ((n = recv(sock, buffer, BUF_SIZE - 1, 0)) < 0)
	{
		//perror("recv()");
		exit(errno);
	}

	buffer[n] = 0;

	return n;
}

void Client::write_server(SOCKET sock, const char *buffer)
{
	if (send(sock, buffer, strlen(buffer), 0) < 0)
	{
		//perror("send()");
		exit(errno);
	}
	else
	{
		cout << "Request sent successfully" << endl;
	}
}

void Client::init()
{
	WSADATA wsa;
	int err = WSAStartup(MAKEWORD(2, 2), &wsa);
	if (err < 0)
	{
		cout << "WSAStartup failed !" << endl;
		return;
	}
}

void Client::end()
{
	WSACleanup();
}