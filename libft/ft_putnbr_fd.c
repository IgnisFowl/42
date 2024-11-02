/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:20:24 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2024/10/16 16:46:56 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	num;

	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	if (num == 2147483648)
	{
		ft_putstr_fd("2147483648", fd);
		return ;
	}
	if (num == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (num > 9)
		ft_putnbr_fd(num / 10, fd);
	ft_putchar_fd((num % 10) + '0', fd);
}
