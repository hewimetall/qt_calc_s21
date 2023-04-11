//
// Created by xx on 3/20/23.
//
#include "s21_test.h"

START_TEST(test_process_calc_default)
{
    string ss = {
            .len = 3,
            .str = "1+2"
    };
    double result = process_calc(ss, 0);
    ck_assert_double_eq(result, 3);
}
END_TEST

START_TEST(test_process_calc)
{
    // создаем входные данные
    string inp = {4, "2+2"};
    double x = 0;

    // запускаем функцию, которую тестируем
    double result = process_calc(inp, x);

    // проверяем результат
    ck_assert_double_eq(result, 4);
}
END_TEST

START_TEST(test_process_calc_with_x)
{
    // создаем входные данные
    string inp = {6, "x^2+1"};
    double x = 2;

    // запускаем функцию, которую тестируем
    double result = process_calc(inp, x);

    // проверяем результат
    ck_assert_double_eq(result, 5);
}
END_TEST


// Функция для запуска тестов
Suite* test_process_calc_suite(void)
{
    // Создание тестовой сборки
    Suite* suite = suite_create("process_op");

    // Регистрация тестов
    TCase* tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_process_calc_default);
    tcase_add_test(tc_core, test_process_calc);
    tcase_add_test(tc_core, test_process_calc_with_x);
    suite_add_tcase(suite, tc_core);

    return suite;
}
