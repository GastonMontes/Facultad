//
//  files.c
//  TP1
//
//  Created by Gastón Montes on 06/09/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#include "files.h"
#include "string_functions.h"

#include <string.h>

static char *const kFilesOpenModeRead           = "rb";
static char *const kFilesOpenModeWrite          = "w";
static int const kReadOffset                    = 2;
static char *const kEndOfLine                   = "\n";

void filesCreateInputFile(Files *files, char *input_file_name) {
    if (strlen(input_file_name) > 0) {
        files->input_file   = fopen(input_file_name, kFilesOpenModeRead);
        
        // Input file can not be NULL, output file can.
        if (files->input_file == NULL) {
            files->operation_code = FilesOperationCodeFail;
        } else {
            files->operation_code = FilesOperationCodeSuccess;
        }
    } else {
        files->operation_code = FilesOperationCodeFail;
    }
}

void filesCreateOutputFile(Files *files, char *output_file_name) {
    if (strlen(output_file_name) > 0) {
        files->output_file   = fopen(output_file_name, kFilesOpenModeWrite);
        
        // Input file can not be NULL, output file can.
        if (files->output_file == NULL) {
            files->operation_code = FilesOperationCodeFail;
        } else {
            files->operation_code = FilesOperationCodeSuccess;
        }
    } else {
        files->operation_code = FilesOperationCodeFail;
    }
}

void filesCreate(Files *files, int count, char *input_name, char *output_name) {
    files->input_file   = NULL;
    files->output_file  = NULL;
    
    switch (count) {
        case 2:
            filesCreateInputFile(files, input_name);
            break;
        case 3:
            filesCreateInputFile(files, input_name);
            
            if (files->operation_code != FilesOperationCodeFail) {
                filesCreateOutputFile(files, output_name);
            }
            break;
        default:
            break;
    }
}

void filesDestroy(Files *files) {
    if (files->input_file != NULL) {
        fclose(files->input_file);
    }
    
    if (files->output_file != NULL) {
        fclose(files->output_file);
    }
}

FilesReadOperationCode filesReadLine(Files *files,
                                     char *buffer,
                                     int number_of_elements) {
    // + 2 because fgets read n - 1 characters,
    // or up to \n line stroke or EOF.
    // I must read the \n character too from the line.
    char *read;
    read = fgets(buffer, number_of_elements+kReadOffset, files->input_file);
    
    char *save;
    buffer = stringStrtok_r(buffer, kEndOfLine, &save);
    
    if (feof(files->input_file)) {
        files->operation_code = FilesOperationCodeSuccess;
        return FilesReadOperationCodeEndOfFile;
    }
    
    if (strlen(read) == 0) {
        files->operation_code = FilesOperationCodeFail;
        return FilesReadOperationCodeFail;
    } else {
        files->operation_code = FilesOperationCodeSuccess;
        return FilesReadOperationCodeSuccess;
    }
}

FilesReadOperationCode filesReadLineInPosition(Files *files, 
                                               char *sequence_buffer, 
                                               int number_of_elements, 
                                               long sequence_file_position) {
    fseek(files->input_file, sequence_file_position, SEEK_SET);
    
    return filesReadLine(files, sequence_buffer, number_of_elements);
}

void filesPrint(Files *files, char *buffer) {
    if (files->output_file != NULL) {
        fputs(buffer, files->output_file);
        fputs("\n", files->output_file);
    } else {
        // Write in the standar output.
        printf("%s\n", buffer);
    }
}
