#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_atoi(const char *str)
{
	int result = 0;
	int i = 0;
	int sign = 1;
	while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

void print_hex(int n)
{
	char *base = "0123456789abcdef";
	if (n >= 16)
		print_hex(n / 16);
	ft_putchar(base[n % 16]);
}

void ft_putnbr(int n)
{
	long num = n;
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	if (num > 9)
		ft_putnbr(num / 10);
	ft_putchar((num % 10) + '0');
}

int main(int argc, char **argv)
{
	int num = 0;
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));
	ft_putchar('\n');
	return (0);
}