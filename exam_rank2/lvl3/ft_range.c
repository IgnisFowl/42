#include <stdlib.h>
#include <stdio.h>

int     *ft_range(int start, int end)
{
	int len = start - end;
	int i = 0;
	int step = 1;
	if (len < 0)
		len *= -1;
	len++;
	int *result = (int *)malloc(sizeof(int) * len);
	if (end < start)
		step = -1;
	while (i < len)
	{
		result[i] = start;
		printf("%d\n", result[i]);
		start += step;
		i++;
	}
	return (result);
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_range(atoi(argv[1]), atoi(argv[2]));
	}
	return (0);
}
