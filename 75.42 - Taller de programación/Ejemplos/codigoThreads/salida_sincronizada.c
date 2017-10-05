//
//  SalidaSync.c
//  Ejemplos
//
//  Created by Gastón Montes on 03/09/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#include "salida_sincronizada.h"

void salidaSincronizadaCreate(SalidaSincronizada *salida, FILE *archivo) {
    salida->archivo = archivo;
    mutex_create(&salida->mutex);
}

void salidaSincronizadaDestroy(SalidaSincronizada *salida) {
    mutex_destroy(&salida->mutex);
}

void salidaSincronizadaImprimir(SalidaSincronizada *salida, char *nombre_archivo, int lineas) {
    mutex_lock(&salida->mutex);
    fprintf(salida->archivo, "El archivo %s tiene %d líneas. \n", nombre_archivo, lineas);
    mutex_unlock(&salida->mutex);
}
