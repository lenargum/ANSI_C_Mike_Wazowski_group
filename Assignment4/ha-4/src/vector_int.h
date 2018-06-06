//
// Created by cubazis on 05.06.18.
//

#ifndef LAB4_EXPANDABLE_VECTOR_INT_H
#define LAB4_EXPANDABLE_VECTOR_INT_H

#include "vector.h"
/* Vector creation. */

Vector *vector_create_int(size_t capacity);
/* Vector access operations. */

int vector_push_back_int(Vector *v, int item);

int vector_pop_back_int(Vector *v);

int vector_get_element_int(Vector *v, size_t index);

int vector_get_begin_int(Vector *v);

int vector_get_end_int(Vector *v);

#endif //LAB4_EXPANDABLE_VECTOR_INT_H
