#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int a = atoi(argv[1]);
		int b = atoi(argv[2]);
		int c = 0;
		if (a > 0 && b > 0)
		{
			while (b != 0)
			{
				c = b;
				b = a % b;
				a = c;
			}
		}
		printf("%d", c);
	}
	printf("\n");
	return (0);
}