//
//  arguments_parser.h
//  TP1
//
//  Created by Gastón Montes on 02/09/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#ifndef TP1_arguments_parser_h
#define TP1_arguments_parser_h

typedef enum {
    ArgumentsParserCodeNoArguments,
    ArgumentsParserCodeOneArgument,
    ArgumentsParserCodeTwoArguments,
    ArgumentsParserCodeTooManyArguments
} ArgumentsParserCode;

typedef struct {
    ArgumentsParserCode parse_validation;
    char *first_argument;
    char *second_argument;
    int arguments_count;
} ArgumentsParser;

void argumentsParserCreate(ArgumentsParser *arguments_parser, 
                           int arguments_count, 
                           const char *arguments[]);

#endif
