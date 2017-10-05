//
//  files.h
//  TP1
//
//  Created by Gastón Montes on 06/09/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#include <stdio.h>

#ifndef TP1_files_h
#define TP1_files_h

typedef enum {
    FilesOperationCodeSuccess,
    FilesOperationCodeFail,
} FilesOperationCode;

typedef enum {
    FilesReadOperationCodeFail,
    FilesReadOperationCodeSuccess,
    FilesReadOperationCodeEndOfFile
} FilesReadOperationCode;

typedef struct {
    FILE *input_file;
    FILE *output_file;
    FilesOperationCode operation_code;
} Files;

/**
 * Create the files.
 * @params - files_count: The number of arguments.
 * @params - input_file_name: the name of the imput file.
 * @params - output_file_name: the name of the output file, it could be NULL if there is no output file.
 */
void filesCreate(Files *files, int count, char *input_name, char *output_name);

/**
 * Close both files.
 */
void filesDestroy(Files *files);

/**
 * Fill the line read from the file to buffer.
 * @params - number_of_elements: Maxium number of chars to read.
 * @return: FilesReadOperationCodeSuccess bytes were read, FilesReadOperationCodeFail could not read or FilesReadOperationCodeEndOfFile end of file.
 */
FilesReadOperationCode filesReadLine(Files *files, 
                                     char *buffer, 
                                     int number_of_elements);

/**
 * Seek into the file to sequence_file_position and fill the line read to sequence_buffer.
 * @params - number_of_elements: Maxium number of chars to read.
 * @params - sequence_file_position: The relative position to the file init to seek.
 * @return: FilesReadOperationCodeSuccess bytes were read, FilesReadOperationCodeFail could not read or FilesReadOperationCodeEndOfFile end of file.
 */
FilesReadOperationCode filesReadLineInPosition(Files *files, 
                                               char *sequence_buffer, 
                                               int number_of_elements, 
                                               long sequence_file_position);

/**
 * Print buffer into output file or standar output.
 */
void filesPrint(Files *files, char *buffer);

#endif
