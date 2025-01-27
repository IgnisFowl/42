#include <stdlib.h>

int *ft_rrange(int start, int end)
{
    int *range;
    int i = 0;
    int step = 1;
    int len = end - start;

    if(len < 0)
        len *= -1;
    len++;
    range = (int *)malloc(sizeof(int) * len);
    if (!range)
        return NULL;
    if (start < end)
        step = -1;
    while (i < len)
    {
        range[i] = end;
        end += step;
        i++;
    }
    return (range);
}