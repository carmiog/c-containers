#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

void vector_memory_allocation_fail() {
    printf("Vector: memory allocation failed\n");
    exit(1);
}

void vector_out_of_range(size_t index) {
    printf("Vector: index %lu is out of bound\n", index);
    exit(1);
}
#define TYPE int
#define TYPED_NAME(x) x ## _int
#include "vector_impl.c"
#undef TYPE
#undef TYPED_NAME

#define TYPE double
#define TYPED_NAME(x) x ## _double
#include "vector_impl.c"
#undef TYPE
#undef TYPED_NAME

