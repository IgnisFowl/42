#include <stddef.h>

size_t  strcspn(const char *s, const char *reject)
{
    size_t count = 0;
    size_t i = 0;
    while (*s)
    {
        while (reject[i] && *s != reject[i])
            i++;
        if (reject[i] != '\0')
            return (count);
        i = 0;
        count++;
        s++;
    }
    return (count);
}
