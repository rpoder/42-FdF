/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_addons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:59:52 by rpoder            #+#    #+#             */
/*   Updated: 2022/05/14 17:00:25 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strrstrchr(char *str, char *set)
{
	size_t	i;
	size_t	j;
	size_t	set_len;

	i = ft_strlen(str);
	set_len = ft_strlen(set);
	j = 0;
	while (i > 0 && j < set_len)
	{
		if (str[i] != set[set_len])
			return (0);
		j++;
		set_len--;
		i--;
	}
	return (1);
}

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
