//
//  server.h
//  TP2
//
//  Created by Gastón Montes on 07/10/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#ifndef TP2_server_h
#define TP2_server_h

#include "common_socket.h"

typedef struct {
    Socket sockfd;
} Server;

/**
 * Create the server.
 */
int serverCreate(Server *server);

/**
 * Destroy the server/
 */
void serverDestroy(Server *server);

/**
 * Bind and listen the server in the local machine address and in port.
 * @params - port: The port to bind.
 */
int serverOpen(Server *server, short port);

/**
 * Accept a new remote connection.
 */
Socket serverAccept(Server *server);

#endif
