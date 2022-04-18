/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:53:12 by rpoder            #+#    #+#             */
/*   Updated: 2022/04/18 15:22:05 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_line_count(char *to_open)
{
	int		count;
	int		ret;
	char 	*buf;
	int		fd;

	count = 0;
	ret = 1;
	fd = open(to_open, O_RDONLY);
	if (fd < 0)
		return (-1);
	buf = malloc(sizeof(char));
	if(!buf)
		return (-1);
	while (ret != 0)
	{
		ret = read(fd, buf, 1);
		if (buf[0] == '\n')
			count++;
	}
	free(buf);
	close(fd);
	return (count - 1);
}

static int	*get_line(int fd, t_int_tab *s_tab)
{
	int		*tab;
	char	**line;
	int		i;

	line = ft_split(get_next_line(fd), ' ');
	if (!line)
		return (NULL);
	s_tab->x_max = ft_strlen_split(line);
	tab = malloc(s_tab->x_max * sizeof(int));
	if (!tab)
    {
        free(line);
		return (NULL);
    }
	i = 0;
	while (line[i])
	{
		tab[i] = ft_atoi(line[i]);
		i++;
	}
	free(line);
	return (tab);
}

t_int_tab	*get_int_map(char *to_open, t_int_tab *s_tab)
{
	int			fd;
	int			i;

	s_tab->y_max = get_line_count(to_open);
	s_tab->tab = malloc(s_tab->y_max * sizeof(int *));
	if (!s_tab->tab)
		return (NULL);
	fd = open(to_open, O_RDONLY);
	if (fd < 0)
		return (NULL);
	i = 0;
	while (i < s_tab->y_max)
	{
		s_tab->tab[i] = get_line(fd, s_tab);
        if (!s_tab->tab[i])
        {
            ft_free_double_int(s_tab->tab, i);
            return (0);
        }
		i++;
	}
	close(fd);
	return (s_tab);
}