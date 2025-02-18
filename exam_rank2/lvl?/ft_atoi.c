#include <stdio.h>

int	ft_atoi(const char *str)
{
    long num = 0;
    int sign = 1;
    int i = 0;
    while(str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
        i++;
    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            sign *= -1;
        i++;
    }
    while(str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
    {
        num = num * 10 + (str[i] - '0');
        i++;
    }
    return(sign * num);
}
