/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:07:39 by rpoder            #+#    #+#             */
/*   Updated: 2022/03/05 16:07:40 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_inttab(int *tab, int size)
{
	int	i;

	i = 0;
	if (tab)
	{	
		while (i < size)
		{
			ft_printf("%d", tab[i]);
			i++;
		}
		printf("\n");
	}
}

void	ft_print_doubleinttab(int **tab, int h_size, int w_size)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (i < h_size)
		{
			ft_print_inttab(tab[i], w_size);
			i++;
		}
	}
}