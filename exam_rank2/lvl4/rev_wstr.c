#include <stdlib.h>
#include <unistd.h>

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
	int wc = 0;
	while (str[i] != '\0')
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i])
			wc++;
		while (str[i] && str[i] != ' ')
			i++;
	}
	char **result = (char **)malloc(sizeof(char *) * (wc + 1));
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] && str[i] == ' ')
			i++;
		j = i;
		while (str[i] && str[i] != ' ')
			i++;
		if (i > j)
		{
			result[k] = (char *)malloc((i - j) + 1);
			result[k] = ft_strncpy(result[k], &str[j], (i - j));
			k++;
		}
	}
	result[k] = NULL;
	return (result);
}

int main(int argc, char **argv)
{
	int i = 0;
	int count = 0;
	char **result;
	if (argc == 2)
	{
		result = ft_split(argv[1]);
		while (result[count] != NULL)
			count++;
		count--;
		while (count >= 0)
		{
			ft_putstr(result[count]);
			if (count != 0)
				ft_putchar(' ');
			count--;
		}
	}
	ft_putchar('\n');
	return (0);
}