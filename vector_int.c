#include "stdlib.h"
#include "stdio.h"

#include "vector_int.h"


struct VectorInt
{
    int *data; /* dynamically allocated int array */
    unsigned long size; /* number of integers in the array */
    unsigned long capacity; /* max size of the array */
    unsigned long original_capacity; /* the minimum capacity, it's input on construction, and can be modified by resizing. */
};

VectorInt* newVectorInt(unsigned long sz)
{
    VectorInt *v = (VectorInt *) malloc(sizeof(VectorInt));
    if(sz < 0) sz = 0;

    v->capacity = sz;
    v->original_capacity = sz;
    v->size = 0;
    v->data = NULL;
    return v;
}

void destroyVectorInt(VectorInt* v)
{
    if(v->capacity) free(v->data);
}

VectorInt* newFillVectorInt(unsigned long sz, int value)
{
    VectorInt *v = (VectorInt *) malloc(sizeof(VectorInt));
    if(sz < 0) sz = 0;

    v->capacity = sz;
    v->original_capacity = sz;
    v->size = sz;
    v->data = (int *) malloc(sizeof(int)  * sz);
    /* fill vector with val */
    while(sz--)
        *(v->data+sz) = value;
    return  v;
}

void copyVectorInt(VectorInt *src_v, struct VectorInt *dst_v)
{
    /* empty data */
    destroyVectorInt(src_v);

    src_v->capacity = dst_v->capacity;
    src_v->original_capacity = dst_v->original_capacity;
    src_v->size = dst_v->size;
    if(src_v->size)
        src_v->data = (int *) malloc(sizeof(int) * src_v->capacity);
}

#ifdef _DEBUG
void printVectorInt(VectorInt * v)
{
    unsigned long i;
    printf("vector_size = %lu, vector_capacity = %lu, vector_original_capacity = %lu, vector_data = %lu,\n", v->size,
        v->capacity, v->original_capacity, (unsigned long)(v->data));
    printf("[ ");
    for(i = 0; i < v->size - 1; i++)
        printf("item %lu = %d, ", i, v->data[i]);
    printf("item %lu = %d ]\n", i, v->data[i]);
}
#endif /* _DEBUG */