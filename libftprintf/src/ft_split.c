/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:57:00 by rpoder            #+#    #+#             */
/*   Updated: 2021/12/07 19:27:39 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_handle_free(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (NULL);
}

static int	ft_count_words(char const *str, char charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != charset)
		{
			count ++;
			while (str[i] != charset && str[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	ft_count_c(char const *str, char charset, int start)
{
	int	count;

	count = 0;
	while (str[start] == charset && str[start])
		start++;
	while (str[start] != charset && str[start])
	{
		count++;
		start++;
	}
	return (count);
}

static char	**ft_assign(char **tab, const char *str, char c, int nb_words)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i < nb_words)
	{
		k = 0;
		while (str[j] == c)
			j++;
		tab[i] = (char *)malloc(sizeof(char) * (ft_count_c(str, c, j) + 1));
		if (!tab[i])
			return (ft_handle_free(tab, i));
		while (str[j] && str[j] != c)
		{
			tab[i][k] = str[j];
			k++;
			j++;
		}
		tab[i][k] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char	**ft_split(char const *str, char charset)
{
	int		nb_words;
	char	**tab;

	if (!str)
		return (NULL);
	nb_words = ft_count_words(str, charset);
	tab = (char **)ft_calloc(nb_words + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	tab = ft_assign(tab, str, charset, nb_words);
	return (tab);
}
