#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    int i = 0;

    if (argc == 2)
    {
        while(argv[1][i] == ' ')
                i++;
        while(argv[1][i] != '\0')
        {
            if(argv[1][i] != ' ')
            {
                ft_putchar(argv[1][i]);
                i++;
            }
            if(argv[1][i] == ' ')
                break ;
        }

    }
    ft_putchar('\n');
    return (0);
} 
