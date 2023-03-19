#include "headers/api_helper.h"

op *get_oper() {
    static struct op oper[9] = {
            {"acos", "w"}, {"asin", "e"}, {"atan", "r"},
            {"sqrt", "q"}, {"cos", "c"}, {"sin", "s"},
            {"ctg", "g"}, {"tan", "a"}, {"ln", "l"}
    };
    return oper;
}

priory *init_priory() {
    static priory priority[] = {{.c = '+', .p = 1},
                                {.c = '-', .p = 1},
                                {.c = '*', .p = 2},
                                {.c = '/', .p = 2},
                                {.c = '?', .p = MAX_PRIORITY},
                                {.c = '(', .p = -1},
                                {.c = 'q', .p = MAX_PRIORITY},
                                {.c = 'c', .p = MAX_PRIORITY},
                                {.c = 's', .p = MAX_PRIORITY},
                                {.c = 'g', .p = MAX_PRIORITY},
                                {.c = 'a', .p = MAX_PRIORITY},
                                {.c = 'l', .p = MAX_PRIORITY},
                                {.c = '^', .p = MAX_PRIORITY},
                                {.c = 'w', .p = MAX_PRIORITY},
                                {.c = 'e', .p = MAX_PRIORITY},
                                {.c = 'r', .p = MAX_PRIORITY},
                                {0}

    };
    return priority;
}

int check_prior(char c) {
    static priory *priority;
    int prior = -2;
    if (priority == 0) {
        priority = init_priory();
    }
    for (int i = 0; i < priority->c != 0; i++) {
        if (priority[i].c == c) prior = priority[i].p;
    }
    return prior;
}


int is_digit(char c) {
    int is_digital = 0;
    if ('0' <= c && c <= '9') is_digital = 1;
    if ('.' == c || c == ',') is_digital = 1;
    return is_digital;
}