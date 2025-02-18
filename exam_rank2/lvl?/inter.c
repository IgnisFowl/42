#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    int i = 0;
    int j = 0;
    char seen[256] = {0};
    if (argc == 3)
    {
        while(argv[1][i])
        {
            j = 0;
            while (argv[2][j])
            {
                if (argv[1][i] == argv[2][j])
                {
                    if (!(seen[argv[1][i]]))
                    {
                        ft_putchar(argv[1][i]);
                        seen[argv[1][i]] = 1;
                    }
                    break ;
                }
                j++;
            }
            i++;
        }
        
    }
    ft_putchar('\n');
    return (0);
}
