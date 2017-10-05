//
//  DNA_sequence.c
//  TP1
//
//  Created by Gastón Montes on 09/09/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "DNA_sequence.h"

static int const kZeroIntValue  = 0;
static int const kOneIntValue   = 1;

void dnaSequenceCreate(DNASequence *sequence, long int position) {
    sequence->comparison_value  = kZeroIntValue;
    sequence->position_in_file  = position;
}

/**
 * Smith-Waterman comparition.
 */
int dnaSequenceCompareSWValue(int **two_dim_array, 
                              int row_position, 
                              int column_position, 
                              Arguments *arguments, 
                              char *base_sequence, 
                              char *sequence_to_compare) {
    int row_index       = row_position - kOneIntValue;
    int column_index    = column_position - kOneIntValue;
    
    // The values that I need to find the max value.
    int gap_value = arguments->gap;
    int left_up_value   = two_dim_array[row_index][column_index];
    int left_value      = two_dim_array[row_position][column_index] + gap_value;
    int up_value        = two_dim_array[row_index][column_position] + gap_value;
    int max_value       = kZeroIntValue;
    
    if (base_sequence[column_index] == sequence_to_compare[row_index]) {
        left_up_value += arguments->equals;
    } else {
        left_up_value += arguments->different;
    }
    
    int values_array[4] = {max_value, left_up_value, left_value, up_value};
    for (int i = 0; i < 4; i++) {
        int value = values_array[i];
        
        if (value > max_value) {
            max_value = value;
        }
    }
    
    return max_value;
}

void dnaSequenceCompare(DNASequence *base_sequence, 
                        char *base_char, 
                        DNASequence *sequence_to_compare, 
                        char *char_to_compare, 
                        Arguments *arguments_values) {
    // + kOneIntValue because the first columns and row of zero.
    unsigned long columns_number    = strlen(base_char) + kOneIntValue;
    unsigned long rows_number       = strlen(char_to_compare) + kOneIntValue;
    
    // rows_number mallocs, one for each row, plus one malloc for array of row
    // arrays.
    // An array of int arrays (a pointer to pointers to ints).
    int **two_dimension_array;
    
    // Allocate an array of rows_number pointers to ints.
    two_dimension_array = (int **)malloc(sizeof(int *) * rows_number);
    
    // For each row, malloc space for its buckets and add it to
    // the array of arrays. (Number of buckets = columns_number).
    for (int i = kZeroIntValue; i < rows_number; i++) {
        two_dimension_array[i] = (int *)malloc(sizeof(int) * columns_number);
    }
    
    // I can access using [] notation:
    // two_dimension_array[i] is a bucket in 2d_array, which is the address of
    // a 1d array, on which you can use indexing to access its bucket int value.
    // Initialize buckets with zero value.
    for (int i = kZeroIntValue; i < rows_number; i++) {
        for (int j = kZeroIntValue; j < columns_number; j++) {
            two_dimension_array[i][j] = 0;
        }
    }
    
    for (int i = kOneIntValue; i < rows_number; i++) {
        for (int j = kOneIntValue; j < columns_number; j++) {
            int compare_value = dnaSequenceCompareSWValue(two_dimension_array, 
                                                          i, 
                                                          j, 
                                                          arguments_values, 
                                                          base_char, 
                                                          char_to_compare);
            two_dimension_array[i][j] = compare_value;
        }
    }
    
    long row_index       = rows_number - kOneIntValue;
    long column_index    = columns_number - kOneIntValue;
    int compare_value = two_dimension_array[row_index][column_index];
    sequence_to_compare->comparison_value = compare_value;
    
    // Free the allocated memory.
    // First free each row and then the arraw of rows.
    for (int i = 0; i < rows_number; i++) {
        free(two_dimension_array[i]);
    }
    free(two_dimension_array);
}
