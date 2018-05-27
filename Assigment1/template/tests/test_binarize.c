//
// Created by cubazis on 24.05.18.
//
#include <check.h>
#include "binarize.h"

int COMPARATOR(char* c1, char* c2)
{
	if(strlen(c1) != strlen(c2))
	{
		return 0;
	}
	for (int i = 0; i < strlen(c1); i++)
	{
		if((c1)[i] != (c2)[i])
		{
			return 0;
		}
	}
	return 1;
}

START_TEST (test_bin_u)
{
	unsigned long x = 1608637542;
	char* output = binarize_u(x);
	char* pattern = "01011111111000011101110001100110";
	ck_assert(COMPARATOR(output, pattern));
	//printf("%s\n", output);
}
END_TEST

START_TEST (test_bin_s)
{
	signed long x = -1608637542;
	char* output = binarize_s(x);
	char* pattern = "10100000000111100010001110011010";
	ck_assert(COMPARATOR(output, pattern));
	//printf("%s\n", output);
}
END_TEST

Suite* str_suite (void) {
	Suite *suite = suite_create("binarize");
	TCase *tcase = tcase_create("case");
	tcase_add_test(tcase, test_bin_u);
	tcase_add_test(tcase, test_bin_s);
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