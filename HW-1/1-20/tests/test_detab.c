//
// Created by igor on 28.05.18.
//
#include <check.h>
#include "detab.h"

START_TEST(test_detab)
    {
    char * test = detab("\ttest");
    char * test1 = detab("test\t");
    char * test2 = detab("test\ttest");
    char * test3 = detab("\ttest\t");
    char * answer = "    test";
    ck_assert_str_eq(test, answer);
    ck_assert_str_eq(test1, "test    ");
    ck_assert_str_eq(test2, "test    test");
    ck_assert_str_eq(test3, "    test    ");
}
END_TEST

Suite* str_suite (void) {
    Suite *suite = suite_create("Home assignment 1");
    TCase *tcase = tcase_create("case");

    tcase_add_test(tcase, test_detab);

    suite_add_tcase(suite, tcase);
    return suite;
}

int main (int argc, char *argv[]) {
    int number_failed;
    Suite *suite = str_suite();
    SRunner *runner = srunner_create(suite);
    srunner_run_all(runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return number_failed;
}