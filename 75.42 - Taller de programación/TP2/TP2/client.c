//
//  client.c
//  TP2
//
//  Created by Gastón Montes on 07/10/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#include <netdb.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "client.h"
#include "common_socket.h"

#define ERROR -1
#define ZERO 0 
#define OK 0
#define ONE 1

int clientCreate(Client *client) {
    // Create TCP internet socket.
    if (socketCreate(&client->sockfd) == ERROR) {
        return ERROR;
    }
    
    return OK;
}

void clientDestroy(Client *client) {
    socketDestroy(&client->sockfd);
}

int clientConnect(Client *client, char *server_url, short server_port) {
    if (socketConnect(&client->sockfd, server_url, server_port) == ERROR) {
        return ERROR;
    }
    
    return OK;
}

int clientReceive(Client *client) {
    if (socketReceive(&client->sockfd) == ERROR) {
        return ERROR;
    }
    return OK;
}
