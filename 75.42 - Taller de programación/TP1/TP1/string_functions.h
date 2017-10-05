//
//  string_functions.h
//  TP1
//
//  Created by Gastón Montes on 23/09/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#ifndef TP1_string_functions_h
#define TP1_string_functions_h

/**
 * Safe reimplementation of function strtok_r of <string.h>
 */
char *stringStrtok_r(char *str, const char *delim, char **nextp);

#endif
