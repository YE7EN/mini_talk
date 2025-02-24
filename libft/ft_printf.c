/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjurdana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:13:27 by pjurdana          #+#    #+#             */
/*   Updated: 2024/10/31 12:13:31 by pjurdana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_type(va_list ap, char type)
{
	int	len;

	len = 0;
	if (type == 'c')
		len += ft_printchar_fd(va_arg(ap, int));
	else if (type == 's')
		len += ft_printstr_fd(va_arg(ap, char *));
	else if (type == 'p')
		len += ft_printnil(va_arg(ap, unsigned long int));
	else if (type == 'd' || type == 'i')
		len += ft_printnbr_fd(va_arg(ap, int));
	else if (type == 'u')
		len += ft_print_unsigned_nbr_fd(va_arg(ap, unsigned int));
	else if (type == 'x')
		len += ft_printhexa_l_fd(va_arg(ap, unsigned int));
	else if (type == 'X')
		len += ft_printhexa_u_fd(va_arg(ap, unsigned int));
	else if (type == '%')
		len += ft_printchar_fd('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		total;

	if (!str)
		return (-1);
	i = 0;
	total = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			total += ft_type(ap, str[i + 1]);
			i++;
		}
		else
			total += write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (total);
}
