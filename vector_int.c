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

/* ========================= helper functions ========================= */
/* resizes data capacity
*/
void resizeData(int **data, unsigned long new_capacity, unsigned long data_size);

void resizeData(int **data, unsigned long new_capacity, unsigned long data_size)
{
    int *new_data = (int *) malloc(sizeof(int) * new_capacity);
    memcpy(new_data, *data, sizeof(int) * data_size);
    free(*data);
    *data = new_data;
}


/* ========================= VectorInt ========================= */
VectorInt* newVectorInt(unsigned long sz)
{
    VectorInt *v = (VectorInt *) malloc(sizeof(VectorInt));

    v->capacity = sz;
    v->original_capacity = sz ? sz : 1;
    v->size = 0;
    if(sz) v->data = (int *) malloc(sizeof(int) * sz);
    else v->data = 0; /* nullptr */
    return v;
}

void destroyVectorInt(VectorInt* v)
{
    if(v)
    {
        if(v->capacity) free(v->data);
        free(v);
    }
}

VectorInt* newFillVectorInt(unsigned long sz, int value)
{
    VectorInt *v = (VectorInt *) malloc(sizeof(VectorInt));

    v->capacity = sz;
    v->size = sz;
    v->original_capacity = sz ? sz : 1;
    v->data = (int *) malloc(sizeof(int)  * sz);
    /* fill vector with val */
    while(sz--)
        v->data[sz] = value;
    return  v;
}

void copyVectorInt(VectorInt *src_v, struct VectorInt **dst_v)
{
    /* do nothing if src and dst are the same */
    if(src_v == *dst_v) return;
    /* empty data */
    destroyVectorInt(*dst_v);
    /* allocate *dst_v if it's null */
    *dst_v = newVectorInt(src_v->original_capacity);


    (*dst_v)->capacity = src_v->capacity;
    (*dst_v)->size = src_v->size;
    if((*dst_v)->size)
    {
        (*dst_v)->data = (int *) malloc(sizeof(int) * (*dst_v)->capacity);
        memcpy((*dst_v)->data, src_v->data, sizeof(int) * (*dst_v)->size);
    }
}

void pushVectorInt(VectorInt *v, int value)
{
    if(v->capacity == 0) 
    {
        v->capacity = 1;
        v->data = (int *) malloc(sizeof(int));
    }
    if(v->size == v->capacity)
    {
        v->capacity *= 2;
        resizeData(&v->data, v->capacity, v->size);
    }
    v->data[v->size] = value;
    ++(v->size);
}

int popVectorInt(VectorInt *v)
{
    int val;

    if(!v->size) return 0;

    --(v->size);
    val = v->data[v->size];

    if((v->size < (v->capacity / 3)) && (v->capacity != v->original_capacity))
    {
        if(v->capacity / 2 >= v->original_capacity)
            v->capacity = v->capacity / 2;
        else
            v->capacity = v->original_capacity;
        resizeData(&v->data, v->capacity, v->size);
    }
    return val;
}

unsigned long sizeVectorInt(VectorInt *v)
{
    return v->size;
}

unsigned long capacityVectorInt(VectorInt * v)
{
    return v->capacity;
}

unsigned long originalCapacityVectorInt(VectorInt * v)
{
    return v->original_capacity;
}

void resize(VectorInt *v, unsigned long new_capacity)
{
    int *new_data = (int *)malloc(sizeof(int) * new_capacity);
    if(v->size < new_capacity)
        v->size = new_capacity;
    memcpy(new_data, v->data, v->size * sizeof(int));
    v->data = new_data;
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
#endif