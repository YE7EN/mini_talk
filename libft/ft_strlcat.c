/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjurdana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:44:56 by pjurdana          #+#    #+#             */
/*   Updated: 2024/10/09 13:46:56 by pjurdana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	lendst;
	size_t	lensrc;

	if (!size)
		return (ft_strlen((char *)src));
	len = ft_strlen((char *)src) + ft_strlen(dst);
	lendst = ft_strlen(dst);
	lensrc = ft_strlen((char *)src);
	if (size < lendst)
		return (lensrc + size);
	while (lendst < len && lendst < size - 1)
	{
		dst[lendst] = *src;
		src++;
		lendst++;
	}
	dst[lendst] = 0;
	return (len);
}
