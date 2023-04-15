//
// Created by xx on 3/20/23.
//
#include "test.h"
START_TEST(test_process_op_multiply)
{
    int err = 0;
    stack_double stack = init_stack_double(&err);

    stack = append_d(stack, 3.0, &err);
    stack = append_d(stack, 4.0, &err);

    stack = process_op(stack, '*', &err);
    double top = 0;
    stack = pop_d(stack, &top);
    ck_assert(err == 0);
    ck_assert_int_eq(err, 0);
    ck_assert_double_eq(top, 12.0);
    ck_assert(stack.len == 0);
}
END_TEST

START_TEST(test_process_op_add)
{    int err = 0;
    stack_double stack = init_stack_double(&err);
    stack = append_d(stack, 3.0, &err);
    stack = append_d(stack, 4.0, &err);

    stack = process_op(stack, '+', &err);
    double top = 0;
    stack = pop_d(stack, &top);

    ck_assert_int_eq(err, 0);
    ck_assert_double_eq(top, 7.0);
    ck_assert(stack.len == 0);
}
END_TEST
START_TEST(test_process_op_subtract)
{
    int err = 0;
    stack_double stack = init_stack_double(&err);
    stack = append_d(stack, 3.0, &err);
    stack = append_d(stack, 4.0, &err);

    stack = process_op(stack, '-', &err);
    double top = 0;
    stack = pop_d(stack, &top);

    ck_assert_int_eq(err, 0);
    ck_assert_double_eq(top, -1.0);
    ck_assert(stack.len == 0);
}
END_TEST

START_TEST(test_process_op_divide)
{
    int err = 0;
    stack_double stack = init_stack_double(&err);
    stack = append_d(stack, 4.0, &err);
    stack = append_d(stack, 2.0, &err);

    stack = process_op(stack, '/', &err);
    double top;
    stack = pop_d(stack, &top);

    ck_assert_int_eq(err, 0);
    ck_assert_double_eq(top, 2.0);

    stack = append_d(stack, 4.0, &err);
    stack = append_d(stack, 0.0, &err);

    stack = process_op(stack, '/', &err);

    ck_assert_int_eq(err, 0);
    ck_assert(stack.len == 0);
    delete_d(stack);
}
END_TEST

START_TEST(test_process_op_power)
{
    int err = 0;
    stack_double stack = init_stack_double(&err);
    stack = append_d(stack, 4.0, &err);
    stack = append_d(stack, 3.0, &err);

    stack = process_op(stack, '^', &err);
    double top = 0;
    stack = pop_d(stack, &top);
    ck_assert_int_eq(err, 0);
    ck_assert_double_eq(top, 64.0);

    stack = append_d(stack, 4.0, &err);
    stack = append_d(stack, 0.0, &err);

    stack = process_op(stack, '^', &err);

    ck_assert_int_eq(err, 0);
    ck_assert(stack.len == 0);
    delete_d(stack);

}
END_TEST

START_TEST(test_process_op_negate)
{
    int err = 0;
    stack_double stack = init_stack_double(&err);
    stack = append_d(stack, 4.0, &err);

    stack = process_op(stack, '?', &err);
    double top;
    stack = pop_d(stack, &top);

    ck_assert_int_eq(err, 0);
    ck_assert_double_eq(top, -4.0);
    ck_assert(stack.len == 0);

    stack = append_d(stack, 0.0, &err);

    stack = process_op(stack, '?', &err);
    stack = pop_d(stack, &top);

    ck_assert_int_eq(err, 0);
    ck_assert_double_eq(top, -1);
    ck_assert(stack.len == 0);

    delete_d(stack);

}
END_TEST

START_TEST(test_process_op_square_root)
{
    int err = 0;
    stack_double stack = init_stack_double(&err);
    stack = append_d(stack, 4.0, &err);

    stack = process_op(stack, 'q', &err);
    double top = 0;
    stack = pop_d(stack, &top);

    ck_assert_int_eq(err, 0);
    ck_assert_double_eq(top, 2.0);

    stack = append_d(stack, -4.0, &err);

    stack = process_op(stack, 'q', &err);

    ck_assert_int_eq(err, 0);
    ck_assert(stack.len == 0);
    delete_d(stack);
}
END_TEST

// Функция для проверки операции вычисления синуса
START_TEST(test_process_op_alter)
{
    int err = 0;
    // Создание стека
    stack_double stack = init_stack_double(&err);

    double top = 1;
    char func[] = {'s','c','a','g','l','w','e','r'};
    int res[] = {8, 5, 15, 6, 0, 0,15, 7};

    for (int i = 0; i < 8; ++i) {
        // Добавление значения в стек
        stack = append_d(stack, 1.0, &err);
        // Выполнение операции вычисления синуса
        stack = process_op(stack, func[i], &err);
        // Вытаскиваем значение
        stack = pop_d(stack, &top);
        ck_assert_int_eq((int ) (top*10.), res[i]);
    }
    // Проверка результата

    delete_d(stack);

}
END_TEST

// Функция для запуска тестов
Suite* test_process_op_suite(void)
{
    // Создание тестовой сборки
    Suite* suite = suite_create("process_op");

    // Регистрация тестов
    TCase* tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_process_op_multiply);
    tcase_add_test(tc_core, test_process_op_add);
    tcase_add_test(tc_core, test_process_op_subtract);
    tcase_add_test(tc_core, test_process_op_divide);
    tcase_add_test(tc_core, test_process_op_power);
    tcase_add_test(tc_core, test_process_op_negate);
    tcase_add_test(tc_core, test_process_op_square_root);
    tcase_add_test(tc_core, test_process_op_alter);
    suite_add_tcase(suite, tc_core);

    return suite;
}
