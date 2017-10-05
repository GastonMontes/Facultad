//
//  server_arguments.h
//  TP2
//
//  Created by Gastón Montes on 07/10/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#ifndef TP2_server_arguments_h
#define TP2_server_arguments_h

typedef struct {
    short server_port;
    char *data_file_route;
} ServerArguments;

/**
 * Create the client arguments.
 */
int serverArgumentsCreate(ServerArguments *arguments, int argc, char *argv[]);

/**
 * Destroy the client arguments.
 */
void serverArgumentsDestroy(ServerArguments *arguments);

/**
 * Returns the server port.
 */
short serverArgumentsPort(ServerArguments *arguments);

/**
 * Returns the file route.
 */
char *serverArgumentsFileRoute(ServerArguments *arguments);

#endif
