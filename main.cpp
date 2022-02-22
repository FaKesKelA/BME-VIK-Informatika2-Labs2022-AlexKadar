#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "winsock2.h"
#pragma comment(lib, "WS2_32.lib") //Properties/Linker/ws2_32.lib
//cringe csak windows-on megy a winsock2, itt csak gépelek


int main(int argc, char* argv[])
{
	// Ellenőrzés
	if(argc < 5)
	{
		printf("Használat: %s IP port oldal f·jl\n", argv[0]);
		return 1;
	}

	// Winsock inicializálása
	WSADATA	wsd;
	if(WSAStartup(0x0202, &wsd) != 0)
	{
		perror("WSAStartup");
		return 1;
	}

	//socket létrehozása 
    SOCKET sock = socket(PF_INET, SOCK_STREAM, 0);
	
	WSACleanup();

	return 0;
}

