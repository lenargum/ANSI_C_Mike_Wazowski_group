//vector_create
// Created by cubazis on 05.06.18.
//

#include <check.h>
#include "vector_int.h"
#include <stdlib.h>
#include <stdio.h>

#define NELEMS(x) (sizeof (x)/sizeof (x[0]))

int comp_vectors_int(const void *a, const void *b)
/* Returns -ve if a<b, 0 if a==b, +ve if a>b */
{
	struct Vector *v1 = (struct Vector *)a;
	struct Vector *v2 = (struct Vector *)b;
	int i = 0;
	while (v1->size < i + 1 && v2->size < i + 1){
		if (((int*)v1->data)[i] > ((int*)v2->data)[i]) return 1;
		if (((int*)v1->data)[i] < ((int*)v2->data)[i]) return -1;
	}
	if (v1->size > v2->size) {
		return 1;
	}
	if (v1->size < v2->size) {
		return -1;
	}
	return 0;
}

START_TEST(test_vector_qsort)
{
	struct Vector *v = vector_create_int(5);
	for (int i = 0; i < NELEMS(v); ++i) {
		((int*)v->data)[i] = NELEMS(v) - i;
	}
	qsort(&v, NELEMS(v), sizeof v[0], comp_vectors_int);
	for (int i = 0; i < NELEMS(v); ++i) {
		printf("%d ", ((int*)v->data)[i]);
	}
}
END_TEST


Suite* str_suite (void) {
	Suite *suite = suite_create("Assignment 4");
	TCase *tcase = tcase_create("case");


	tcase_add_test(tcase, test_vector_qsort);

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