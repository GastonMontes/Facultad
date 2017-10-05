//
//  client_main.c
//  TP2
//
//  Created by Gastón Montes on 07/10/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#include <stdio.h>

#include "client_arguments.h"
#include "client.h"

#define ZERO 0
#define ERROR -1

int main(int argc, char *argv[])
{
    // Arguments parser.
    ClientArguments arguments;
    if (clientArgumentsCreate(&arguments, argc, argv) == ERROR) {
        return ERROR;
    }
    
    Client client;
    if (clientCreate(&client) == ERROR) {
        return ERROR;
    }
    
    char *url = clientArgumentsURL(&arguments);
    short port = clientArgumentsPort(&arguments);
    if (clientConnect(&client, url, port) == ERROR) {
        return ERROR;
    }
    
    if (clientReceive(&client) == ERROR) {
        return ERROR;
    }
    
    clientArgumentsDestroy(&arguments);
    clientDestroy(&client);
    
    return ZERO;
}
