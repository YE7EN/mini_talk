/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjurdana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:07:19 by pjurdana          #+#    #+#             */
/*   Updated: 2024/10/09 12:07:50 by pjurdana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*ndest;
	const char	*nsrc;

	ndest = dest;
	nsrc = src;
	if (ndest == NULL && nsrc == NULL)
		return (dest);
	if (!n)
		return (dest);
	if (ndest < nsrc)
	{
		return (ft_memcpy(ndest, src, n));
	}
	while (n > 0)
	{
		ndest[n -1] = nsrc[n - 1];
		n--;
	}
	return (dest);
}
