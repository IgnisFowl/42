#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int n)
{
    unsigned int num = n;
    if (num >= 10)
        ft_putnbr(num / 10);
    ft_putchar((num % 10) + '0');
}

int ft_atoi(char *c)
{
    int i = 0;
    int result = 0;
    while (c[i] != '\0')
    {
        result = result * 10 + (c[i] - '0');
        i++;
    }
    return (result);
}

int is_prime(int n)
{
    int i = 2;
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
    int num = 0;
    int result = 0;
    if (argc == 2 && argv[1][0] != '-')
    {
        num = ft_atoi(argv[1]);
        while (num > 0)
        {
            if (is_prime(num))
                result += num;
            num--;
        }
        ft_putnbr(result);
    }
    else
        ft_putchar('0');
    ft_putchar('\n');
    return (0);
}
