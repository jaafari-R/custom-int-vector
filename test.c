#include "stdio.h"

#include "test.h"
#include "vector_int.h"

#ifdef _DEBUG
void runVectorIntTESTS()
{
    newVectorIntTEST();
    copyVectorIntTEST();
}

void newVectorIntTEST()
{
    VectorInt *v1 = newVectorInt(0);
    VectorInt *v2 = newVectorInt(5);
    VectorInt *v3 = newFillVectorInt(0, 0);
    VectorInt *v4 = newFillVectorInt(5, 0);
    VectorInt *v5 = newFillVectorInt(5, 10);
    VectorInt *v6 = newFillVectorInt(10, -4);

    printf("\n\n================ newVectorIntTest ================\n\n");

    printf("---v1---\n");
    printVectorInt(v1);
    printf("---v2---\n");
    printVectorInt(v2);

    destroyVectorInt(v1);
    destroyVectorInt(v2);


    printf("---v3---\n");
    printVectorInt(v3);
    printf("---v4---\n");
    printVectorInt(v4);
    printf("---v5---\n");
    printVectorInt(v5);
    printf("---v6---\n");
    printVectorInt(v6);

    destroyVectorInt(v3);
    destroyVectorInt(v4);
    destroyVectorInt(v5);
    destroyVectorInt(v6);
}

void copyVectorIntTEST()
{
    VectorInt *vc1 = 0, *vc2 = 0, *vc3 = 0, *vc4 = 0, *vc5 = 0;
    VectorInt *v1 = newVectorInt(0);
    VectorInt *v2 = newVectorInt(5);
    VectorInt *v3 = newFillVectorInt(0, 0);
    VectorInt *v4 = newFillVectorInt(5, 0);
    VectorInt *v5 = newFillVectorInt(5, -4);

    printf("\n================ copyVectorIntTEST ================\n\n");
    
    /* copy to empty */
    copyVectorInt(v1, &vc1);
    copyVectorInt(v2, &vc2);
    copyVectorInt(v3, &vc3);
    copyVectorInt(v4, &vc4);
    copyVectorInt(v5, &vc5);

    printf("---v1---\n");
    printVectorInt(v1);
    printf("---v2---\n");
    printVectorInt(v2);
    printf("---v3---\n");
    printVectorInt(v3);
    printf("---v4---\n");
    printVectorInt(v4);
    printf("---v5---\n");
    printVectorInt(v5);
    printf("---vc1---\n");
    printVectorInt(vc1);
    printf("---vc2---\n");
    printVectorInt(vc2);
    printf("---vc3---\n");
    printVectorInt(vc3);
    printf("---vc4---\n");
    printVectorInt(vc4);
    printf("---vc5---\n");
    printVectorInt(vc5);

    /* copy to filled */
    copyVectorInt(v2, &v1);
    copyVectorInt(v3, &v2);
    copyVectorInt(v4, &v3);
    copyVectorInt(v5, &v4);

    printf("---v1 copied from v2---\n");
    printVectorInt(v1);
    printf("---v2 copied from v3---\n");
    printVectorInt(v2);
    printf("---v3 copied from v4---\n");
    printVectorInt(v3);
    printf("---v4 copied from v5---\n");
    printVectorInt(v4);

    destroyVectorInt(v1);
    destroyVectorInt(v2);
    destroyVectorInt(v3);
    destroyVectorInt(v4);
    destroyVectorInt(vc1);
    destroyVectorInt(vc2);
    destroyVectorInt(vc3);
    destroyVectorInt(vc4);
}

#endif