#include "test.h"
#include <stdio.h>

int     main()
{
    t_te    data;
    int     i;

    i = 0;
    data.flag[L] = 23;
    data.flag[fanny] = 42;
    data.flag[florian] = 1000;

    while (i < 3)
    {
       printf("FLAGS -> %d\n", data.flag[i]); 
       ++i;
    }
    return (0);
}
