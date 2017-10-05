//
//  punteros_2.c
//  Ejemplos
//
//  Created by Gastón Montes on 28/08/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#include <stdio.h>

void swap(int *a, int *b)
{
    int c;
    c   = *a;
    *a  = *b;
    *b  = c;
}

/*int main( int argc, char *argv[])
{
    int a = 2, b = 3;
    
    printf("%d - %d\n", a, b);
    
    swap( &a , &b );
    
    printf("%d - %d\n", a, b);
    
    return 0;
}*/