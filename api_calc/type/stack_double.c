#include "stack_double.h"

#include <stdlib.h>

stack_double init_stack_double(int *err) {
    *err = 0;
    stack_double init_st;
    init_st.len = 0;
    init_st.max_len = 100;
    init_st.start = calloc(1, sizeof(double) * 100);
    return init_st;
}

stack_double delete_d(stack_double stack) {
    if (stack.start) free(stack.start);
    stack.start = 0;
    stack.len = 0;
    stack.max_len = 0;
    return stack;
}

stack_double append_d(stack_double stack, double data, int *err) {
    *err = 0;

    if (stack.start) stack.len++;
    else *err = 1;

    if (stack.len >= stack.max_len && !*err) {
        stack.max_len += 10;
        stack.start = realloc(stack.start, sizeof(double) * stack.max_len);
    }

    if (!*err) {
        stack.start[stack.len] = data;
    }
    return stack;
}

stack_double pop_d(stack_double stack, double *data) {
    if (stack.len == 0) {
        *data = -1;
    } else {
        *data = stack.start[stack.len];
        stack.len--;
    }
    return stack;
}
