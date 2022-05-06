/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:53:12 by rpoder            #+#    #+#             */
/*   Updated: 2022/05/06 23:20:52 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_line_count(char *to_open)
{
	int			count;
	char		*buf;
	int			ret;
	int			fd;
	t_last_seen last_seen;

	count = 1;
	buf = malloc(sizeof(char));
	if (!buf)
		return (-1);
	fd = open(to_open, O_RDONLY);
	while (ret != 0)
	{
		ret = read(fd, buf, 1);
		if (*buf == 10)
		{
			count++;
			last_seen.last = last_seen.i;
		}
		last_seen.i++;
	}
	free(buf);
	close(fd);
	if (last_seen.i - last_seen.last == 1)
		count = count - 2;
	return (count);
}

int	*get_line(int fd, t_int_tab *s_tab)
{
	int		*tab;
	char	*tmp;
	char	**splitted;
	int		i;

	i = 0;
	tmp = get_next_line(fd, 1);
	if (!tmp)
		return (NULL);
	splitted = ft_split(tmp, ' ');
	s_tab->x_max = ft_strlen_split(splitted);
	tab = malloc(sizeof(int) * s_tab->y_max);
	while (i < s_tab->x_max)
	{
		tab[i] = ft_atoi(splitted[i]);
		//ft_printf("|%d|\n", tab[i]);
		i++;
	}
	ft_free_double_char(splitted, s_tab->y_max);
	return (tab);
}

int	tab_parser(char *to_open, t_int_tab *s_tab)
{
	int			i;
	int			fd;

	fd = open(to_open, O_RDONLY);

	s_tab->y_max = get_line_count(to_open);
	s_tab->tab = malloc(sizeof(int *) * s_tab->y_max);
	if (!s_tab->tab)
		return (0);
	i = 0;
	while (i < s_tab->y_max)
	{
		s_tab->tab[i] = get_line(fd, s_tab);
		i++;
	}
	return (1);
}
