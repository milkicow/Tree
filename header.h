#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>
#include <math.h>

#define LOX  printf("повезло повезло %d\n", __LINE__);                     

typedef int DATA;
#define elem_t "%d"

void TreeCtor(struct node * nd, DATA arg);
void TreeDtor(struct node * nd);
node * TreeAdd(node * nd, DATA arg);
void TreePrintPreOrder(node * nd, int n);
void TreePrintInOrder(node * nd);
void TreePrintPostOrder(node * nd);
void TreeFDump(node * nd);
void TreePrint(node * nd, FILE * fp);
void TreeSegDtor(node * nd);
node * TreeFind(node * root, int value);


struct node
{
    DATA data;
    node * left_son;
    node * right_son;
};