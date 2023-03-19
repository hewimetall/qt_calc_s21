#ifndef SRC_VALIDATION_H_
#define SRC_VALIDATION_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "api_type.h"

int check_bracket(char *string);

int check_symbol(char *string);

void replace_substring(char *string, char *substring, char *sub_str_rep);

int check_validation(string ss);

void cast_string(string ss);

#endif  // SRC_VALIDATION_H_
