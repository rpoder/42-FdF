/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:48:48 by rpoder            #+#    #+#             */
/*   Updated: 2021/12/03 19:09:53 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*tmp;

	count = 0;
	tmp = lst;
	if (!lst)
		return (0);
	while (tmp->next != NULL)
	{
		count ++;
		tmp = tmp->next;
	}
	if (tmp->next == NULL)
		count++;
	return (count);
}
