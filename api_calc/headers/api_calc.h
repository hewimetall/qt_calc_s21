#ifndef QT_CALC_API_CALC_H
#define QT_CALC_API_CALC_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "api_helper.h"
#include "api_type.h"
#include "api_type.h"
#include "../type/stack_double.h"
#include "../type/stack_char.h"

stack_double process_op(stack_double stack, char c, int* err);
double calc_polish(string rpm, double x);
stack_char to_pn(string s_str, int* err);
#endif
