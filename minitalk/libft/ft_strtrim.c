/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjurdana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:15:26 by pjurdana          #+#    #+#             */
/*   Updated: 2024/10/14 13:15:29 by pjurdana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const	*s1, char const	*set)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	j = ft_strlen((char *)s1 + 1);
	if (!s1 || !set)
		return (NULL);
	while ((size_t) k < ft_strlen(set))
	{
		if (s1[i] == set[k])
		{
			i++;
			k = 0;
		}
		else if (s1[j] == set[k])
		{
			j--;
			k = 0;
		}
		else
			k++;
	}
	return (ft_substr(s1, i, j - i + 1));
}
