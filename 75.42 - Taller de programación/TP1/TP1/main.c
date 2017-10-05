//
//  main.c
//  TP1
//
//  Created by Gastón Montes on 26/08/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arguments_parser.h"
#include "DNA_sequence.h"
#include "list_node.h"
#include "arguments.h"
#include "files.h"
#include "list.h"

static int const kNormalOutput                  = 0;
static int const kInvalidArguments              = 1;
static int const kFilesError                    = 2;
static int const kMaxNumberOfCharInFirstline    = 64;

FilesReadOperationCode createSequence(Files *files, 
                                      DNASequence *sequence, 
                                      char *buffer, 
                                      Arguments *arguments) {
    long int position_in_file = ftell(files->input_file);
    FilesReadOperationCode operation_read_code;
    operation_read_code = filesReadLine(files, buffer, arguments->max_length);
    
    if (operation_read_code != FilesReadOperationCodeFail) {
        // Create the  sequence.
        dnaSequenceCreate(sequence, position_in_file);
    }
    
    return operation_read_code;
}

void printResults(LinkedList *list, Files *files, Arguments *arguments) {
    struct ListNode *temporal_node = list->head_node;
    
    while (temporal_node != NULL) {
        int kSequenceMaxLength = arguments->max_length;
        char char_to_print[kSequenceMaxLength];
        filesReadLineInPosition(files, char_to_print, 
                                kSequenceMaxLength, 
                                temporal_node->sequence.position_in_file);
        filesPrint(files, char_to_print);
        
        temporal_node = temporal_node->next;
    }
}

FilesReadOperationCode compareSequences(Files *files, 
                                        LinkedList *linked_list, 
                                        Arguments *arguments, 
                                        DNASequence *base_sequence, 
                                        char *base_sequence_string) {
    while (!feof(files->input_file)) {
        DNASequence sequence_to_compare;
        int kSequenceMaxLength = arguments->max_length;
        char sequence_to_compare_string[kSequenceMaxLength];
        FilesReadOperationCode operation_read_code;
        operation_read_code = createSequence(files, 
                                             &sequence_to_compare, 
                                             sequence_to_compare_string, 
                                             arguments);
        
        if (operation_read_code != FilesReadOperationCodeSuccess) {
            return operation_read_code;
        }
        
        dnaSequenceCompare(base_sequence, 
                           base_sequence_string, 
                           &sequence_to_compare, 
                           sequence_to_compare_string, 
                           arguments);
        linkedListAddNode(linked_list, sequence_to_compare);
    }
    
    return FilesReadOperationCodeSuccess;
}

int main(int argc, const char *argv[]) {
    ArgumentsParser arguments_parser;
    DNASequence base_sequence;
    LinkedList *linked_list;
    Arguments arguments;
    Files files;
    
    // Parse the console arguments.
    argumentsParserCreate(&arguments_parser, argc, argv);
    ArgumentsParserCode parse_validation;
    parse_validation = arguments_parser.parse_validation;
    
    if (parse_validation != ArgumentsParserCodeOneArgument 
        && parse_validation != ArgumentsParserCodeTwoArguments) {
        return kInvalidArguments;
    }
    
    // Create the input and output files
    filesCreate(&files, arguments_parser.arguments_count, 
                arguments_parser.first_argument, 
                arguments_parser.second_argument);
    
    if (files.operation_code == FilesOperationCodeFail) {
        // Free the files resources
        filesDestroy(&files);
        return kFilesError;
    }
    
    // Read the first line of the file with the arguments.
    char firstLine[kMaxNumberOfCharInFirstline];
    FilesReadOperationCode operation_read_code; 
    operation_read_code = filesReadLine(&files, 
                                        firstLine, 
                                        kMaxNumberOfCharInFirstline);
    
    if (operation_read_code != FilesReadOperationCodeSuccess) {
        // Can not read the first line with the parameters.
        filesDestroy(&files);
        return kFilesError;
    }
    
    // Create the arguments model.
    argumentsCreate(&arguments, firstLine);
    int kSequenceMaxLenght = arguments.max_length;
    char base_sequence_string[kSequenceMaxLenght];
    
    // Create the base secuence.
    operation_read_code = createSequence(&files, 
                                         &base_sequence, 
                                         base_sequence_string, 
                                         &arguments);
    
    // Read the base sequence string.
    filesReadLineInPosition(&files, 
                            base_sequence_string, 
                            kSequenceMaxLenght, 
                            base_sequence.position_in_file);
    
    // Return file error if can not read the sequence.
    if (operation_read_code == FilesReadOperationCodeFail) {
        // First sequence can not be read.
        filesDestroy(&files);
        return kFilesError;
    }
    
    // Create the list of sequences.
    linkedListCreate(&linked_list);
    
    // Compare secuences to base secuence.
    operation_read_code = compareSequences(&files, 
                                           linked_list, 
                                           &arguments, 
                                           &base_sequence, 
                                           base_sequence_string);
    
    // Return file error if can not read the sequence.
    if (operation_read_code == FilesReadOperationCodeFail) {
        // First sequence can not be read.
        filesDestroy(&files);
        return kFilesError;
    }
    
    printResults(linked_list, &files, &arguments);
     
    linkedListDestroy(linked_list);
    filesDestroy(&files);
    
    return kNormalOutput;
}
