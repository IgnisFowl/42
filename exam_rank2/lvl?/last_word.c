#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int is_printable(char c)
{
    return (c >= 33 && c <= 126);
}

int find_last_space(char *str)
{
    int i = 0;
    int last_space = 0;

    while(str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            if ((is_printable(str[i - 1])) && (is_printable(str[i + 1])))
                last_space = i;
            i++;
        }
        else
            i++;
    }
    return(last_space);
}

int main(int argc, char **argv)
{
    int i = 0;

    if (argc == 2)
    {
        i = find_last_space(argv[1]) + 1;
        while(argv[1][i] != '\0')
        {
            if (argv[1][i] != ' ')
            {
                ft_putchar(argv[1][i]);
                i++;
            }
            else
                i++;
        }
    }
    ft_putchar('\n');
    return (0);
}  
