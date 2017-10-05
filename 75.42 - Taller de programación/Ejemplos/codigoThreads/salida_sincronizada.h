//
//  SalidaSync.h
//  Ejemplos
//
//  Created by Gastón Montes on 03/09/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#ifndef Ejemplos_SalidaSync_h
#define Ejemplos_SalidaSync_h

#include <stdio.h>
#include <stdlib.h>

#include "mutex.h"

typedef struct {
    FILE *archivo;
    mutex_t mutex;
} SalidaSincronizada;

/**
 * El archivo file debe estar abierto y no me voy a encargar de cerrarlo.
 */
void salidaSincronizadaCreate(SalidaSincronizada *salida, FILE *archivo);

void salidaSincronizadaDestroy(SalidaSincronizada *salida);

void salidaSincronizadaImprimir(SalidaSincronizada *salida, char *nombre_archivo, int lineas);

#endif
