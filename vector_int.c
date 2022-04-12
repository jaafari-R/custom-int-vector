#include "stdlib.h"

#include "vector_int.h"


struct VectorInt
{
    int *data; // dynamically allocated int array
    unsigned long long size; // number of integers in the array
    unsigned long long capacity; // max size of the array
    unsigned long long original_capacity; // the minimum capacity, it's input on construction, and can be modified by resizing.
};

VectorInt* newVectorInt(unsigned long long sz)
{
    VectorInt *v;
    v->capacity = sz;
    v->original_capacity = sz;
    v->size = 0;
    v->data = NULL;
}

void destroyVectorInt(VectorInt* v)
{
    if(v->capacity) free(v->data);
}

VectorInt*  newFillVectorInt(unsigned long long sz, int value)
{
    VectorInt* v;

    v->capacity = sz;
    v->original_capacity = sz;
    v->size = sz;
    v->data = (int *) malloc(sizeof(int)  * sz);
    // fill vector with val
    while(sz--)
        *(v->data+sz) = value;
    return  v;
}

void copyVectorInt(VectorInt *src_v, struct VectorInt *dst_v)
{
    // empty data
    destroyVectorInt(src_v);

    src_v->capacity = dst_v->capacity;
    src_v->original_capacity = dst_v->original_capacity;
    src_v->size = dst_v->size;
    if(src_v->size)
        src_v->data = (int *) malloc(sizeof(int) * src_v->capacity);
    return src_v;
}

#ifdef _DEBUG
void printVectorInt(VectorInt * v)
{
    unsigned long long i;
    printf("vector_size = %llu, vector_capacity = %llu, vector_original_capacity = %llu, vector_data = %llu,\n", v->size,
        v->capacity, v->original_capacity, (unsigned long long)(v->data));
    printf("[ ")
    for(i = 0; i < v->size - 1; i++)
        printf("item %lu = %d, ", i, v->data[i]);
    printf("item %lu = %d ]\n", i, v->data[i]);
}
#endif /* _DEBUG */