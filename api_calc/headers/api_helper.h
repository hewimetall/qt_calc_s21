#ifndef QT_CALC_API_HELPER_H
#define QT_CALC_API_HELPER_H
#include "api_type.h"
#define MAX_PRIORITY 4

priory* init_priory();
int check_prior(char c);
int is_digit(char c);
op * get_oper();
#endif //QT_CALC_API_HELPER_H
