char *ft_strrev(char *str)
{
	int i = 0;
	int len = 0;
	char temp;

	while (str[len])
		len++;
	len--;
	while (i <= len / 2)
	{
		temp = str[i];
		str[i] = str[len - i];
		str[len - i] = temp;
		i++;
	}
	return (str);
}

#include <stdio.h>

int main(int argc, char **argv)
{
	int i = 0;
	if (argc == 2)
	{
		printf("%s\n", ft_strrev(argv[1]));
	}
	return (0);
}