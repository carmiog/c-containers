typedef struct {
    size_t size;
    size_t capacity;
    double realloc_ratio;
    double dealloc_ratio;
    TYPE *values;
} TYPED_NAME(vector);
TYPED_NAME(vector) * TYPED_NAME(new_vector) (size_t capacity);
void TYPED_NAME(delete_vector) (TYPED_NAME(vector) * vect);
TYPED_NAME(vector) * TYPED_NAME(append) (TYPED_NAME(vector) * vect, TYPE value);
TYPED_NAME(vector) * TYPED_NAME(insert) (TYPED_NAME(vector) * vect, size_t index, TYPE value);
TYPED_NAME(vector) * TYPED_NAME(delete) (TYPED_NAME(vector) * vect, size_t index);
TYPED_NAME(vector) * TYPED_NAME(shrink_to_fit) (TYPED_NAME(vector) * vect);
TYPE TYPED_NAME(get) (TYPED_NAME(vector) * vect, size_t index);
