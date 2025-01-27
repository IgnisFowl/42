#include <stdio.h>

char *ft_strpbrk(const char *s, const char *accept)
{
    int i = 0;
    if (!s || !accept)
        return (NULL);
    while (*s)
    {
        i = 0;
        while (accept[i])
        {
            if (*s == accept[i])
                return ((char *)s);
            i++;
        }
        s++;
    }
    return (NULL);
}