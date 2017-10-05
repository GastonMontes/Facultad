//
//  contador_general.h
//  Ejemplos
//
//  Created by Gastón Montes on 03/09/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#ifndef Ejemplos_contador_general_h
#define Ejemplos_contador_general_h

#include <stdio.h>
#include <stdlib.h>

#include "mutex.h"

typedef struct {
    int cantidad_total;
    mutex_t mutex;
    
} ContadorGeneral;

void contadorGeneralCreate(ContadorGeneral *contador);

void contadorGeneralDestroy(ContadorGeneral *contador);

void contadorGeneralIncrementar(ContadorGeneral *contador, int lineas);

int contadorGeneralGetCantidadTotal(ContadorGeneral *contador);

#endif
