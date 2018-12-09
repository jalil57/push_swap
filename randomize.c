#include "ft_push_swap.h"
#include <stdlib.h>
#include <time.h>

char    **randomize(int len)
{
    int     i;
    char    **list;

    i = 0;
    list = (char **)malloc(sizeof(char *) * len + 1);
    srand(time(NULL));
    while (i < len)
    {
        list[i] = ft_itoa((i + (rand() % ((NBMAX - NBMIN) + NBMIN))));
        i++;
    }
    list[len] = NULL;
    return (list);
}