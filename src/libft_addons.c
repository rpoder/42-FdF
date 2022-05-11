/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_addons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:59:52 by rpoder            #+#    #+#             */
/*   Updated: 2022/05/11 17:16:15 by rpoder           ###   ########.fr       */
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