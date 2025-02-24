/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjurdana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:36:47 by pjurdana          #+#    #+#             */
/*   Updated: 2024/10/09 11:40:06 by pjurdana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*ndest;
	const char	*nsrc;

	ndest = dest;
	nsrc = src;
	if (ndest == NULL && nsrc == NULL)
		return (dest);
	while (n > 0)
	{
		*ndest = *nsrc;
		ndest++;
		nsrc++;
		n--;
	}
	return (dest);
}
