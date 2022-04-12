#ifndef __VICTOR_INT__
#define __VICTOR_INT__

/*  VectorInt:
        Dynamically allocates int array.
        expanding and shrinking of the vector:
            the capacity of the vector array doubles when its size is equal to it's capacity and an insertion is being done to it,
            and the capacity is halved if the size is half of the capacity and the original capacity is less than the current capacity.
            if the capacity is equal to 0 then it's set to 1 during insertion.
        Must be Destroyed before the program end using destroyVectorInt(), to not cause memory leaks
*/
typedef struct VectorInt VectorInt;

/* Constructs an int vector with it's original capacity set to sz
    if sz is set to 0 the vector is empty, and original capacity is set to 1.
    make sure that sz is not negative, it will be converted to unsigned long
*/
VectorInt* newVectorInt(unsigned long sz);

/* Constructs an int vector with original capacity sz, and fill it with value
    if sz is set to 0 the vector is empty, and original capacity is set to 1.
    make sure that sz is not negative, it will be converted to unsigned long
*/
VectorInt*  newFillVectorInt(unsigned long sz, int value);

/* Destroys a VectorInt, 
   Must be called before the program ends, not calling it will cause a memory leak. 
*/
void destroyVectorInt(VectorInt* v);

/* Copies src_v from dst_v
*/
void copyVectorInt(VectorInt *src_v, struct VectorInt **dst_v);


#if _DEBUG
void printVectorInt(VectorInt *v);
#endif

#endif