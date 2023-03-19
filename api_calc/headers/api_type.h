//
// Created by xx on 3/12/23.
//

#ifndef QT_CALC_TYPE_H
#define QT_CALC_TYPE_H
typedef struct {
    int x;
    int y;
} point;

typedef struct {
    int len;
    char *str;
} string;

typedef struct {
    char c;
    char *str;
} rule;

typedef struct {
    char c;
    int p;
} priory;

typedef struct {
    int len;
    int max_len;
    double *start;
} stack_double;

typedef struct op {
    char *name;
    char *polperf;
} op;

#endif //QT_CALC_TYPE_H
