/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:22:19 by rpoder            #+#    #+#             */
/*   Updated: 2021/12/03 19:08:59 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*todelete;

	if (!*lst || !del)
		return ;
	while ((*lst)->next != NULL)
	{
		todelete = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(todelete, del);
	}
	if ((*lst)->next == NULL)
		ft_lstdelone(*lst, del);
	*lst = NULL;
}
