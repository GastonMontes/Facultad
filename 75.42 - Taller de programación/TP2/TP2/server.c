//
//  server.c
//  TP2
//
//  Created by Gastón Montes on 07/10/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#include <netinet/in.h>

#include "server.h"

#define ERROR -1
#define ZERO 0 

int serverCreate(Server *server) {
    if (socketCreate(&server->sockfd) == ERROR) {
        return ERROR;
    }
    
    return ZERO;
}

void serverDestroy(Server *server) {
    socketDestroy(&server->sockfd);
}

// Bind and listen.
int serverOpen(Server *server, short port) {
    
    // Bind socket to localhost and url.
    if (socketBind(&server->sockfd, port) == ERROR) {
        return ERROR;
    }
    
    if (socketListen(&server->sockfd) == ERROR) {
        return ERROR;
    }
    
    return ZERO;
}

Socket serverAccept(Server *server) {
    Socket new_sock = socketAccept(&server->sockfd);
    return new_sock;
}
