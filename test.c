#include "test.h"
#include "vector_int.h"

void runVectorIntTESTS()
{
    newVectorIntTEST();
}

void newVectorIntTEST()
{
    VectorInt *v1 = newVectorInt(0);
    VectorInt *v2 = newVectorInt(5);
    VectorInt *v3 = newVectorInt(-5);

    VectorInt *v4 = newFillVectorInt(0, 0);
    VectorInt *v5 = newFillVectorInt(5, 0);
    VectorInt *v6 = newFillVectorInt(5, 10);
    VectorInt *v7 = newFillVectorInt(-2, 4);

    printVectorInt(v1);
    printVectorInt(v2);
    printVectorInt(v3);
    printVectorInt(v4);
    printVectorInt(v5);
    printVectorInt(v6);
    printVectorInt(v7);
}