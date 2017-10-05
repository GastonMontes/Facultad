//
//  DNA_sequence.h
//  TP1
//
//  Created by Gastón Montes on 09/09/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#ifndef TP1_DNA_sequence_h
#define TP1_DNA_sequence_h

#include "arguments.h"

typedef struct {
    int comparison_value;
    long position_in_file;
} DNASequence;

/**
 * @params - sequence_line: the line read from the file that contains the sequence of DNA.
 * @params - position: The position in the file. For example, base sequence is going to hava position = 0;
 */
void dnaSequenceCreate(DNASequence *sequence, long int position);

/**
 * @params - base_sequence: The base sequence to compare.
 * @params - base_sequence_char: The sequence base char.
 * @params - sequence_to_compare: The sequence that I want to compare.
 * @params - sequence_to_compare_char: The sequence to compare char.
 * @params - arguments_values: the argument of Smith-Waterman algorithm.
 */
void dnaSequenceCompare(DNASequence *base_sequence, 
                        char *base_sequence_char, 
                        DNASequence *sequence_to_compare, 
                        char *sequence_to_compare_char, 
                        Arguments *arguments_values);

#endif
