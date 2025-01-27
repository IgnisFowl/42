#include <stdlib.h>

char *strdup(const char *s)
{
    int len = 0;
    int i = 0;
    char *result;

    while (s[len] != '\0')
        len++;
    result = (char *)malloc(len + 1);
    if (result == NULL)
        return (NULL);
    while (s[i] != '\0')
    {
        result[i] == s[i];
        i++;
    }
    result[i] = '\0';
    return (result);
}