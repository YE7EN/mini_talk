/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjurdana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:39:10 by pjurdana          #+#    #+#             */
/*   Updated: 2024/10/22 15:39:12 by pjurdana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	size;

	if (!lst)
		return (NULL);
	size = ft_lstsize(lst);
	while (size - 1 > 0)
	{
		lst = lst->next;
		size--;
	}
	return (lst);
}
