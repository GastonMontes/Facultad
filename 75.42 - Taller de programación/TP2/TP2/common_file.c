//
//  common_file.c
//  TP2
//
//  Created by Gastón Montes on 07/10/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#include <string.h>

#include "common_file.h"

#define ERROR -1
#define OK 0
#define ZERO 0
#define ONE 1
#define OPEN_MODE_READ "r"
#define END_OF_LINE '\n'

int fileCreate(File *file, char *file_route) {
    if (strlen(file_route) > 0) {
        file->file = fopen(file_route, OPEN_MODE_READ);
        
        if (file->file != NULL) {
            return OK;
        }
    }
    printf("ERROR: No se pudo abrir el archivo de datos: %s.\n", file_route);
    return ERROR;
}

void fileDestroy(File *file) {
    if (file->file != NULL) {
        fclose(file->file);
    }
}

int fileLineLengthCount(File *file) {
    long file_pos = ftell(file->file);
    int count = ZERO;
    
    while (fgetc(file->file) != END_OF_LINE) {
        count++;
    }
    fseek(file->file, file_pos, SEEK_SET);
    return count;
}

void fileReadLine(File *file, char *buffer, int max_data) {
    
    fgets(buffer, max_data + ONE, file->file);
}

FILE *fileAsociatedFile(File *file) {
    return file->file;
}
