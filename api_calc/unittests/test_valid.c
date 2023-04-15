//
// Created by xx on 3/20/23.
//
#include "test.h"

string help_f(const char *arr){
    string st = {strlen(arr), calloc(1, st.len)};
    for (int i = 0; arr[i]; ++i) {
        st.str[i] = arr[i];
    }
    return st;
}
START_TEST(test_input_try)
{

    // создаем входные данные
    string inp[] = {
            help_f("2+-2"),
            help_f("2+(-2)"),
    };
    for (int i = 0; i < 2; ++i) {
        ck_assert_int_eq(check_validation(inp[i]),1);
        free(inp[i].str);
    }
}
END_TEST

START_TEST(test_input_fail)
{
    // создаем входные данные
    string inp[] = {
            {6, "=2+-2"},
            {9, "2+)(-2)"}
    };
    for (int i = 0; i < 2; ++i) {
        ck_assert_int_eq(check_validation(inp[i]), 0);
    }

}
END_TEST


// Функция для запуска тестов
Suite* test_valid_suite(void)
{
    // Создание тестовой сборки
    Suite* suite = suite_create("valid");

    // Регистрация тестов
    TCase* tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_input_try);
    tcase_add_test(tc_core, test_input_fail);
    suite_add_tcase(suite, tc_core);

    return suite;
}
