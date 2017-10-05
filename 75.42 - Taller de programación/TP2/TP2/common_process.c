//
//  common_process.c
//  TP2
//
//  Created by Gastón Montes on 07/10/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "common_process.h"

#define ONE 1
#define CODE_MAX_LEN 8
#define DATE_MAX_LEN 5
#define OTHERS_MAS_LEN 10
#define PROCESS_REG_EXP "%8[^|]%*c%5[^|]%*c%10[^|]%*c%*c%s"
#define DOCS_REG_EXP "%10[^|]%*c%s"

void processCreate(Process *process, char *process_line, int sesion_id) {
    process->sesion_id = sesion_id;
    process->code = malloc(sizeof(char)*(CODE_MAX_LEN));
    process->date = malloc(sizeof(char)*(DATE_MAX_LEN));
    
    long line_len = strlen(process_line);
    
    char code[CODE_MAX_LEN + ONE];
    char date[DATE_MAX_LEN + ONE];
    char availability[OTHERS_MAS_LEN + ONE];
    char other_line[line_len];
    
    sscanf(process_line, PROCESS_REG_EXP, code, date, availability, other_line);
    strncpy(process->code, code, CODE_MAX_LEN);
    strncpy(process->date, date, DATE_MAX_LEN);
    process->availability = atoi(availability);
    
    char document[OTHERS_MAS_LEN + ONE];
    while (sscanf(other_line, DOCS_REG_EXP, document, other_line) == 2) {
    }
}

void processDestroy(Process *process) {
    free(process->code);
    free(process->date);
}
