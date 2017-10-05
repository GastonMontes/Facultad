//
//  arguments.c
//  TP1
//
//  Created by Gastón Montes on 08/09/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "arguments.h"
#include "string_functions.h"

static char *const kCommaSeparator  = ",";

void argumentsCreate(Arguments *arguments, char *arguments_line) {
    char *token;
    
    // Read equals param value.
    char *save_str;
    token = stringStrtok_r(arguments_line, kCommaSeparator, &save_str);
    arguments->equals = atoi(token);
    
    // Read differents param value.
    token = stringStrtok_r(NULL, kCommaSeparator, &save_str);
    arguments->different = atoi(token);
    
    // Read gap param value.
    token = stringStrtok_r(NULL, kCommaSeparator, &save_str);
    arguments->gap = atoi(token);
    
    // Read max length param value.
    token = stringStrtok_r(NULL, kCommaSeparator, &save_str);
    arguments->max_length = atoi(token);
}
