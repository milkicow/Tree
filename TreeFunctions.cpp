#include "header.h"

node * TreeCtor(node ** nd, DATA arg)
{
    LOX
    *nd = (node *) calloc(1, sizeof(node));

    assert(nd);

    (*nd) -> data = arg;

    (*nd) -> left_son = NULL;
    (*nd) -> right_son = NULL;

    return *nd;
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

node * TreeAdd(node * parent, node ** nd, DATA arg)
{   
    LOX
    if(*nd == NULL)
    {   
        LOX
        TreeNodeAdd(parent, nd, arg);
    }
    else
    {   
        if (arg < (*nd) -> data)
        {   
            LOX
            TreeAdd(*nd, &((*nd) -> left_son), arg);
            LOX
        }
        else if (arg > (*nd) -> data)
        {   
            LOX
            TreeAdd(*nd, &((*nd) -> right_son), arg);
        }
    }
    return *nd;
}

node * TreeNodeAdd(node * parent, node ** nd, DATA arg)
{    
    LOX
    *nd = (node *) calloc(1, sizeof(node));
    assert(nd);
    LOX

    (*nd) -> data = arg;
    LOX
    (*nd) -> left_son = NULL;
    LOX
    (*nd) -> right_son = NULL;
    LOX
    (*nd) -> parent = parent;
    LOX

    return *nd;
}

void TreePrintPreOrder(FILE * fp, node * nd, int n)
{   
    assert(fp);
    assert(nd);
    fprintf(fp, "\n%*s", n, "{");

    fprintf(fp, " " elem_t, nd -> data);

    if(nd -> left_son) TreePrintPreOrder(fp, nd -> left_son, n + 4);
    //else n = 2;
    if(nd -> right_son) TreePrintPreOrder(fp, nd -> right_son, n + 4);
    //else n = 2;
    if(!nd -> left_son && !nd -> right_son) n = 2;

    fprintf(fp, "%*s\n", n, "}");
}

void TreePrintInOrder(node * nd)
{
    if (nd == NULL)
    {   
        return;
    }
    //printf("%*s", n, "{");

    TreePrintInOrder(nd -> left_son);
    printf(" "elem_t, nd -> data);
    TreePrintInOrder(nd -> right_son);

    //printf("%s", "}");
}

void TreePrintPostOrder(node * nd)
{
    if (nd == NULL)
    {   
        return;
    }
    TreePrintPostOrder(nd -> left_son);
    TreePrintPostOrder(nd -> right_son);
    printf(" "elem_t, nd -> data);
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
        
    fprintf(fp, "node%p [shape=record,label=\"DATA " elem_t " \" ];\n", nd, nd -> data);
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

void TreeScanf(FILE * fp, node ** nd, node * parent)
{   
    LOX
    int data = 0;
    char bracket[10];
    LOX
    fscanf(fp, "%s", bracket);
    LOX
    if(strcmp(bracket, "{") == 0)
    {   
        LOX
        fscanf(fp, "%d", &data);
        LOX
        TreeNodeAdd(parent, nd, data);
        LOX
        TreeScanf(fp, &(*nd) -> right_son, *nd);
        LOX
        TreeScanf(fp, &(*nd) -> left_son, *nd);
    }
    else if(strcmp(bracket, "}") == 0)
    {   
        LOX
        ungetc('}', fp);
        return;
    }
    fscanf(fp, "%s", bracket);   
    
}