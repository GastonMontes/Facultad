//
//  client_arguments.c
//  TP2
//
//  Created by Gastón Montes on 07/10/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "client_arguments.h"

#define ERROR -1
#define OK 0
#define ONE 1
#define TWO 2
#define ARGUMENTS_SEPARATOR ":"

void printMessageError() {
    fprintf(stderr,"ERROR: parameters.\n");
    fprintf(stderr,"Usage: ./client hostname:hostport.\n");
}

int clientArgumentsCreate(ClientArguments *arguments, int argc, char *argv[]) {
    if (argc != TWO) {
        printMessageError();
        return ERROR;
    }
    
    // Read the url name.
    char remote_url;
    if (sscanf(argv[ONE], "%[^:]%*c%*s", &remote_url) != ONE) {
        printMessageError();    }
    arguments->remote_url = malloc(strlen(&remote_url) + ONE);
    strncpy(arguments->remote_url, &remote_url, strlen(&remote_url));
    arguments->remote_url[strlen(&remote_url)] = '\0';
    
    // Read the port.
    char remote_port;
    if (sscanf(argv[ONE], "%*[^:]%*c%s", &remote_port) != ONE) {
        printMessageError();
    }
    char *port = malloc(strlen(&remote_port) + ONE);
    strncpy(port, &remote_port, strlen(&remote_port));
    port[strlen(&remote_port)] = '\0';
    arguments->remote_port = atoi(port);
    free(port);
    
    return OK;
}

void clientArgumentsDestroy(ClientArguments *arguments) {
    free(arguments->remote_url);
}

char *clientArgumentsURL(ClientArguments *arguments) {
    return arguments->remote_url;
}

short clientArgumentsPort(ClientArguments *arguments) {
    return arguments->remote_port;
}
