/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjurdana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:31:21 by pjurdana          #+#    #+#             */
/*   Updated: 2024/11/01 16:31:23 by pjurdana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printhexa_u_fd(unsigned int n)
{
	int		j;
	char	*hexa;

	hexa = "0123456789ABCDEF";
	j = 0;
	if (n <= 15)
		j += ft_printchar_fd(hexa[n]);
	else
	{
		j += ft_printhexa_u_fd(n / 16);
		j += ft_printhexa_u_fd(n % 16);
	}
	return (j);
}

int	ft_print_unsigned_nbr_fd(int n)
{
	unsigned int	i;
	int				j;

	j = 0;
	i = n;
	if (i <= 9)
		j += ft_printchar_fd(i + '0');
	else
	{
		j += ft_print_unsigned_nbr_fd(i / 10);
		j += ft_print_unsigned_nbr_fd(i % 10);
	}
	return (j);
}

int	ft_printhexa_p_fd(unsigned long int n)
{
	int		j;
	char	*hexa;

	j = 0;
	hexa = "0123456789abcdef";
	if (n <= 15)
		j += ft_printchar_fd(hexa[n]);
	else
	{
		j += ft_printhexa_p_fd(n / 16);
		j += ft_printhexa_p_fd(n % 16);
	}
	return (j);
}

int	ft_printnil(unsigned long int n)
{
	int	j;

	if (!n)
	{
		j = write (1, "(nil)", 5);
		return (j);
	}
	j = write(1, "0x", 2);
	j += ft_printhexa_p_fd(n);
	return (j);
}
