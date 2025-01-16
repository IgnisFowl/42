int	ft_atoi_base(const char *str, int str_base)
{
	int num = 0;
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
		if (str[i] >= '0' && str[i] <= '9')
			num = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			num = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			num = str[i] - 'A' + 10;
		else
			break ;
		result = result * str_base + num;
		i++;
	}
	return (sign * num);
}
