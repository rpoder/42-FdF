/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_addons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:59:52 by rpoder            #+#    #+#             */
/*   Updated: 2022/05/07 00:14:27 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**ft_free_double_int(int **tab, int i)
{
	i--;
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (NULL);
}

char	**ft_free_double_char(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (NULL);
}

int	ft_strlen_split(char **tab)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			if (tab[i][0] != 10)
				count++;
			i++;
		}
	}
	return (count);
}

void	ft_print_double_tab(t_int_tab *s_tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < s_tab->x_max)
	{
		j = 0;
		while (j < s_tab->y_max)
		{
			ft_printf("%d", s_tab->tab[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
