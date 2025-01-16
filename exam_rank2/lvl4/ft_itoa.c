#include <stdlib.h>
#include <stdio.h>

int how_many_digits(int n)
{
	int len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while(n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	int len = how_many_digits(nbr);
	int num = nbr;
	char *result;

	if (num < 0)
	{
		num *= -1;
		result = (char *)malloc(len + 2);
		result[0] = '-';
	}
	else
		result = (char *)malloc(len + 1);
	result[len] = '\0';
	while (len--)
	{
		result[len] = num % 10 + '0';
		num /= 10;
	}
	return (result);
}

int main(void)
{
	int a = 42;
	printf("%s", ft_itoa(a));
	return (0);
}