//
//  contador_lineas.h
//  Ejemplos
//
//  Created by Gastón Montes on 03/09/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#ifndef Ejemplos_contador_lineas_h
#define Ejemplos_contador_lineas_h

#include <stdio.h>
#include <stdlib.h>

#include "thread.h"
#include "contador_general.h"
#include "salida_sincronizada.h"

typedef struct {
    thread_t hilo;
    ContadorGeneral *contador_general; // Todos los contadores de líneas tienen el mismo puntero al contador general.
    SalidaSincronizada *salida;
    char *nombre_de_archivo;
} ContadorLineas;

void contadorLineasCreate(ContadorLineas *contador_lineas, ContadorGeneral *contador_general, SalidaSincronizada *salida, char *nombre_de_archivo);

void contadorLineasDestroy(ContadorLineas *contador_lineas);

void contadorLineasContar(ContadorLineas *contador_lineas);

#endif
