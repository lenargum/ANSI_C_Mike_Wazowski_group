//
// Created by cubazis on 25.05.18.
//

#include <check.h>
#include "task.h"


#define TOL_STRICT 1e-9

#ifndef COMPARATOR
#define COMPARATOR(res, c1, c2) do                  \
    {                                               \
        int i = 0;                                  \
        for (;'\0' != (c1)[i];i++)                  \
        {                                           \
            if((c1)[i] != (c2)[i])                  \
                {                                   \
                    (res) = 0;                      \
                }                                   \
        }                                           \
    } while(0)
#endif

START_TEST (test_stub)
    {
        ck_assert(42 == stub());
    }
END_TEST

START_TEST (test_array_changer)
    {
        const char input[] = "abcba";
        const char pattern[] = "abbba";

        /** change 'c' to 'b' */

        char *output = array_changer(input);

        /** initialise k because ck_assert need's it to be sure
         *  that he compare something initialised with 1
         *  because if COMPARATOR will not change it value, k will not have any value
         *  */
        int k = 1;

        /** get k, k, output, pattern
         *  compare output array with pattern array by elements
         *  return 0 if they are not equal
         * */
        COMPARATOR(k, output, pattern);

        /** check statement is true */
        ck_assert(1 == k);

    }
END_TEST

/** YOUT TEST CASES HERE
 *
 *  please use 'test_fname' format for naming tcases
 *  fname is function name
 *
 *  if function name is 'detab' then test case is 'test_detab'
 * */

START_TEST (test_detab)
    {
        const char input[] = "";
        const char answer[] = "";

        char *test = detab(input);
        ck_assert_str_eq(test, answer);

        const char input1[] = "1\t1";
        const char answer1[] = "1    1";

        char *test1 = detab(input1);
        ck_assert_str_eq(test1, answer1);

        const char input2[] = "1\t\t\t1";
        const char answer2[] = "1            1";

        char *test2 = detab(input2);
        ck_assert_str_eq(test2, answer2);
    }
END_TEST

START_TEST (test_entab)
    {
        const char input[] = "                        ";
        const char answer[] = "\t\t\t\t\t    ";

        char *test = entab(input);
        ck_assert_str_eq(test, answer);

        const char input0[] = "";
        const char answer0[] = "";

        char *test0 = entab(input0);
        ck_assert_str_eq(test0, answer0);

        const char input1[] = "1    ";
        const char answer1[] = "1    ";

        char *test1 = entab(input1);
        ck_assert_str_eq(test1, answer1);

        const char input2[] = "1              ";
        const char answer2[] = "1\t\t\t  ";

        char *test2 = entab(input2);
        ck_assert_str_eq(test2, answer2);

    }
END_TEST

START_TEST (test_enter)
    {
        const char str0[] = "123456789";
        int n0 = 1;
        const char answer0[] = "1\n2\n3\n4\n5\n6\n7\n8\n9\n";
        char *test0 = enter(n0, str0);
        ck_assert_str_eq(test0, answer0);

        const char str1[] = "123123";
        int n1 = 3;
        const char answer1[] = "123\n123\n";
        char *test1 = enter(n1, str1);
        ck_assert_str_eq(test1, answer1);

        const char str2[] = "1111";
        int n2 = 3;
        const char answer2[] = "111\n1";
        char *test2 = enter(n2, str2);
        ck_assert_str_eq(test2, answer2);
    }
END_TEST

START_TEST (test_flush)
{
    char *str0 = "code//comment\n/*comment*/";
    char *answer = "code";
    char *test = flush(str0);
    ck_assert_str_eq(answer, test);

    char *str1 = "/**/";
    char *answer1 = "";
    char *test1 = flush(str1);
    ck_assert_str_eq(answer1, test1);

    char *str2 = "//comment";
    char *answer2 = "";
    char *test2 = flush(str2);
    ck_assert_str_eq(answer2, test2);
}
END_TEST

START_TEST (test_htoi)
{
    char *s0 = "0x0000";
    int answer = 0;
    int res = htoi(s0);
    ck_assert_int_eq(answer, res);

    char *s1 = "000";
    answer = 0;
    res = htoi(s1);
    ck_assert_int_eq(answer, res);

    char *s2 = "0Xeba1Bac";
    answer = 247274412;
    res = htoi(s2);
    ck_assert_int_eq(answer, res);

    char *s3 = "0xc0ca1b";
    answer = 15781147;
    res = htoi(s3);
    ck_assert_int_eq(answer, res);
}
END_TEST

