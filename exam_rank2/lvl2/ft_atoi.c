int ft_atoi(char *c)
{
    int num = 0;
    int sign = 1;

    while (*c == ' ' || (*c >=9 && *c <= 13))
        c++;
    if (*c == '-')
        sign = -1;
    if (*c == '-' || *c == '+')
        c++;
    while (*c >= '0' && *c <= '9')
    {
        num = num * 10 + (*c - '0');
        c++;
    }
    return (sign * num);
}