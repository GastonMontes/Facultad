//
//  main.c
//  Ejemplos
//
//  Created by Gastón Montes on 03/09/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "contador_lineas.h"
#include "contador_general.h"
#include "salida_sincronizada.h"

int main(int argc, char *argv[]) {
    ContadorGeneral contador_general;
    SalidaSincronizada salida;
    
    contadorGeneralCreate(&contador_general);
    salidaSincronizadaCreate(&salida, stdout);
    
    ContadorLineas *contadores = malloc(sizeof(ContadorLineas)*(argc - 1));
    
    for (int i = 0; i < argc - 1; i++) {
        contadorLineasCreate(&contadores[i], &contador_general, &salida, argv[i+1]);
        contadorLineasContar(&contadores[i]);
    }
    
    for (int i = 0; i < argc - 1; i++) {
        contadorLineasDestroy(&contadores[i]);
    }
    
    free(contadores);
    
    printf("La cantidad totales %d \n", contadorGeneralGetCantidadTotal(&contador_general));
    
    contadorGeneralDestroy(&contador_general);
    salidaSincronizadaDestroy(&salida);
    
    return 0;
}