START_TEST (test_squeeze)
{
    char *s0 = "abcdefghijklmnopqrstuvwxyz";
    char *r0 = "abcdefgjklmnopqrstuvwxyz";
    char *answer0 = "hi";
    char *res0 = squeeze(s0, r0);
    ck_assert_str_eq(answer0, res0);

    char *s1 = "kasu kasu kasu kasu";
    char *r1 = " ";
    char *answer1 = "kasukasukasukasu ";
    char *res1 = squeeze(s1, r1);
    ck_assert_str_eq(answer1, res1);

    char *s2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    char *r2 = "a";
    char *answer2 = "";
    char *res2 = squeeze(s2, r2);
    ck_assert_str_eq(answer2, res2);

    char *s3 = "shla sasha po shose";
    char *r3 = "sanya verni sotku";
    char *answer3 = "hlhph";
    char *res3 = squeeze(s3, r3);
    ck_assert_str_eq(answer3, res3);

    char *s4 = "esli vo vtoroi stroke budet shtoto to ya budu delat vse vovremya";
    char *r4 = "";
    char *answer4 = "esli vo vtoroi stroke budet shtoto to ya budu delat vse vovremya";
    char *res4 = squeeze(s4, r4);
    ck_assert_str_eq(answer4, res4);
}
END_TEST

START_TEST (test_any)
{
    const char s1[] = "abcdefghijklmnopqrstuvwxyz";
    const char s2[] = "d";
    int answer = 3;
    int res = any(s1, s2);
    ck_assert_int_eq(answer, res);

    const char s3[] = "ne chitai eto";
    const char s4[] = " ok";
    answer = 2;
    res = any(s3, s4);
    ck_assert_int_eq(answer, res);

    const char s5[] = "testi bolshe ne nujni";
    const char s6[] = "";
    answer = -1;
    res = any(s5, s6);
    ck_assert_int_eq(answer, res);
}
END_TEST

START_TEST (test_setbits)
    {
        unsigned int x = 111;
        unsigned int y = 100;
        int p = 1;
        int n = 2;
        unsigned int answer = 108;
        unsigned res = setbits(x, p, n, y);
        ck_assert_int_eq(answer, res);

        unsigned int x1 = 1234;
        unsigned int y1 = 100;
        int p1 = 0;
        int n1 = 4;
        unsigned int answer1 = 2147484882;
        unsigned res1 = setbits(x1, p1, n1, y1);
        ck_assert_int_eq(answer1, res1);

        unsigned int x2 = 1234;
        unsigned int y2 = 100;
        int p2 = 1;
        int n2 = 0;
        unsigned int answer2 = x2;
        unsigned res2 = setbits(x2, p2, n2, y2);
        ck_assert_int_eq(answer2, res2);
    }
END_TEST

START_TEST (test_binsearch)
{
    int v0[] = {1, 2, 3, 4, 5, 6};
    int x = 3;
    int answer = 2;
    int res = binsearch(x, v0, 6);
    ck_assert_int_eq(answer, res);

    x = 4;
    answer = 3;
    res = binsearch(x, v0, 6);
    ck_assert_int_eq(answer, res);

    int v1[] = {0};
    x = 8;
    answer = -1;
    res = binsearch(x, v1, 1);
    ck_assert_int_eq(answer, res);

    x = 1;
    answer = 0;
    res = binsearch(x, v0, 1);
    ck_assert_int_eq(answer, res);

    int v2[] = {};
    x = 228;
    answer = -1;
    res = binsearch(x, v2, 0);
    ck_assert_int_eq(answer, res);
}
END_TEST

START_TEST (test_escape)
{
    const char input1[] = "\t";
    const char answer1[] = "\\t";
    char *output1 = escape(input1);
    ck_assert_str_eq(answer1, output1);

    const char input2[] = "";
    const char answer2[] = "";
    char *output2 = escape(input2);
    ck_assert_str_eq(answer2, output2);

    const char input3[] = "\n";
    const char answer3[] = "\\n";
    char *output3 = escape(input3);
    ck_assert_str_eq(answer3, output3);
}
END_TEST

