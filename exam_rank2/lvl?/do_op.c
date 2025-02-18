#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int a;
    int b;
    if (argc == 4)
    {
        int a = atoi(argv[1]);
        int b = atoi(argv[3]);
        if (argv[2][0] == '-')
            printf("%d", (a - b));
        else if (argv[2][0] == '+')
            printf("%d", (a + b));
        else if (argv[2][0] == '*')
            printf("%d", (a * b));
        else if (argv[2][0] == '/')
            printf("%d", (a / b));
        else if (argv[2][0] == '%')
            printf("%d", (a % b));
    }
    printf("\n");
    return (0);
}
