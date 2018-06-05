#include <check.h>
#include <stdio.h>
#include "bitMap.h"

START_TEST (test_setBitByNumber)
    {
        int array[3] = {2,-4,8};
        ck_assert_int_eq(0 ,setBitByNumber(array,3, 1, 0));
        ck_assert_int_eq(array, 4294953492);
    }
END_TEST

START_TEST (test_getBitByNumber)
    {
        int array[3] = {2,-4,8};
        ck_assert_int_eq(0,getBitByNumber(array,3, 0));
        ck_assert_int_eq(1,getBitByNumber(array,3,30));
        ck_assert_int_eq(1,getBitByNumber(array,3,92));
        ck_assert_int_eq(0,getBitByNumber(array,3,93));
    }
END_TEST

START_TEST (test_setBitByAddress)
    {
        int a = -7;
        int* p = binarize_s(a);
        setBitByAddress(p,0);
        ck_assert_int_eq(*p,0);
        ck_assert_int_eq(binToInt(p), 2147483641);
    }
END_TEST

START_TEST (test_getBitByAddress)
    {
        int a = 128;
        int* ptr = binarize_s(a);
        ck_assert_int_eq(0,getBitByAddress(ptr));
        a *= -1;
        ptr = binarize_s(a);
        ck_assert_int_eq(1,getBitByAddress(ptr));
    }
END_TEST

Suite *str_suite(void) {
    Suite *suite = suite_create("priority queue");
    TCase *tcase = tcase_create("case");
    tcase_add_test(tcase, test_setBitByNumber);
    tcase_add_test(tcase, test_getBitByNumber);
    tcase_add_test(tcase, test_setBitByAddress);
    tcase_add_test(tcase, test_getBitByAddress);
    suite_add_tcase(suite, tcase);
    return suite;
}

int main(int argc, char *argv[]) {
    int number_failed;
    Suite *suite = str_suite();
    SRunner *runner = srunner_create(suite);
    srunner_run_all(runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return number_failed;
}