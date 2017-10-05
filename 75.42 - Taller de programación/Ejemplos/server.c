//
//  server.c
//  Ejemplos
//
//  Created by Gastón Montes on 02/10/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h> 
#include<errno.h>
#include<string.h> 
#include<netdb.h>
#include<arpa/inet.h> 
#include<sys/types.h>

extern int errno;
#define SERVER_PORT 4321

int main(int argc, char *argv[])
{
    unsigned int sockfd, newsockfd, clilen;
    struct sockaddr_in cli_addr, serv_addr;
    printf("Creando socket...\n");
    // Creo el socket
    if ((sockfd = socket(AF_INET,SOCK_STREAM,0)) < 0){
        perror("creando socket");
        printf("%s\n",strerror(errno));
        exit(1);
    }
    
    // Lleno de ceros la estructura
    memset((char *)&serv_addr,0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET; // Tipo internet
    serv_addr.sin_port = htons(SERVER_PORT);
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    
    // Enlazo la dirección al socket
    printf("Bindeando...\n");
    if ( bind(  sockfd,
              (struct sockaddr *)&serv_addr,
              (socklen_t)sizeof(struct sockaddr)) < 0 ) {
        perror("bind");
        printf("%s\n",strerror(errno));
        exit(1); 
    }

    printf("Escuchando...\n");
    listen(sockfd,5); // Escucho por conexiones
    printf("Aceptando...\n");
    clilen = (socklen_t)sizeof(cli_addr);
    
    // Acepto la conexión entrante
    newsockfd = accept(sockfd,(struct sockaddr *)&cli_addr,&clilen);
    if (newsockfd < 0){
        perror("acept");
        printf("%sn",strerror(errno));
        exit(1);
    }

    printf("Conexión establecida \n");
    write(newsockfd, "Recibí el mensaje \n", 19);
    close(sockfd);
    return 0; 
}
