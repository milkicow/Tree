#include "header.h"

int main()
{   
    node * korney = NULL;
    node * nd = NULL;
    FILE * in = fopen("graphIn.txt", "r");

    TreeScanf(in, &korney, NULL);
    TreeFDump(korney);

    fclose(in);

    return 0;
}