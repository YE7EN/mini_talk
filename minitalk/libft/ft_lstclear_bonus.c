/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjurdana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:42:24 by pjurdana          #+#    #+#             */
/*   Updated: 2024/10/23 09:42:26 by pjurdana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*n;

	if (!lst || !(*lst) || !del)
		return ;
	while (lst && *lst)
	{
		n = (*lst)->next;
		ft_lstdelone((*lst), del);
		*lst = n;
	}
	*lst = NULL;
}
