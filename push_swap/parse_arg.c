/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:50:26 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2025/02/01 10:23:19 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_repeated(int n, char **argv, int i)
{
	i += 1;
	while (argv[i])
	{
		if (n == ft_atoi(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *n)
{
	int	i;

	i = 0;
	if (!n || n[0] == '\0')
		return (0);
	if (n[0] == '-' || n[0] == '+')
		i++;
	if (!ft_isdigit(n[i]))
		return (0);
	while (n[i])
	{
		if (!ft_isdigit(n[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	parse_args(char **args, int i, int argc)
{
	long	temp;

	temp = 0;
	while (args[i])
	{
		temp = ft_atol(args[i]);
		if (!ft_isnum(args[i]) || temp < INT_MIN || temp > INT_MAX || \
		temp == LONG_MAX || temp == LONG_MIN)
		{
			if (argc == 2)
				ft_free(args);
			return (0);
		}
		if (is_repeated(temp, args, i))
		{
			if (argc == 2)
				ft_free(args);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_args(int argc, char **argv)
{
	int		i;
	char	**args;

	i = 0;
	args = NULL;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
		{
			ft_free(args);
			return (0);
		}
	}
	else
	{
		i = 1;
		args = argv;
	}
	if (!parse_args(args, i, argc))
		return (0);
	if (argc == 2)
		ft_free(args);
	return (1);
}
