/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjurdana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:58:53 by pjurdana          #+#    #+#             */
/*   Updated: 2024/11/01 11:58:55 by pjurdana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printchar_fd(char c)
{
	size_t	j;

	j = 0;
	j += write(1, &c, 1);
	return (j);
}

int	ft_printstr_fd(char *s)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (!s)
	{
		j += write (1, "(null)", 6);
		return (j);
	}
	i = 0;
	while (s[i])
		i++;
	j += write(1, s, i);
	return (j);
}

int	ft_printnbr_fd(int n)
{
	int	i;
	int	j;

	j = 0;
	i = n;
	if (i == -2147483648)
	{
		j += write(1, "-2147483648", 11);
		return (j);
	}
	if (i < 0)
	{
		j += ft_printchar_fd('-');
		i = -i;
	}
	if (i <= 9)
		j += ft_printchar_fd(i + '0');
	else
	{
		j += ft_printnbr_fd(i / 10);
		j += ft_printnbr_fd(i % 10);
	}
	return (j);
}

int	ft_printhexa_l_fd(unsigned int n)
{
	int		j;
	char	*hexa;

	hexa = "0123456789abcdef";
	j = 0;
	if (n <= 15)
		j += ft_printchar_fd(hexa[n]);
	else
	{
		j += ft_printhexa_l_fd(n / 16);
		j += ft_printhexa_l_fd(n % 16);
	}
	return (j);
}
