//
//  server_main.c
//  TP2
//
//  Created by Gastón Montes on 07/10/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "server_arguments.h"
#include "common_process.h"
#include "common_file.h"
#include "server.h"

#define ERROR -1
#define ZERO 0
#define ONE 1

int main(int argc, char *argv[])
{
    ServerArguments arguments;
    
    // Arguments parser.
    if (serverArgumentsCreate(&arguments, argc, argv) == ERROR) {
        return ERROR;
    }
    
    File file;
    if (fileCreate(&file, serverArgumentsFileRoute(&arguments)) == ERROR) {
        return ERROR;
    }
    
    int sesion_id = ONE;
    while (!feof(fileAsociatedFile(&file))) {
        long line_length = fileLineLengthCount(&file);
        char buffer[line_length + ONE];
        fileReadLine(&file, buffer, (int)line_length + ONE);
        Process process;
        processCreate(&process, buffer, sesion_id);
        sesion_id++;
    }
    
    // Create server.
    Server server;
    
    if (serverCreate(&server) == ERROR) {
        return ERROR;
    }
    
    if (serverOpen(&server, serverArgumentsPort(&arguments)) == ERROR) {
        return ERROR;
    }
    
    Socket new_sock = serverAccept(&server);
    if (new_sock.sockfd == ERROR) {
        return ERROR;
    }
    
    if (socketSend(&new_sock, NULL) == ERROR) {
        return ERROR;
    }
    
    serverArgumentsDestroy(&arguments);
    serverDestroy(&server);
    socketDestroy(&new_sock);
    fileDestroy(&file);
    
    return ZERO;
}
