#include "stdlib.h"
#include "stdio.h"
#include "string.h"

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

    v->capacity = sz;
    v->original_capacity = sz ? sz : 1;
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

    v->capacity = sz;
    v->original_capacity = sz ? sz : 1;
    v->size = sz;
    v->data = (int *) malloc(sizeof(int)  * sz);
    /* fill vector with val */
    while(sz--)
        v->data[sz] = value;
    return  v;
}

void copyVectorInt(VectorInt *src_v, struct VectorInt **dst_v)
{
    /* empty data */
    if(!*dst_v) *dst_v = (VectorInt *) malloc(sizeof(VectorInt));
    destroyVectorInt(*dst_v);

    (*dst_v)->capacity = src_v->capacity;
    (*dst_v)->original_capacity = src_v->original_capacity;
    (*dst_v)->size = src_v->size;
    if((*dst_v)->size)
    {
        (*dst_v)->data = (int *) malloc(sizeof(int) * (*dst_v)->capacity);
        memcpy((*dst_v)->data, src_v->data, (*dst_v)->size);
    }
}

#ifdef _DEBUG
void printVectorInt(VectorInt * v)
{
    unsigned long i;
    printf("vector_size = %lu, vector_capacity = %lu, vector_original_capacity = %lu, vector_data = %lu, data:\n", v->size,
        v->capacity, v->original_capacity, (unsigned long)(v->data));
    printf("[ ");
    if(!v->size) 
    {
        printf("]\n");
        return;
    }
    for(i = 0; i < v->size - 1; ++i)
        printf("%d, ", v->data[i]);
    printf("%d ]\n", v->data[i]);
}
#endif /* _DEBUG */