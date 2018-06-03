#include <check.h>
#include "bitMap.h"

int areArraysEquals(const int* left, const int* right, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        if(left[i] != right[i])
        {
            return 0;
        }
    }
    return 1;
}

START_TEST (test_setBitByNumber)
{
    int bitMap[8] = {0,0,0,0,0,0,0,0};

    ck_assert_int_eq(setBitByNumber(NULL, 8, 1,0), 1);

    ck_assert_int_eq(setBitByNumber(bitMap, 8, 2,0), 2);

    ck_assert_int_eq(setBitByNumber(bitMap, 8, 1,8), 3);

    ck_assert_int_eq(setBitByNumber(bitMap, 8, 1,0), 0);

    int pattern[8] = {1,0,0,0,0,0,0,0};

    ck_assert(areArraysEquals(bitMap, pattern, 8));

    ck_assert_int_eq(setBitByNumber(bitMap, 8, 1,7), 0);

    pattern[7] = 1;
    ck_assert(areArraysEquals(bitMap, pattern, 8));
}
END_TEST

START_TEST (test_getBitByNumber)
{
    int bitMap[8] = {0,1,3,1,0,1,0,1};

    ck_assert_int_eq(getBitByNumber(NULL, 8,0), NULL);

    ck_assert_int_eq(getBitByNumber(bitMap, 8,8), NULL);

    ck_assert_int_eq(getBitByNumber(bitMap, 8,2), NULL);

    ck_assert_int_eq(getBitByNumber(bitMap, 8, 0), 0);

    ck_assert_int_eq(getBitByNumber(bitMap, 8, 7), 1);
}
END_TEST

START_TEST (test_setBitByAddress)
{
    int bitMap[8] = {0,0,0,0,0,0,0,0};

    ck_assert_int_eq(setBitByAddress(NULL ,1), 1);

    ck_assert_int_eq(setBitByAddress(bitMap ,2), 2);

    ck_assert_int_eq(setBitByAddress(bitMap + 1,1), 0);

    int pattern[8] = {0,1,0,0,0,0,0,0};

    ck_assert(areArraysEquals(bitMap, pattern, 8));

    ck_assert_int_eq(setBitByAddress(bitMap + 7, 1), 0);

    pattern[7] = 1;
    ck_assert(areArraysEquals(bitMap, pattern, 8));
}
END_TEST

START_TEST (test_getBitByAddress)
{
    int bitMap[8] = {0,1,3,1,0,1,0,1};

    ck_assert_int_eq(getBitByAddress(NULL), NULL);

    ck_assert_int_eq(getBitByAddress(bitMap + 2), NULL);

    ck_assert_int_eq(getBitByAddress(bitMap), 0);

    ck_assert_int_eq(getBitByAddress(bitMap + 7), 1);
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