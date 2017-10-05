//
//  common_process.h
//  TP2
//
//  Created by Gastón Montes on 07/10/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#ifndef TP2_common_process_h
#define TP2_common_process_h

typedef struct {
    int sesion_id;
    char *code;
    char *date;
    int availability;
    long documents[];
} Process;

/**
 * Create a process from a line.
 */
void processCreate(Process *process, char *process_line, int sesion_id);

/**
 * Destroy the process.
 */
void processDestroy(Process *process);

#endif
