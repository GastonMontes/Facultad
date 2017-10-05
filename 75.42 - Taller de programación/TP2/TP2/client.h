//
//  client.h
//  TP2
//
//  Created by Gastón Montes on 07/10/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#ifndef TP2_client_h
#define TP2_client_h

#include "common_socket.h"

typedef struct {
    Socket sockfd;
} Client;

/**
 * Create the client.
 * @return: ERROR = -1; OK = 0;
 */
int clientCreate(Client *client);

/**
 * Destroy the client/
 */
void clientDestroy(Client *client);

/**
 * Connect the client to the server.
 * @params - server_url: The server url to connect.
 * @params - server_port: The server port to connect.
 * @return: ERROR = -1; OK = 0;
 */
int clientConnect(Client *client, char *server_url, short server_port);

/**
 * Recieve the data from the server.
 */
int clientReceive(Client *client);

#endif
