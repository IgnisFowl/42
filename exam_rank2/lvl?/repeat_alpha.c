#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    int i = 0;
    int j = 0;

    if (argc == 2)
    {
        while (argv[1][i] != '\0')
        {
            if ((argv[1][i] >= 97 && argv[1][i] <= 122))
            {
                j = argv[1][i] - 96;
                while (j > 0)
                {
                    ft_putchar(argv[1][i]);
                    j--;
                }
            }
            else if ((argv[1][i] >= 65 && argv[1][i] <= 90))
            {
                j = argv[1][i] - 64;
                while (j > 0)
                {
                    ft_putchar(argv[1][i]);
                    j--;
                }
            }
            else
                ft_putchar(argv[1][i]);
            i++;
        }
    }
    ft_putchar('\n');
    return (0);
}