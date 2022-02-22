#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#pragma comment(lib, "WS2_32.lib") //Properties/Linker/ws2_32.lib
//cringe, csak windows-on megy a winsock2, itt csak gépelek

int main(int argc, char* argv[])
{
	// Ellenőrzés
	if(argc < 5)
	{
		printf("Használat: %s IP port oldal fájl\n", argv[0]);
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
    if(sock < 0){
        printf("socket: %d", WSAGetLastError());
        return 1;
    }

    // szerver címe

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    addr.sin_port = htons(atoi(argv[2]));

    // kapcsolódás
    if(connect(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0){
        printf("connect: %d", WSAGetLastError());
        return 1;
    }

    char req[256];
    int reqlen;
    reqlen = sprintf(req, "GET %s HTTP/1.0/r/n/r/n", argv[3]);

    send(sock, req, reqlen, 0);

    char rec[1024];
    int reclen = recv(sock, rec, sizeof(rec)-1, MSG_WAITALL);
    if(reclen < 0){
        printf("recv: %d", WSAGetLastError());
        return 1;
    }

    char version[16];
    int status;
    char error[256];
    if(sscanf(rec, "HTTP/%16s %d %256[^/r/n]/r/n", version, status, error) == 3){
        printf("szerver státusza: %d %s/r/n", status, error);
    }

    char* pdata;
    if((pdata = strstr(rec, "/r/n/r/n")) == NULL){
        printf("Hiba a szétválasztásnál!");
        return 1;
    }

    closesocket(sock); 
	
	WSACleanup();

	return 0;
}

