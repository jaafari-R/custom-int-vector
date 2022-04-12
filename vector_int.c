#include "stdlib.h"

#include "vector_int.h"


struct VectorInt
{
    int *values; // dynamically allocated int array
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
    v->values = NULL;
}

void destroyVectorInt(VectorInt* v)
{
    if(v->capacity) free(v->values);
}

VectorInt*  newFillVectorInt(unsigned long long sz, int value)
{
    VectorInt* v;

    v->capacity = sz;
    v->original_capacity = sz;
    v->size = sz;
    v->values = (int *) malloc(sizeof(int)  * sz);
    // fill vector with val
    while(sz--)
        *(v->values+sz) = value;
    return  v;
}

void copyVectorInt(VectorInt *src_v, struct VectorInt *dst_v)
{
    // empty values
    destroyVectorInt(src_v);

    src_v->capacity = dst_v->capacity;
    src_v->original_capacity = dst_v->original_capacity;
    src_v->size = dst_v->size;
    if(src_v->size)
        src_v->values = (int *) malloc(sizeof(int) * src_v->capacity);
    return src_v;
}