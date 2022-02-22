#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "winsock2.h"
#pragma comment(lib, "WS2_32.lib")


int main(int argc, char* argv[])
{
	// EllenırzÈs
	if(argc < 5)
	{
		printf("Haszn·lat: %s IP port oldal f·jl\n", argv[0]);
		return 1;
	}

	// Winsock inicializ·l·s
	WSADATA	wsd;
	if(WSAStartup(0x0202, &wsd) != 0)
	{
		perror("WSAStartup");
		return 1;
	}

	// TODO
	
	WSACleanup();

	return 0;
}

