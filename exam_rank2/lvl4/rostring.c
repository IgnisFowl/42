#include <unistd.h>
#include <stdlib.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	int i = 0;
	if (!str)
		return ;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

char *ft_strncpy(char *s1, char *s2, int n)
{
	int i = 0;
	if (!s1 || !s2)
		return NULL;
	while (i < n && s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char **ft_split(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int cw = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i])
			cw++;
		while (str[i] && str[i] != ' ')
			i++;
	}
	char **result = (char **)malloc(sizeof(char *) * (cw + 1));
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		j = i; // start of word
		while (str[i] && str[i] != ' ')
			i++;
		if (i > j)
		{
			result[k] = (char *)malloc((i - j) + 1);
			ft_strncpy(result[k], &str[j], (i - j));
			k++;
		}
	}
	result[k] = NULL;
	return (result);
}

int main(int argc, char **argv)
{
	int i = 1;
	if (argc == 2)
	{
		char **result = ft_split(argv[1]);
		while (result[i] != NULL)
		{
			ft_putstr(result[i]);
			ft_putchar(' ');
			i++;
		}
		ft_putstr(result[0]);
	}
	ft_putchar('\n');
	return (0);
}