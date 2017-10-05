//
//  arguments_parser.c
//  TP1
//
//  Created by Gastón Montes on 02/09/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#include <stdio.h>
#include "arguments_parser.h"

static int const FIRST_ARGUMENT_INDEX   = 1;
static int const SECOND_ARGUMENT_INDEX  = 2;

// pragma mark - Private methods.
void argumentsParserParseArguments(ArgumentsParser *parser, 
                                   int arguments_count) {
    switch (arguments_count) {
        case 0:
            parser->parse_validation = ArgumentsParserCodeNoArguments;
            break;
        case 1:
            // No arguments passed.
            parser->parse_validation = ArgumentsParserCodeNoArguments;
            break;
        case 2:
            // Only 1 argument.
            parser->parse_validation = ArgumentsParserCodeOneArgument;
            break;
        case 3:
            // 2 arguments ok.
            parser->parse_validation = ArgumentsParserCodeTwoArguments;
            break;
        default:
            // More than 2 arguments.
            parser->parse_validation = ArgumentsParserCodeTooManyArguments;
            break;
    }
    parser->arguments_count = arguments_count;
}

void argumentsParserFirstArgument(ArgumentsParser *parser, 
                                  const char *arguments[]) {
    parser->first_argument = NULL;
    if (arguments[FIRST_ARGUMENT_INDEX] != NULL) {
        parser->first_argument = (char *)arguments[FIRST_ARGUMENT_INDEX];
    }
}

void argumentsParserSecondArgument(ArgumentsParser *parser, 
                                   const char *arguments[]) {
    parser->second_argument = NULL;
    if (arguments[SECOND_ARGUMENT_INDEX] != NULL) {
        parser->second_argument = (char *)arguments[SECOND_ARGUMENT_INDEX];
    }
}

// pragma mark - Public methods.
void argumentsParserCreate(ArgumentsParser *arguments_parser, 
                           int arguments_count, 
                           const char *arguments[]) {
    argumentsParserParseArguments(arguments_parser, arguments_count);
    argumentsParserFirstArgument(arguments_parser, arguments);
    argumentsParserSecondArgument(arguments_parser, arguments);
}
