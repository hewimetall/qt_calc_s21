//
// Created by xx on 3/20/23.
//
#include "test.h"
START_TEST(test_d_create)
{
    int err = 0;
    stack_double stack = init_stack_double(&err);
    ck_assert_ptr_nonnull(stack.start);
    stack.max_len = 10;
    stack.len = 9;
    stack = delete_d(stack);
    ck_assert_ptr_null(stack.start);
}
END_TEST

START_TEST(test_d_filo)
{
    int err = 0;
    double top = 12.25;
    stack_double stack = init_stack_double(&err);
    stack = append_d(stack, top, &err);
    stack = pop_d(stack, &top);
    ck_assert_int_eq(err, 0);
    ck_assert_double_eq(top, 12.25);
    ck_assert(stack.len == 0);
    stack.max_len = 10;
    stack.len = 9;
    stack = append_d(stack, top, &err);
    ck_assert_int_eq(stack.max_len, 20);
    stack = delete_d(stack);
    stack = pop_d(stack, &top);
    stack = append_d(stack, top, &err);
    ck_assert_int_eq(err, 1);
    ck_assert_int_eq(top, -1);
}
END_TEST

START_TEST(test_c_create)
{
    int err = 0;
    stack_char stack = init_stack_char(&err);
    ck_assert_ptr_nonnull(stack.start);
    stack.max_len = 10;
    stack.len = 9;
    stack = delete_c(stack);
    ck_assert_ptr_null(stack.start);
}
END_TEST

START_TEST(test_c_filo)
{
    int err = 0;
    char  top = 'a';
    stack_char stack = init_stack_char(&err);
    stack = append_c(stack, top, &err);
    stack = pop_c(stack, &top);
    ck_assert_int_eq(err, 0);
    ck_assert_int_eq(top, 'a');
    ck_assert(stack.len == 0);
    stack.max_len = 10;
    stack.len = 9;
    stack = append_c(stack, top, &err);
    ck_assert_int_eq(stack.max_len, 20);
    stack = delete_c(stack);
    stack = pop_c(stack, &top);
    stack = append_c(stack, top, &err);
    ck_assert_int_eq(err, 0);
    ck_assert_int_eq(top, -1);
}
END_TEST


// Функция для запуска тестов
Suite* test_stack_op_suite(void)
{
    // Создание тестовой сборки
    Suite* suite = suite_create("stack");

    // Регистрация тестов
    TCase* tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_d_create);
    tcase_add_test(tc_core, test_d_filo);
    tcase_add_test(tc_core, test_c_create);
    tcase_add_test(tc_core, test_c_filo);

    suite_add_tcase(suite, tc_core);

    return suite;
}
