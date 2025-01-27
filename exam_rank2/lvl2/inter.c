#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int is_duplicate(char c, char *str, int index)
{
    int i = 0;
    while (i < index)
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    int i = 0;
    int j = 0;

    if (argc == 3)
    {
        while (argv[1][i])
        {
            if (!is_duplicate(argv[1][i], argv[1], i))
            {
                j = 0;
                while (argv[2][j])
                {
                    if (argv[1][i] == argv[2][j])
                    {
                        ft_putchar(argv[1][i]);
                        break;
                    }
                    j++;
                }
            }
            i++;
        }
    }
    ft_putchar('\n');
    return (0);
}