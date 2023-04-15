#include "test.h"

void run_testcase(Suite *testcase) {
    static int counter_testcase = 1;

    if (counter_testcase > 0) putchar('\n');
    counter_testcase++;
    SRunner *sr = srunner_create(testcase);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    srunner_free(sr);
}

void run_tests(void) {
    Suite *list_cases[] = {
            test_process_op_suite(),
            test_process_calc_suite(),
            test_stack_op_suite(),
            test_valid_suite(),
                           NULL};
    for (Suite **current_testcase = list_cases; *current_testcase != NULL;
         current_testcase++) {
        run_testcase(*current_testcase);
    }
}

int main(void) {
    run_tests();
    return 0;
}
