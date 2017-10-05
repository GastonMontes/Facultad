//
//  contador_lineas.c
//  Ejemplos
//
//  Created by Gastón Montes on 03/09/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#include "contador_lineas.h"

/**
 * El statis indica que la función puede ser accedida sólo por el mismo archivo.
 * No tiene el prefijo de archivo (contadorLineas...) porque pertenece al thread.
 * Basicamente es lo que corre el thread.
 */
static void finFun(void *data) {
    ContadorLineas *contador_lineas = (ContadorLineas *)data;
    int cantidad                    = 0;
    FILE *archivo                   = fopen(contador_lineas->nombre_de_archivo, "r");
    char linea[180];
    
    while (fgets(linea, 180, archivo)) {
        cantidad++;
    }
    
    fclose(archivo);
    
    contadorGeneralIncrementar(contador_lineas->contador_general, cantidad);
    salidaSincronizadaImprimir(contador_lineas->salida, contador_lineas->nombre_de_archivo, cantidad);
}

void contadorLineasCreate(ContadorLineas *contador_lineas, ContadorGeneral *contador_general, SalidaSincronizada *salida, char *nombre_de_archivo) {
    contador_lineas->contador_general   = contador_general;
    contador_lineas->salida             = salida;
    contador_lineas->nombre_de_archivo  = nombre_de_archivo;
    thread_crear(&contador_lineas->hilo, finFun, contador_lineas);
}

void contadorLineasDestroy(ContadorLineas *contador_lineas) {
    thread_join(&contador_lineas->hilo);
    thread_destroy(&contador_lineas->hilo);
}

void contadorLineasContar(ContadorLineas *contador_lineas) {
    thread_start(&contador_lineas->hilo);
}
