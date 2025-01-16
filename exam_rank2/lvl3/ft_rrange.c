#include <stdlib.h>
#include <stdio.h>

int     *ft_rrange(int start, int end)
{
	int len = end - start;
	int step = 1;
	int i = 0;
	int *result;
	if (len < 0)
		len *= -1;
	len++;
	result = (int *)malloc(sizeof(int) * len);
	if (end > start)
		step = -1;
	while (i < len)
	{
		result[i] = end;
		printf("%d\n", result[i]);
		end += step;
		i++;
	}
	return (result);
}

int main(int argc, char **argv)
{
	ft_rrange(-1, 2);
	return (0);
}