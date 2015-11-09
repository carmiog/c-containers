TYPED_NAME(vector) * TYPED_NAME(new_vector) (size_t capacity) {
    TYPED_NAME(vector) * vect = malloc(sizeof(TYPED_NAME(vector) ));
    if (vect == NULL)
        vector_memory_allocation_fail();
    vect->values = malloc(sizeof( TYPE )*capacity);
    if(vect->values == NULL)
        vector_memory_allocation_fail();
    vect->size = 0;
    vect->capacity = capacity;
    vect->realloc_ratio = 1.2;
    vect->dealloc_ratio = 0.5;
    return vect;
}

void TYPED_NAME(delete_vector) (TYPED_NAME(vector) * vect) {
    free(vect->values);
    free(vect);
}

TYPE TYPED_NAME(get) (TYPED_NAME(vector) * vect, size_t index) {
    if(index > vect->size - 1)
        vector_out_of_range(index);
    return vect->values[index];
}

void TYPED_NAME(increase_capacity) (TYPED_NAME(vector) * vect) {
    size_t new_capacity = (size_t)(vect->realloc_ratio*vect->capacity + 1);
    vect->values = realloc(vect->values, sizeof( TYPE )*new_capacity);
    if(vect->values == NULL)
        vector_memory_allocation_fail();
    vect->capacity = new_capacity;
}

void TYPED_NAME(decrease_capacity) (TYPED_NAME(vector) * vect) {
    size_t new_capacity = (size_t)(vect->realloc_ratio*vect->size + 1);
    vect->values = realloc(vect->values, sizeof( TYPE )*new_capacity);
    if(vect->values == NULL)
        vector_memory_allocation_fail();
    vect->capacity = new_capacity;
}

TYPED_NAME(vector) * TYPED_NAME(append) (TYPED_NAME(vector) * vect, TYPE value) {
    return TYPED_NAME(insert) (vect, vect->size, value);
}

TYPED_NAME(vector) * TYPED_NAME(insert) (TYPED_NAME(vector) * vect, size_t index, TYPE value) {
    if (index > vect->size)
        vector_out_of_range(index);
    if (vect->size == vect->capacity)
        TYPED_NAME(increase_capacity) (vect);
    for (size_t i = vect->size; i > index; --i)
        vect->values[i] = vect->values[i - 1];
    vect->values[index] = value;
    vect->size += 1;
    return vect;
}

TYPED_NAME(vector) * TYPED_NAME(delete) (TYPED_NAME(vector) * vect, size_t index) {
    if (index >= vect->size)
        vector_out_of_range(index);
    for (size_t i = index; i < vect->size - 1; ++i)
        vect->values[i] = vect->values[i + 1];
    vect->size -= 1;
    if (vect->size/(double)vect->capacity < vect->dealloc_ratio)
        TYPED_NAME(decrease_capacity) (vect);
    return vect;
}

TYPED_NAME(vector) * TYPED_NAME(shrink_to_fit) (TYPED_NAME(vector) * vect) {
    TYPE * tmp = ( TYPE *) realloc(vect->values, sizeof( TYPE )*vect->size);
    if(tmp == NULL)
        vector_memory_allocation_fail();
    vect->capacity = vect->size;
    vect->values = tmp;
    return vect;
}

TYPED_NAME(lifo) * TYPED_NAME(new_lifo) () {
    TYPED_NAME(lifo) * lifo = TYPED_NAME(new_vector)(100);
    return lifo;
}

void TYPED_NAME(delete_lifo) (TYPED_NAME(lifo) * lifo) {
    TYPED_NAME(delete_vector)(lifo);
}

void TYPED_NAME(lifo_put) (TYPED_NAME(lifo) * lifo, TYPE value) {
    TYPED_NAME(append)(lifo, value);
}

TYPE TYPED_NAME(lifo_pull) (TYPED_NAME(lifo) * lifo) {
    TYPE value = TYPED_NAME(lifo_top)(lifo);
    TYPED_NAME(delete)(lifo, lifo->size - 1);
    return value;
}

TYPE TYPED_NAME(lifo_top) (TYPED_NAME(lifo) * lifo) {
    return TYPED_NAME(get)(lifo, lifo->size - 1);
}
