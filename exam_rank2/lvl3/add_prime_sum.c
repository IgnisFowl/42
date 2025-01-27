#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_putnbr(int n)
{
    if (n > 9)
        ft_putnbr(n / 10);
    ft_putchar(n % 10 + '0');
}

int ft_atoi(char *nbr)
{
    int i = 0;
    int n = 0;
    int sign = 1;
    while (nbr[i] == ' ' || nbr[i] == '\t' || nbr[i] == '\v')
        i++;
    while (nbr[i] == '-' || nbr[i] == '+')
    {
        if (nbr[i] == '-')
            sign *= -1;
        i++;
    }
    while (nbr[i] >= '0' && nbr[i] <= '9')
    {
        n = n * 10 + (nbr[i] - '0');
        i++;
    }
    return(n * sign);
}

int ft_isprime(int n)
{
    int i = 1;
    if (n <= 1)
        return (0);
    while (i * i <= n)
    {
        if (n % i == 0)
            return (0);
        i++;
    }
    return (1);
}

int main(int argc, char **argv)
{
    int n;
    int i = 1;
    int result = 0;
    if (argc == 2)
    {
        n = ft_atoi(argv[1]);
        if (n < 0)
        {
            ft_putchar('0');
            ft_putchar('\n');
            return (0);
        }
        while (++i <= n)
        {
            if (ft_isprime(i))
                result += i;
        }
        ft_putnbr(result);
    }
    else
        ft_putchar('0');
    ft_putchar('\n');
    return (0);
}