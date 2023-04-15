#include "headers/api_calc.h"
#include "headers/api_validation.h"


stack_double process_op(stack_double stack, char c, int *err) {
    double d1, d2;
    switch (c) {
        case '*':
            stack = pop_d(stack, &d1);
            stack = pop_d(stack, &d2);
            stack = append_d(stack, d1 * d2, err);
            break;
        case '+':
            stack = pop_d(stack, &d1);
            stack = pop_d(stack, &d2);
            stack = append_d(stack, d1 + d2, err);
            break;
        case '-':
            stack = pop_d(stack, &d1);
            stack = pop_d(stack, &d2);
            stack = append_d(stack, d2 - d1, err);
            break;
        case '/':
            stack = pop_d(stack, &d1);
            stack = pop_d(stack, &d2);
            if (d1 == 0) {
                *err = 0;
            } else {
                stack = append_d(stack, d2 / d1, err);
            }
            break;
        case '^':
            stack = pop_d(stack, &d1);
            stack = pop_d(stack, &d2);
            if (d1 == 0) {
                *err = 0;
            } else {
                stack = append_d(stack, pow(d2, d1), err);
            }
            break;
        case '?':
            stack = pop_d(stack, &d1);
            if (d1 == 0) {
                *err = 0;
            } else {
                stack = append_d(stack, -d1, err);
            }
            break;
        case 'q':
            stack = pop_d(stack, &d1);
            if (d1 < 0) {
                *err = 0;
            } else {
                stack = append_d(stack, sqrt(d1), err);
            }
            break;
        case 's':
            stack = pop_d(stack, &d1);
            stack = append_d(stack, sin(d1), err);
            break;
        case 'c':
            stack = pop_d(stack, &d1);
            stack = append_d(stack, cos(d1), err);
            break;
        case 'a':
            stack = pop_d(stack, &d1);
            stack = append_d(stack, tan(d1), err);
            break;
        case 'g':
            stack = pop_d(stack, &d1);
            stack = append_d(stack, 1. / tan(d1), err);
            break;
        case 'l':
            stack = pop_d(stack, &d1);
            stack = append_d(stack, log(d1), err);
            break;
        case 'w':
            stack = pop_d(stack, &d1);
            stack = append_d(stack, acos(d1), err);
            break;
        case 'e':
            stack = pop_d(stack, &d1);
            stack = append_d(stack, asin(d1), err);
            break;
        case 'r':
            stack = pop_d(stack, &d1);
            stack = append_d(stack, atan(d1), err);
            break;
    }
    return stack;
}

double calc_polish(string rpm, double x) {
    int err = 0;
    double data = 0;
    double res_data = 0;
    int count = 0;
    stack_double stack = init_stack_double(&err);

    for (int i = 0; i < rpm.len && !err; i++) {
        while (*(rpm.str + i)) i++;
        count = sscanf(rpm.str + i + 1, "%lf", &data);
        if (count == 1) {
            stack = append_d(stack, data, &err);
        } else {
            if (rpm.str[i + 1] == 'x') {
                stack = append_d(stack, x, &err);
            } else {
                stack = process_op(stack, rpm.str[i + 1], &err);
            }
        }
    }
    stack = pop_d(stack, &res_data);
    return res_data;
}

stack_char to_pn(string s_str, int *err) {
    int is_unar = 1;
    char data = 0;
    stack_char stac_out = init_stack_char(err);
    stack_char stac_oper = init_stack_char(err);
    for (int i = 0; i < s_str.len && !*err; i++) {
        char c = s_str.str[i];
        if (is_digit(c)) {
            is_unar = 0;
            stac_out = append_c(stac_out, c, err);
        } else if (c == 'x') {
            is_unar = 0;
            stac_out = append_c(stac_out, 0, err);
            stac_out = append_c(stac_out, 'x', err);
            stac_out = append_c(stac_out, 0, err);

        } else {
            if (is_unar && c == '-') c = '?';

            is_unar = 1;

            if (c == '(') {
                stac_oper = append_c(stac_oper, c, err);
            } else {
                if (stac_oper.len) {
                    while (stac_oper.len && check_prior(stac_oper.start[stac_oper.len]) >=
                                            check_prior(c)) {
                        stac_out = append_c(stac_out, 0, err);
                        stac_oper = pop_c(stac_oper, &data);
                        stac_out = append_c(stac_out, data, err);
                        stac_out = append_c(stac_out, 0, err);
                    }
                } else {
                    stac_out = append_c(stac_out, 0, err);
                }
                if (c == ')') {
                    stac_oper = pop_c(stac_oper, &data);
                } else {
                    stac_oper = append_c(stac_oper, c, err);
                }
            }
        }
    }
    for (int i = stac_oper.len; i > 0; i--) {
        stac_oper = pop_c(stac_oper, &data);
        stac_out = append_c(stac_out, 0, err);
        stac_out = append_c(stac_out, data, err);
        stac_out = append_c(stac_out, 0, err);
    }
    delete_c(stac_oper);
    return stac_out;
}

double process_calc(string inp, double x) {
    string ss = {0};
    int check = 0;
    cast_string(inp);
    stack_char sc = to_pn(inp, &check);
    ss.len = sc.len;
    ss.str = sc.start;
    return calc_polish(ss, x);
}
