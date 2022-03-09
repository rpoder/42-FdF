/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:13:55 by rpoder            #+#    #+#             */
/*   Updated: 2022/03/09 18:27:50 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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

	count = 0;
	if (tab)
	{
		while (tab[count])
		{
			count++;
		}
		count--;
	}
	return (count);
}

int	get_line_count(char *to_open)
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

t_int_tab	*init_s_tab(void)
{
	t_int_tab	*s_tab;

	s_tab = malloc(sizeof(s_tab));
	if (!s_tab)
		return (NULL);
	s_tab->tab = NULL;
	s_tab->x_max = 0;
	s_tab->y_max = 0;
	return (s_tab);
}

char	***get_map(int fd, int map_height)
{
	char	***map;
	char	*ret;
	int		i;

	i = 0;
	map = malloc((map_height + 1) * sizeof(char **));
	map[map_height] = NULL;
	while (i < map_height)
	{
		map[i] = ft_split(get_next_line(fd), ' ');
		//verifier split
		i++;
	}
	return (map);
}

t_int_tab	*get_int_map(char *to_open)
{
	t_int_tab	*s_tab;
	int			fd;

	s_tab = init_s_tab();
	s_tab->y_max = get_line_count(to_open);
	ft_printf("y_max = %d\n", s_tab->y_max);
	s_tab->tab = malloc(s_tab->y_max * sizeof(int *));
	if (!s_tab->tab)
		return (NULL);
	fd = open(to_open, O_RDONLY);
	if (fd < 0)
		return (NULL);
	close(fd);
	return (s_tab);
}

void	print_tab_to_window(t_data	img, char ***tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			my_mlx_pixel_put(&img, i * 100, j * 100, 0x00FF0000);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	//int	n;
//	char	***map;
//	int		fd;
//	char *ret;
//	fd = open("map.fdf", O_RDONLY);
//	ft_printf("nombre de lignes = %d", get_line_count(fd));

//	map = get_map(fd, 10);
	//ft_print_double_char_tab(map);
	//ft_printf("result %s", map[0][4]);

	get_int_map(argv[1]);




	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// mlx_loop(mlx);
}
