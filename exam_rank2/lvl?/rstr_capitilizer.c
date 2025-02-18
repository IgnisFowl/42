#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_strcapitalizer(char *argv)
{
    int i = 0;
    while(argv[i])
    {
        if ((argv[i] >= 'a' && argv[i] <= 'z') && (argv[i + 1] == ' ' || argv[i + 1] == '\t' || argv[i + 1] == '\v' || argv[i + 1] == '\0'))
            ft_putchar(argv[i] - 32);
        else if ((argv[i] >= 'A' && argv[i] <= 'Z') && !(argv[i + 1] == ' ' || argv[i + 1] == '\t' || argv[i + 1] == '\v' || argv[i + 1] == '\0'))
            ft_putchar(argv[i] + 32);
        else
            ft_putchar(argv[i]);
        i++;
    }
}


int main(int argc, char **argv)
{
    int j = 1;
    if (argc >= 2)
    {
        while (j <= argc)
        {
            ft_strcapitalizer(argv[j]);
            ft_putchar('\n');
            j++;
        }
    }
    ft_putchar('\n');
    return (0);
}