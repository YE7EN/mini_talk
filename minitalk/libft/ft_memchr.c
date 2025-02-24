/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjurdana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:08:02 by pjurdana          #+#    #+#             */
/*   Updated: 2024/10/10 15:08:03 by pjurdana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;	

	ptr = (unsigned char *)s;
	while (n--)
	{
		if (*ptr == (unsigned char) c)
			return (ptr);
		ptr++;
	}
	return (NULL);
}
