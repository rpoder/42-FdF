/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:53:12 by rpoder            #+#    #+#             */
/*   Updated: 2022/05/11 17:38:57 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_line_count(int fd)
{
	int			count;
	char		*buf;
	int			ret;
	t_last_seen	*last_seen;

	count = 1;
	last_seen = malloc(sizeof(t_last_seen));
	if (!last_seen)
		return (-1);
	last_seen->i = 0;
	buf = malloc(sizeof(char));
	if (!buf)
		return (free(last_seen), -1);
	ret = read(fd, buf, 1);
	if (ret <= 0)
		return ((free(buf), free(last_seen), close(fd)), -1);
	count = line_loop(fd, buf, count, last_seen);
	close(fd);
	if (last_seen->i - last_seen->last == 1)
		count = count - 1;
	free (last_seen);
	return (count);
}

int	line_loop(int fd, char *buf, int count, t_last_seen *last_seen)
{
	int	ret;

	ret = 1;
	while (ret != 0)
	{
		if (*buf == 10)
		{
			count++;
			last_seen->last = last_seen->i;
		}
		last_seen->i++;
		ret = read(fd, buf, 1);
	}
	free(buf);
	return (count);
}

int	*get_line(int fd, t_int_tab *s_tab, int k)
{
	int		*tab;
	char	*tmp;
	char	**splitted;
	int		i;

	tmp = get_next_line(fd, k);
	if (!tmp)
		return (NULL);
	splitted = ft_split(tmp, ' ');
	s_tab->x_max = ft_strlen_split(splitted);
	tab = malloc(sizeof(int) * s_tab->x_max);
	i = 0;
	while (i < s_tab->x_max)
	{
		tab[i] = ft_atoi(splitted[i]);
		i++;
	}
	free(tmp);
	ft_free_double_char(splitted, s_tab->x_max);
	return (tab);
}

int	tab_parser(char *to_open, t_int_tab *s_tab)
{
	int			i;
	int			fd;
	int			k;
	int			fd_get_line;

	fd = open(to_open, O_RDONLY);
	fd_get_line = open(to_open, O_RDONLY);
	if (fd <= 0 || fd_get_line <= 0)
		return (0);
	s_tab->y_max = get_line_count(fd_get_line);
	if (s_tab->y_max <= 0)
		return (close (fd), -1);
	s_tab->tab = malloc(sizeof(int *) * s_tab->y_max);
	if (!s_tab->tab)
		return (0);
	i = 0;
	k = s_tab->y_max - 1;
	while (i < s_tab->y_max)
	{
		s_tab->tab[i] = get_line(fd, s_tab, k);
		i++;
		k--;
	}
	return (close(fd), 1);
}
