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

	SOCKET sockClient =socket(AF_INET,SOCK_STREAM,0);
	//定义一个SOCKADDR_IN类型的结构体变量，并进行初始化
    SOCKADDR_IN addrCli;
    addrCli.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
    addrCli.sin_family=AF_INET;
    addrCli.sin_port=htons(6000);

    //向服务器发起连接请求
    connect(sockClient,(SOCKADDR*)& addrCli,sizeof(SOCKADDR));

    //接收并打印输出接收数据
    char recvBuf[100];
    recv(sockClient,recvBuf,100,0);
    printf("%s\n",recvBuf);

    //客户端向服务器发送数据
    send(sockClient,"This is lisi",strlen("This is lisi")+1,0);

    closesocket(sockClient);
}
