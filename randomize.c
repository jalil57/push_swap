#include "ft_push_swap.h"
#include <stdlib.h>
#include <time.h>

char    **randomize(int len)
{
    int     i;
    char    **list;

    i = 0;
    srand(time(NULL));
    list = (char **)malloc(sizeof(char *) * len + 1);
    while (i < len)
    {
        list[i] = ft_itoa(i);
        i++;
    }
   i = 0;
    while (i < len)
    {
        int x = rand() % len + 1;
        int y = rand() % len + 1;
        char *swap = list[x];
        list[x] = list[y];
        list[y] = swap;
        i++;
    }

    return (list);
}