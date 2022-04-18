/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:13:55 by rpoder            #+#    #+#             */
/*   Updated: 2022/04/18 15:34:28 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render_map(t_data	img, t_int_tab *map, t_win_data *win_data)
{
	int		i;
	int		j;
	t_point	*start;
	t_point	*stop;
	float	a;

	i = 0;
	j = 0;
	start = malloc(sizeof(t_point));
	stop = malloc(sizeof(t_point));
	a = 26.565;
	while (i < map->y_max)
	{
		j = 0;
		while (j < map->x_max)
		{
			if (j + 1 < map->x_max)
			{
				start->y = (i * cos(a) * win_data->zoom  - j * cos(a) * win_data->zoom) + win_data->y_offset - map->tab[i][j] * win_data->height;
				start->x = (i * sin(a) * win_data->zoom + j * sin(a) * win_data->zoom - 1 * win_data->zoom) + win_data->x_offset;
				stop->y = (i * cos(a) * win_data->zoom  - (j + 1) * cos(a) * win_data->zoom) + win_data->y_offset - map->tab[i][j + 1] * win_data->height;
				stop->x = (i * sin(a) * win_data->zoom + (j + 1) * sin(a) * win_data->zoom - 1 * win_data->zoom) + win_data->x_offset;
				ft_drawline(img, start, stop);
			}
			if (i + 1 < map->y_max)
			{
				start->y = (i * cos(a) * win_data->zoom  - j * cos(a) * win_data->zoom) + win_data->y_offset - map->tab[i][j] * win_data->height;
				start->x = (i * sin(a) * win_data->zoom + j * sin(a) * win_data->zoom - 1 * win_data->zoom) + win_data->x_offset;
				stop->y = ((i + 1) * cos(a) * win_data->zoom  - j * cos(a) * win_data->zoom) + win_data->y_offset - map->tab[i + 1][j] * win_data->height;
				stop->x = ((i + 1) * sin(a) * win_data->zoom + j * sin(a) * win_data->zoom - 1 * win_data->zoom) + win_data->x_offset;
				ft_drawline(img, start, stop);
			}
			j++;
		}
		i++;
	}
	free(start);
	free(stop);
}

int	main(int argc, char **argv)
{
	t_data		img;
	t_win_data	*win_data;
	t_int_tab	*s_tab;

	if (argc != 2)
		return (0);

	s_tab = set_s_tab();
	if (!s_tab)
		return (0);
	get_int_map(argv[1], s_tab);
	if (!s_tab->tab)
		return (0);
	
	win_data = set_win_data(s_tab);

	mlx_loop_hook(win_data->mlx_ptr, &handle_no_event, &win_data);
	mlx_key_hook(win_data->win_ptr, &handle_input, &win_data);

	img.img = mlx_new_image(win_data->mlx_ptr, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	render_map(img, s_tab, win_data);
	ft_free_double_int(s_tab->tab, s_tab->y_max);

	mlx_put_image_to_window(win_data->mlx_ptr, win_data->win_ptr, img.img, 0, 0);

	mlx_loop(win_data->mlx_ptr);

}
