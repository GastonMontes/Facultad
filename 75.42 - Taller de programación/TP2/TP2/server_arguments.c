//
//  server_arguments.c
//  TP2
//
//  Created by Gastón Montes on 07/10/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "server_arguments.h"

#define ERROR -1
#define OK 0
#define ONE 1
#define TWO 2

void printMessageError() {
    fprintf(stderr,"ERROR: parameters.\n");
    fprintf(stderr,"Usage: ./server <server_port> <files_route>.\n");
}

int serverArgumentsCreate(ServerArguments *arguments, int argc, char *argv[]) {    
    if (argc != 3) {
        printMessageError();
        return ERROR;
    }
    
    // Read the port.
    char *port = malloc(strlen(argv[ONE] + ONE));
    strncpy(port, argv[ONE], strlen(argv[ONE]));
    port[strlen(argv[ONE])] = '\0';
    arguments->server_port = atoi(port);
    free(port);
    
    arguments->data_file_route = malloc(strlen(argv[TWO]) + ONE);
    strncpy(arguments->data_file_route, argv[TWO], strlen(argv[TWO]));
    arguments->data_file_route[strlen(argv[TWO])] = '\0';
    
    return OK;
}

void serverArgumentsDestroy(ServerArguments *arguments) {
    free(arguments->data_file_route);
}

short serverArgumentsPort(ServerArguments *arguments) {
    return arguments->server_port;
}

char *serverArgumentsFileRoute(ServerArguments *arguments) {
    return arguments->data_file_route;
}
