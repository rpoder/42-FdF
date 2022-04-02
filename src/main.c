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
		//count--;
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

int	*get_line(int fd, t_int_tab *s_tab)
{
	int		*tab;
	char	**line;
	int		x_max;
	int		i;

	line = ft_split(get_next_line(fd), ' ');
	if (!line)
		return (NULL);
	s_tab->x_max = ft_strlen_split(line);
	tab = malloc(s_tab->x_max * sizeof(int));
	if (!tab)
		return (NULL);
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
		i++;
	}
	close(fd);
	return (s_tab);
}

void	draw_line(t_data img, int xStart, int yStart, int xEnd, int yEnd)
{
	int	dx;
	int	dy;
	int	pk;
	int	x;
	int	y;
	int	count;
	int	tmp;


	x = xStart;
	y = yStart;
	count = 0;
	printf("dx = %d\n", dx);

	tmp = xEnd;
	xEnd = xStart;
	xStart = tmp;
	dx = xEnd - xStart;
	dy = yEnd - yStart;
	pk = 2 * dy - dx;
	while(count < dx)
	{
		printf("x = %d, y = %d\n", x, y);
		if(pk >= 0)
		{
			printf("in if ");
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			y = y + 1;
			pk = pk + 2 * dy - 2 * dx;
		}
		else
		{
			printf("in else ");
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			pk = pk + 2 * dy;
		}
	x = x + 1;
	count ++;
	}
}

void	print_tab_to_window(t_data img, t_int_tab *map)
{
	int	i;
	int	j;
	int	zoom;
	int	offset;
	int	x;
	int	y;

	i = 0;
	zoom = 20;
	offset = 300;
	while (i < map->y_max)
	{
		j = 0;
		while (j < map->x_max)
		{
		//	printf("i = %d | j = %d\n", i, j);
			x = (i * zoom + j * zoom) + offset;
			y = (i * zoom - j * zoom) / 2 + offset;
			//printf("A(%d, %d)\n", x, y);
			my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
			j++;
		}
		i++;
	}
}

int	handle_no_event(void *data)
{
		return (0);
}

int	handle_input(int keysym, t_win_data *win_data)
{
	if (keysym == 53)
	{
		mlx_destroy_window(win_data->mlx_ptr, win_data->win_ptr);
		exit(0);
	}
	//ft_printf("Keypress: %d\n", keysym);
	return (0);
}

void	draw_tab(t_data	img, t_int_tab *map)
{
	int	i;
	int	j;
	int	zoom;
	int	offset;
	int	x_start;
	int	y_start;
	int	x_end;
	int	y_end;

	i = 0;
	zoom = 20;
	offset = 300;
	i = 0;
	j = 0;
	x_start = (i * zoom + j * zoom) + offset;
	y_start = (i * zoom - j * zoom)/2 + offset;
	x_end = ((i) * zoom + (j + 1) * zoom) + offset;
	y_end = ((i) * zoom - (j + 1) * zoom)/2 + offset;
	printf("start: (%d, %d)\nend: (%d, %d)\n", x_start, y_start, x_end, y_end);
	draw_line(img, x_start, y_start, x_end, y_end);
	// while (i < map->y_max)
	// {
	// 	j = 0;
	// 	while (j < map->x_max)
	// 	{
	// 		x_start = i * (zoom / 2) + j * (zoom / 2) + offset;
	// 		y_start = i * (zoom / 2) - j * (zoom / 2) + offset;
	// 		x_end = (i + 1) * (zoom / 2) + (j + 1)  * (zoom / 2) + offset;
	// 		y_end = (i + 1) * (zoom / 2) - (j + 1) * (zoom / 2) + offset;
	// 		draw_line(img, x_start, y_start, x_end, y_end);
	// 		j++;
	// 	}
	// 	i++;
	// }
}

int	main(int argc, char **argv)
{
	t_data		img;
	t_win_data	win_data;
	t_int_tab	*s_tab;
	
	s_tab = init_s_tab();
	//int	n;
//	char	***map;
//	int		fd;
//	char *ret;
//	fd = open("map.fdf", O_RDONLY);
//	ft_printf("nombre de lignes = %d", get_line_count(fd));

//	map = get_map(fd, 10);
	//ft_print_double_char_tab(map);
	//ft_printf("result %s", map[0][4]);



	// ft_print_doubleinttab(s_tab->tab, s_tab->y_max, s_tab->x_max);
	get_int_map(argv[1], s_tab);

	win_data.mlx_ptr = mlx_init();
	if (win_data.mlx_ptr == NULL)
		return (0);
	win_data.win_ptr = mlx_new_window(win_data.mlx_ptr, 1920, 1080, "Hello world!");
	if (win_data.win_ptr == NULL)
	{
		free(win_data.win_ptr);
		return (0);
	}
	//hooks
	mlx_loop_hook(win_data.mlx_ptr, &handle_no_event, &win_data);
	mlx_key_hook(win_data.win_ptr, &handle_input, &win_data);	
	
	
	img.img = mlx_new_image(win_data.mlx_ptr, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	//draw_tab(img, s_tab);
	draw_line(img, 300, 300, 350, 260);

	print_tab_to_window(img, s_tab);
	//draw_tab(img, s_tab);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);	
	mlx_put_image_to_window(win_data.mlx_ptr, win_data.win_ptr, img.img, 0, 0);
	
	mlx_loop(win_data.mlx_ptr);


}
