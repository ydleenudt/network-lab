//UDP client
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
	SOCKET sockClient=socket(AF_INET,SOCK_DGRAM,0);
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr=inet_addr("222.25.177.246");
	addrSrv.sin_family=AF_INET;
	addrSrv.sin_port=htons(6000);
	char c[2];
	cin>>c;
	sendto(sockClient,c,strlen(c)+1,0,
		(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));
	closesocket(sockClient);
	WSACleanup();
}
