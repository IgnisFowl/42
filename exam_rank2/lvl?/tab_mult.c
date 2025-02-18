#include <unistd.h>
#include <stddef.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *c)
{
    int i = 0;

    while (c[i] != '\0')
    {
        ft_putchar(c[i]);
        i++;
    }
}

void ft_putnbr(int n)
{
    long int    num = n;

    if (num == 0)
    {
        ft_putchar('0');
        return ;
    }
    if (num > 9)
    {
        ft_putnbr(num / 10);
    }
    ft_putchar((num % 10) + '0');
}

size_t ft_strlen(char *str)
{
    size_t c = 0;
    while (str[c] != '\0')
        c++;
    return (c);
}

int ft_atoi(char *str)
{
    size_t  i = 0;
    unsigned int     num = 0;

    while (str[i] >= '0' && str[i] <= '9')
    {
        num = num * 10 + (str[i] - '0');
        i++;
    }
    return (num);
}

int main(int argc, char **argv)
{
    int j = 1;

    if (argc == 2)
    {
        unsigned int num = ft_atoi(argv[1]);
        while (j < 10)
        {
            ft_putnbr(j);
            ft_putstr(" x ");
            ft_putnbr(num);
            ft_putstr(" = ");
            ft_putnbr(num * j);
            ft_putchar('\n');
            j++;
        }
    }
    else
        ft_putchar('\n');
    return (0);
}