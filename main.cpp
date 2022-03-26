#include "header.h"

int main()
{
    struct node * korney = NULL; 
    struct node * vetka = NULL;
    LOX
    korney = TreeAdd(korney, 5);

    TreeAdd(korney, 9);
    TreeAdd(korney, 1);
    TreeAdd(korney, 7);
    TreeAdd(korney, 6);
    TreeAdd(korney, 8);
    TreeAdd(korney, 10);




    //TreeAdd(korney, 4);

    //TreeAdd(korney, 100);

    //korney -> left_son = NULL;

    //printf("ptr = %p, value = %d\n", TreeFind(korney, 100), TreeFind(korney, 100) -> data);
    printf("korney -> right_son = %p\n", korney -> right_son);
    int n = 4;
    TreePrintPreOrder(korney, n);
    printf("\n");
    TreePrintInOrder(korney);
    printf("\n");
    TreePrintPostOrder(korney);
    printf("\n");


    TreeFDump(korney);



/*
    vetka = (korney -> left_son) -> left_son;
    TreeSegDtor(vetka);
*/

    //TreeFDump(korney);
    TreeDtor(korney);

    return 0;
}