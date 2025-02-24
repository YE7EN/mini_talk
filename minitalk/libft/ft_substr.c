/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjurdana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:19:51 by pjurdana          #+#    #+#             */
/*   Updated: 2024/10/11 14:19:53 by pjurdana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dup;
	size_t	length;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	length = ft_strlen(s + start);
	if (len > length)
		len = length;
	dup = malloc(len + 1 * sizeof(char));
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, s + start, len);
	dup[len] = '\0';
	return (dup);
}
