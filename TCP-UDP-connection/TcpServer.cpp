#include<winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#include<stdio.h>

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
	if ( LOBYTE( wsaData.wVersion ) != 1 || HIBYTE( wsaData.wVersion ) != 1 ) {
		WSACleanup( );
		return 0;
	}

	SOCKET sockSrv=socket(AF_INET,SOCK_STREAM,0);
	//定义一个SOCKADDR_IN类型的结构体变量，并进行初始化
    SOCKADDR_IN addrSrv;
    addrSrv.sin_addr.S_un.S_addr=htonl(INADDR_ANY);
    addrSrv.sin_family=AF_INET;
    addrSrv.sin_port=htons(6000);
    bind(sockSrv,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));
    listen(sockSrv,5);    //5表示等待连接队列的最大数目。

    //客户端地址结构变量
    SOCKADDR_IN addrClient;
    int len=sizeof(SOCKADDR);
    //死循环等待连接、接受客户端请求，建立连接。
    while(1)
    {
        SOCKET sockConn=accept(sockSrv,(SOCKADDR*)&addrClient,&len);
        //将客户端的地址存放到sendBuf中。
        char sendBuf[100];
        sprintf(sendBuf, "%s Welcome！", inet_ntoa(addrClient.sin_addr));

        send(sockConn,sendBuf,strlen(sendBuf)+1,0);

        char recvBuf[100];
        recv(sockConn,recvBuf,100,0);

        printf("%s\n",recvBuf);
        closesocket(sockConn);
    }

}
