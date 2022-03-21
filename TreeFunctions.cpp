#include "header.h"

void TreeCtor(node * nd, DATA arg)
{
    LOX
    nd = (node *) calloc(1, sizeof(node));

    nd -> value = arg;

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

        nd -> value = arg;

        nd -> left_son = NULL;
        nd -> right_son = NULL;

        assert(nd);
    }
    else
    {   
        if (arg < nd -> value)
        {   
            LOX
            nd -> left_son = TreeAdd(nd -> left_son, arg);
        }
        else if (arg > nd -> value)
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

void TreePrintSymmetric(node * nd)
{
    if (nd == NULL)
    {   
        LOX
        return;
    }

    LOX
    TreePrintSymmetric(nd -> left_son);
    printf("%d  ", nd -> value);
    TreePrintSymmetric(nd -> right_son);
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
        
    fprintf(fp, "node%p [shape=record,label=\"DATA %d \" ];\n", nd, nd -> value);
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

void TreeSegDtor(node * nd)
{
    assert(nd);

    nd -> right_son = NULL;
    nd -> left_son = NULL;
}