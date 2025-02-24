/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjurdana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:45:54 by pjurdana          #+#    #+#             */
/*   Updated: 2024/10/10 13:45:55 by pjurdana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ns;

	i = 0;
	ns = (char *)s;
	while (s[i])
		i++;
	if ((unsigned char)c == '\0')
	{
		while (*ns)
			ns++;
		return (ns);
	}
	while (s[i - 1] && i >= 0)
	{
		if (s[i - 1] == (unsigned char)c)
			return ((char *)s + i - 1);
		i--;
	}
	if (*s == 0 && (unsigned char)c == 0)
		return ((char *)s);
	return (NULL);
}
