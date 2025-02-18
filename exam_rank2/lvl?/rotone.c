#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    int i = 0;

    if(argc == 2)
    {
        while (argv[1][i] != '\0')
        {
            if (argv[1][i] >= 65 && argv[1][i] <= 90)
            {
                if (argv[1][i] == 'Z')
                    ft_putchar(argv[1][i] = 'A');
                else
                    ft_putchar(argv[1][i] += 1);
            }
            else if (argv[1][i] >= 97 && argv[1][i] <= 122)
            {
                if (argv[1][i] == 'z')
                    ft_putchar(argv[1][i] = 'a');
                else
                    ft_putchar(argv[1][i] += 1);
            }
            else
                ft_putchar(argv[1][i]);
            i++;
        }
    }
    ft_putchar('\n');
    return (0);
}