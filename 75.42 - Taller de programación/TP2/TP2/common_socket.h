//
//  common_socket.h
//  TP2
//
//  Created by Gastón Montes on 07/10/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#ifndef TP2_common_socket_h
#define TP2_common_socket_h

#include <sys/socket.h>

typedef struct {
    int sockfd;
} Socket;

/**
 * Create a new socket and asociate it to adrres url and port.
 * Returns the success of the operation.
 */
int socketCreate(Socket *sockfd);

/**
 * Destroy the socekt.
 * Returns the success of the operation.
 */
void socketDestroy(Socket *sockfd);

/**
 * Bind sockfd to localhost with port.
 * Returns the success of the operation.
 */
int socketBind(Socket *sockfd, short port);

/**
 * Start listening sockfd.
 * Returns the success of the operation.
 */
int socketListen(Socket *sockfd);

/**
 * Return a new socket with the file descriptor of the socket accepted.
 */
Socket socketAccept(Socket *sockfd);

/**
 * Send data to sockfd.
 * Returns the success of the operation.
 */
int socketSend(Socket *sockfd, void *data);

/**
 * Connect sockfd to host in url with port.
 * Returns the success of the operation.
 */
int socketConnect(Socket *sockfd, char *url, short port);

/**
 * Recieve data from host.
 * Returns the success of the operation.
 */
int socketReceive(Socket *sockfd);

#endif
