//
//  common_socket.c
//  TP2
//
//  Created by Gastón Montes on 07/10/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#include <netdb.h>
#include <stdio.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

#include "common_socket.h"

#define ERROR -1
#define OK 0
#define ZERO 0
#define BACKLOG 10
#define MAXDATASIZE 100

int socketCreate(Socket *sockfd) {
    if ((sockfd->sockfd = socket(AF_INET, SOCK_STREAM, ZERO)) == ERROR) {
        perror("ERROR: Client socket error \n");
        printf("%s\n", strerror(errno));
        return ERROR;
    }
    
    return OK;
}

void socketDestroy(Socket *sockfd) {
    close(sockfd->sockfd);
}

int socketBind(Socket *sockfd, short port) {
    
    // Remote connection host data.
    struct sockaddr_in addr_in;
    
    addr_in.sin_family = AF_INET;
    addr_in.sin_port = htons(port);
    addr_in.sin_addr.s_addr = INADDR_ANY; 
    memset(&(addr_in.sin_zero), ZERO, sizeof(addr_in.sin_zero));
    
    struct sockaddr *addr = (struct sockaddr *)&addr_in;
    int sock_addr_size = sizeof(struct sockaddr);
    
    if (bind(sockfd->sockfd, addr, sock_addr_size) == ERROR) {
        perror("ERROR: bind\n");
        printf("%s\n",strerror(errno));
        return ERROR;
    }
    return OK;
}

int socketListen(Socket *sockfd) {
    if (listen(sockfd->sockfd, BACKLOG) == -1) {
        perror("ERROR: listen\n");
        printf("%s\n",strerror(errno));
        return ERROR;
    }
    return OK;
}

Socket socketAccept(Socket *sockfd) {
    struct sockaddr_in cli_addr_in;
    struct sockaddr *cli_addr = (struct sockaddr *)&cli_addr_in;
    socklen_t cli_addr_len = (socklen_t)sizeof(cli_addr);
    
    Socket new_socket;
    new_socket.sockfd = accept(sockfd->sockfd, cli_addr, &cli_addr_len);
    if (new_socket.sockfd == ERROR) {
        perror("ERROR: Server accept socket error");
        printf("%s\n",strerror(errno));
        
    }
    return new_socket;
}

int socketSend(Socket *sockfd, void *data) {
    if (send(sockfd->sockfd, "Te conectaste!\n", 14, 0) == ERROR) {
        perror("ERROR: send\n");
        printf("%s\n",strerror(errno));
        return ERROR;
    }
    return OK;
}

int socketConnect(Socket *sockfd, char *url, short port) {
    // Get remote host information.
    struct hostent *remote_host_info;
    if ((remote_host_info = gethostbyname(url)) == NULL) {
        perror("ERROR: gethostbyname");
        return ERROR; 
    }
    
    // Remote connection host data.
    struct sockaddr_in addr_in;
    
    addr_in.sin_family = AF_INET;
    addr_in.sin_port = htons(port);
    addr_in.sin_addr = *((struct in_addr *)remote_host_info->h_addr); 
    memset(&(addr_in.sin_zero), ZERO, sizeof(addr_in.sin_zero));
    
    struct sockaddr *addr = (struct sockaddr *)&addr_in;
    int sock_addr_size = sizeof(struct sockaddr);
    if (connect(sockfd->sockfd, addr, sock_addr_size) == ERROR) {
        perror("ERROR: Client connect socket error");
        printf("%s\n",strerror(errno));
        return ERROR;
    }
    
    return ZERO;
}

int socketReceive(Socket *sockfd) {
    char buf[MAXDATASIZE];
    int num_bytes = (int)recv(sockfd->sockfd, buf, MAXDATASIZE - 1, 0);
    if (num_bytes == -1) {
        perror("ERROR: recv");
        return ERROR;
    }
    
    buf[num_bytes] = '\0';
    printf("Received: %s\n", buf);
    return OK;
}
