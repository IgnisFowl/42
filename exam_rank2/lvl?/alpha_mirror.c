#include <stdio.h>
#include <stdlib.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    int i = 0;
    if (argc == 2)
    {
        while (argv[1][i] != '\0')
        {
            if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
            {
                ft_putchar(123 - (argv[1][i] - 96));
            }
            else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
            {
                ft_putchar(91 - (argv[1][i] - 64));
            }
            else
                ft_putchar(argv[1][i]);
            i++;
        }
    }
    ft_putchar('\n');
    return (0);
}