START_TEST (test_expand)
    {
        char s0[] = "a-z";
        char answer0[] = "abcdefghijklmnopqrstuvwxyz";
        char *res0 = expand(s0);
        ck_assert_str_eq(answer0, res0);

        char s1[] = "0-9";
        char answer1[] = "0123456789";
        char *res1 = expand(s1);
        ck_assert_str_eq(answer1, res1);

        char s2[] = "a-d0-5";
        char answer2[] = "abcd012345";
        char *res2 = expand(s2);
        ck_assert_str_eq(answer2, res2);
    }
END_TEST

START_TEST (test_itoa)
    {
        int x = 0;
        char *res0 = itoa(x);
        char *answer0 = "0";
        ck_assert_str_eq(res0, answer0);

        x = 123;
        char *res1 = itoa(x);
        char *answer1 = "123";
        ck_assert_str_eq(res1, answer1);

        x = -123;
        char *res2 = itoa(x);
        char *answer2 = "-123";
        ck_assert_str_eq(res2, answer2);
    }
END_TEST

START_TEST (test_itob)
    {
        int n = 49;
        int b = 2;
        char *answer0 = "110001";
        char *res0 = itob(n, b);
        ck_assert_str_eq(answer0, res0);

        n = 789;
        b = 3;
        char *answer1 = "1002020";
        char *res1 = itob(n, b);
        ck_assert_str_eq(answer1, res1);

        n = 25;
        b = 4;
        char *answer2 = "121";
        char *res2 = itob(n, b);
        ck_assert_str_eq(answer2, res2);

        n = 88;
        b = 5;
        char *answer3 = "323";
        char *res3 = itob(n, b);
        ck_assert_str_eq(answer3, res3);

        n = 18965;
        b = 8;
        char *answer4 = "45025";
        char *res4 = itob(n, b);
        ck_assert_str_eq(answer4, res4);

        n = 896541;
        b = 16;
        char *answer5 = "DAE1D";
        char *res5 = itob(n, b);
        ck_assert_str_eq(answer5, res5);
    }
END_TEST

START_TEST (test_strrindex)
    {
        const char s1[] = "111";
        const char h1[] = "1";
        int answer = 0;
        int res = strrindex(s1, h1);
        ck_assert_int_eq(answer, res);

        const char s2[] = "Hello World!";
        const char h2[] = "World";
        int answer2 = 6;
        int res2 = strrindex(s2, h2);
        ck_assert_int_eq(answer2, res2);

        const char s3[] = "I hate the whole world";
        const char h3[] = "love";
        int answer3 = -1;
        int res3 = strrindex(s3, h3);
        ck_assert_int_eq(answer3, res3);
    }
END_TEST

START_TEST (test_atofe)
    {
        char s0[] = "1.2e1";
        double res = atofe(s0);
        double answer = 12;
        ck_assert_double_eq_tol(res, answer, TOL_STRICT);

        char s1[] = "-1.2e1";
        res = atofe(s1);
        answer = -12;
        ck_assert_double_eq_tol(res, answer, TOL_STRICT);

        char s2[] = "12e-1";
        res = atofe(s2);
        answer = 1.2;
        ck_assert_double_eq_tol(res, answer, TOL_STRICT);
    }
END_TEST


Suite *str_suite(void) {
    Suite *suite = suite_create("Home assignment 1");
    TCase *tcase = tcase_create("case");

    tcase_add_test(tcase, test_stub);
    tcase_add_test(tcase, test_array_changer);

    tcase_add_test(tcase, test_detab);
    tcase_add_test(tcase, test_entab);
    tcase_add_test(tcase, test_enter);
    tcase_add_test(tcase, test_flush);
    tcase_add_test(tcase, test_htoi);
    tcase_add_test(tcase, test_squeeze);
    tcase_add_test(tcase, test_any);
    tcase_add_test(tcase, test_setbits);
    tcase_add_test(tcase, test_binsearch);
    tcase_add_test(tcase, test_escape);
    tcase_add_test(tcase, test_expand);
    tcase_add_test(tcase, test_itoa);
    tcase_add_test(tcase, test_itob);
    tcase_add_test(tcase, test_strrindex);
    tcase_add_test(tcase, test_atofe);
    /** YOUT TEST CASES HERE */

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