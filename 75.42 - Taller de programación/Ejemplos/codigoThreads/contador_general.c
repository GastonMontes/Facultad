//
//  contador_general.c
//  Ejemplos
//
//  Created by Gastón Montes on 03/09/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#include "contador_general.h"
#include "mutex.h"

void contadorGeneralCreate(ContadorGeneral *contador) {
    contador->cantidad_total = 0;
    mutex_create(&contador->mutex);
}

void contadorGeneralDestroy(ContadorGeneral *contador) {
    mutex_destroy(&contador->mutex);
}

void contadorGeneralIncrementar(ContadorGeneral *contador, int lineas) {
    mutex_lock(&contador->mutex);
    contador->cantidad_total += lineas;
    mutex_unlock(&contador->mutex);
}

int contadorGeneralGetCantidadTotal(ContadorGeneral *contador) {
    mutex_lock(&contador->mutex);
    int valorActual = contador->cantidad_total;
    mutex_unlock(&contador->mutex);

    return valorActual;
}
