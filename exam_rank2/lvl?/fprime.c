#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int i = 1;
    int n = 0;
    if (argc == 2)
    {
        n = atoi(argv[1]);
        while(n >= ++i)
        {
            if (n % i == 0)
            {
                printf("%d", i);
                if (i == n)
                    break ;
                printf("*");
                n /= i;
                i = 1;
            }
        }
    }
    printf("\n");
    return (0);
}
