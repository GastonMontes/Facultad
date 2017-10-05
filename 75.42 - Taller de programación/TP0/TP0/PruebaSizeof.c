//
//  Prueba.c
//  TP0
//
//  Created by Gastón Montes on 28/08/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#include <stdio.h>

struct employee
{
    int id;
    char name[30];
};

int main( int argc, char *argv[])
{
    // Estos son todos punteros.
    printf("char* %d\n", sizeof(char*));
    printf("int* %d\n", sizeof(int*));
    printf("float* %d\n", sizeof(float*));
    printf("double* %d\n", sizeof(double*));
    
    // Estos son los tipos de datos propiamente dichos.
    printf("char %d\n", sizeof(char));
    printf("int %d\n", sizeof(int));
    printf("float %d\n", sizeof(float));
    printf("double %d\n", sizeof(double));
    
    struct employee e1;
    printf("Size of struct %d\n", sizeof(e1));
    printf("Size of id del struct: %d\n", sizeof(e1.id));
    printf("Size of name del struct: %d\n", sizeof(e1.name));
    
    return 0;
}