//
//  string_functions.c
//  TP1
//
//  Created by Gastón Montes on 23/09/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#include "string_functions.h"

#include <stdio.h>
#include <string.h>

char *stringStrtok_r(char *str, const char *delim, char **nextp) {
    char *ret;
    
    if (str == NULL) {
        str = *nextp;
    }
    
    str += strspn(str, delim);
    
    if (*str == '\0') {
        return NULL;
    }
    
    ret = str;
    
    str += strcspn(str, delim);
    
    if (*str) {
        *str++ = '\0';
    }
    
    *nextp = str;
    
    return ret;
}
