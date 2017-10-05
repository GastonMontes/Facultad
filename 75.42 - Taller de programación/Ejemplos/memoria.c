//
//  memoria.c
//  Ejemplos
//
//  Created by Gastón Montes on 30/08/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

/*
 int main( int argc, char *argv[])
{
    int *vector1;
    int *vector2;
    
    // correcto
    vector1 = (int *)malloc(10 * sizeof(int));
    
    // incorrecto: falta casting explicito y tamanio de int
//    vector2 = (int *)malloc(10);
    vector2 = (int *)malloc(10 * sizeof(int));
    
    // correcto, se libera memoria
    free(vector1);
    
     incorrecto, se libera dos veces un mismo recurso
//    free(vector1);
    free(vector2);
    
    return 0;
     nunca se libero vector2 SE PIERDE MEMORIA 
}
*/
