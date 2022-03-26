#include "header.h"

void TreeCtor(node * nd, DATA arg)
{
    LOX
    nd = (node *) calloc(1, sizeof(node));

    nd -> data = arg;

    nd -> left_son = NULL;
    nd -> right_son = NULL;

    assert(nd);
}

node * TreeAdd(node * nd, DATA arg)
{   
    LOX
    if(nd == NULL)
    {   
        LOX
        nd = (node *) calloc(1, sizeof(node));

        nd -> data = arg;

        nd -> left_son = NULL;
        nd -> right_son = NULL;

        assert(nd);
    }
    else
    {   
        if (arg < nd -> data)
        {   
            LOX
            nd -> left_son = TreeAdd(nd -> left_son, arg);
        }
        else if (arg > nd -> data)
        {   
            LOX
            nd -> right_son = TreeAdd(nd -> right_son, arg);
        }
    }
    return nd;
}

void TreeDtor(node * nd)  //дерево и его поддерево
{   
    if(nd != NULL)
    {   
        LOX
        TreeDtor(nd -> left_son);
        TreeDtor(nd -> right_son);

        free(nd);
    }
}

void TreePrintInOrder(node * nd)
{
    if (nd == NULL)
    {   
        return;
    }
    TreePrintInOrder(nd -> left_son);
    printf("%d  ", nd -> data);
    TreePrintInOrder(nd -> right_son);
}

void TreePrintPreOrder(node * nd)
{
    if (nd == NULL)
    {   
        return;
    }
    printf("%d  ", nd -> data);
    TreePrintPreOrder(nd -> left_son);
    TreePrintPreOrder(nd -> right_son);
}

void TreePrintPostOrder(node * nd)
{
    if (nd == NULL)
    {   
        return;
    }
    TreePrintPostOrder(nd -> left_son);
    TreePrintPostOrder(nd -> right_son);
    printf("%d  ", nd -> data);
}

void TreeFDump(node * nd)
{   
    LOX
    FILE * fp = fopen("dump.txt", "w");
    assert(fp);

    fprintf(fp, "digraph G {\n");
    fprintf(fp, "rankdir=UD;\n");
    LOX
    TreePrint(nd, fp);

    fprintf(fp, "}\n");
    fclose(fp);
    system("dot dump.txt -T pdf -o dump.pdf");
    system("open dump.pdf");
}

void TreePrint(node * nd, FILE * fp)
{   
    LOX
    if(nd == NULL)
    {
        return;
    }
        
    fprintf(fp, "node%p [shape=record,label=\"DATA %d \" ];\n", nd, nd -> data);
    if(nd -> left_son != NULL)
    {
        fprintf(fp, "node%p -> node%p[color = pink];\n", nd , nd -> left_son );
        TreePrint(nd -> left_son, fp);
    }
    if(nd -> right_son != NULL)
    {
        fprintf(fp, "node%p -> node%p[color = pink];\n", nd , nd -> right_son);
        TreePrint(nd -> right_son, fp);
    }
}

node * TreeFind(node * root, DATA value)
{   
    assert(root);
    assert(value);

    node * nd = root;
    while(nd)
    {
        if(nd -> data == value) 
            return nd;
        if(nd -> data < value)
            nd = nd -> right_son;
        if(nd -> data > value)
            nd = nd -> left_son;
    }

    return NULL;
}

void TreeSegDtor(node * nd)
{
    assert(nd);

    nd -> right_son = NULL;
    nd -> left_son = NULL;
}