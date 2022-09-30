// Server side implementation of UDP client-server model

// UDP Server :  
// 1.Create a UDP socket.
// 2.Bind the socket to the server address.
// 3.Wait until the datagram packet arrives from the client.
// 4.Process the datagram packet and send a reply to the client.
// 5.Go back to Step 3.


//为什么server端需要指定一个端口号呢? 因为client客户端需要在已知的端口号情况下,和server端通信
//而server端在业务设计上是是负责监听来自client客户端的消息,消息里面包含客户端socket的端口号,一般而言,
//这个端口号是由系统自动分配
//然后基于端口号,发送消息给客户端
//https://stackoverflow.com/questions/4118241/what-client-side-situations-need-bind
//What client-side situations need bind()?
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
	
#define PORT	 8080
#define MAXLINE 1024
	
// Driver code
int main() {
	int sockfd;
	char buffer[MAXLINE];
	char *hello = "Hello from server";
	struct sockaddr_in servaddr, cliaddr;
		
	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
		
	memset(&servaddr, 0, sizeof(servaddr)); //初始化结构体分配内存空间
	memset(&cliaddr, 0, sizeof(cliaddr));
		
	// Filling server information
	servaddr.sin_family = AF_INET; // IPv4
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORT);
		
	// Bind the socket with the server address
	if ( bind(sockfd, (const struct sockaddr *)&servaddr,
			sizeof(servaddr)) < 0 )
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
		
	int len, n;
	
	len = sizeof(cliaddr); //len is value/result
	
	n = recvfrom(sockfd, (char *)buffer, MAXLINE,
				MSG_WAITALL, ( struct sockaddr *) &cliaddr,
				&len); //cliaddr从UDP header中获取,个人理解一般来说server跟client是1对多的关系
	buffer[n] = '\0';
	printf("Client : %s\n", buffer);
	sendto(sockfd, (const char *)hello, strlen(hello),
		MSG_CONFIRM, (const struct sockaddr *) &cliaddr,//
			len);
	printf("Hello message sent.\n");
	printf("sockaddr %s",((const struct sockaddr *)&cliaddr)->sa_data);
		
	return 0;
}
