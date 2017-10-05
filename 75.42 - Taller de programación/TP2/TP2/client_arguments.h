//
//  client_arguments.h
//  TP2
//
//  Created by Gastón Montes on 07/10/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#ifndef TP2_client_arguments_h
#define TP2_client_arguments_h

typedef struct {
    char *remote_url;
    short remote_port;
} ClientArguments;

/**
 * Create the client arguments.
 */
int clientArgumentsCreate(ClientArguments *arguments, int argc, char *argv[]);

/**
 * Destroy the client arguments.
 */
void clientArgumentsDestroy(ClientArguments *arguments);

/**
 * Returns the remote url.
 */
char *clientArgumentsURL(ClientArguments *arguments);

/**
 * Returns the remote port to connect.
 */
short clientArgumentsPort(ClientArguments *arguments);

#endif
