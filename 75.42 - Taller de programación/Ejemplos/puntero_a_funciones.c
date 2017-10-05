//
//  puntero_a_funciones.c
//  Ejemplos
//
//  Created by Gastón Montes on 30/08/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#include <stdio.h>

int suma (int a, int b)
{
    return a + b;
}

int resta (int a, int b)
{
    return a - b;
}

//int main( int argc, char *argv[])
//{
//    // declaramos un puntero a funciones con dos parámetros enteros que devuelven un entero.
//    int (*funcion) (int,int);
//    int x;
//    
//    funcion = suma; // .funcion. apunta a .suma.
//    x = funcion(4,3); // x=suma(4,3)
//    printf("La suma de 4 mas 3 dio: %d\n", x);
//    
//    funcion = resta; // .funcion. apunta a .resta.
//    x = funcion(4,3); // x=resta(4,3)
//    printf("La suma de 4 menos 3 dio: %d\n", x);
//    
//    return 0;
//}
