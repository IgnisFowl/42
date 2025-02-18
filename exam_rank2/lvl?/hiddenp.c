#include <unistd.h>

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
        while(argv[2][j] != '\0')
        {
            if (argv[1][i] == argv[2][j])
                i++;
            j++;
        }
        if(argv[1][i] == '\0')
            ft_putchar('1');
        else
            ft_putchar('0');        
    }
    ft_putchar('\n');
    return (0);
}
