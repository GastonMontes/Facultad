//
//  common_file.h
//  TP2
//
//  Created by Gastón Montes on 07/10/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#ifndef TP2_common_file_h
#define TP2_common_file_h

#include <stdio.h>

typedef struct {
    FILE *file;
} File;

/**
 * Create a file with the file name file_route.
 * Returns the success of the operation.
 */
int fileCreate(File *file, char *file_route);

/**
 * Destroy the file.
 */
void fileDestroy(File *file);

/**
 * Read one line from the file and put it to buffer.
 */
void fileReadLine(File *file, char *buffer, int max_data);

/**
 * Returns the file asociated to the file.
 */
FILE *fileAsociatedFile(File *file);

/**
 * Count the current line length, counts the '\n' character.
 */
int fileLineLengthCount(File *file);

#endif
