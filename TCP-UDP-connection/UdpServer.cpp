//UDP server
#include <Winsock2.h>
#pragma comment(lib, "ws2_32.lib")    //WINSOCK API连接库文件
#include <stdio.h>
int main()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD( 1, 1 );
	err = WSAStartup( wVersionRequested, &wsaData );
	if ( err != 0 ) {
		return 0;
	}

	if ( LOBYTE( wsaData.wVersion ) != 1 ||
        HIBYTE( wsaData.wVersion ) != 1 ) {
		WSACleanup( );
		return 0;
	}
	SOCKET sockSrv=socket(AF_INET,SOCK_DGRAM,0);
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr=htonl(INADDR_ANY);
	addrSrv.sin_family=AF_INET;
	addrSrv.sin_port=htons(6000);
	bind(sockSrv,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));
	SOCKADDR_IN addrClient;
	int len=sizeof(SOCKADDR);
	char recvBuf[100];

	recvfrom(sockSrv,recvBuf,100,0,(SOCKADDR*)&addrClient,&len);
	printf("%s\n",recvBuf);
	closesocket(sockSrv);
	WSACleanup();
}
