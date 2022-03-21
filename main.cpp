#include "header.h"

int main()
{
    struct node * korney = NULL; 
    struct node * vetka = NULL;
    LOX
    korney = TreeAdd(korney, 20);
    
    TreeAdd(korney, 9);
    TreeAdd(korney, 5);
    TreeAdd(korney, 12);
    TreeAdd(korney, 6);


    TreeAdd(korney, 4);

    TreeAdd(korney -> left_son, 100);

    //korney -> left_son = NULL;

    printf("korney -> right_son = %p", korney -> right_son);


    vetka = (korney -> left_son) -> left_son;
    TreeSegDtor(vetka);


    TreeFDump(korney);

    LOX
    TreeDtor(korney);

    return 0;
}