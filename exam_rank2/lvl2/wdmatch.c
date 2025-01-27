#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    int i = 0;
    int j = 0;

    if (argc == 3)
    {
        while(argv[2][j])
        {
            if(argv[1][i] == argv[2][j])
                i++;
            else
                j++;
            if(argv[1][i] == '\0')
            {
                i = 0;
                while(argv[1][i] != '\0')
                    ft_putchar(argv[1][i]);
            }
        }
    }
    ft_putchar('\n');
    return (0);
}