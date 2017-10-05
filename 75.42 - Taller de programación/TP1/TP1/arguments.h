//
//  arguments.h
//  TP1
//
//  Created by Gastón Montes on 08/09/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#ifndef TP1_arguments_h
#define TP1_arguments_h

typedef struct {
    int equals;
    int different;
    int gap;
    int max_length;
} Arguments;

/**
 * @params - arguments_line: the line that contains the arguments in CSV values.
 */
void argumentsCreate(Arguments *arguments, char *arguments_line);

#endif
