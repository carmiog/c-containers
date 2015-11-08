#ifndef SRC_VECTOR_H_
#define SRC_VECTOR_H_
#include <stdlib.h>

#define TYPE int
#define TYPED_NAME(x) x ## _int
#include "vector_impl.h"
#undef TYPE
#undef TYPED_NAME

#define TYPE double
#define TYPED_NAME(x) x ## _double
#include "vector_impl.h"
#undef TYPE
#undef TYPED_NAME


#endif

