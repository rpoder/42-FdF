/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:13:55 by rpoder            #+#    #+#             */
/*   Updated: 2022/04/22 17:02:39 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render_map(t_data	img, t_int_tab *map, t_win_data *win_data)
{
	t_info_draw	*infos;

	infos = malloc(sizeof(infos));
	infos->i = 0;
	infos->j = 0;
	infos->a = 26.565;
	while (infos->i < map->y_max)
	{
		infos->j = 0;
		while (infos->j < map->x_max)
		{
			if (infos->j + 1 < map->x_max)
				draw_v(img, infos, map, win_data);
			if (infos->i + 1 < map->y_max)
				draw_h(img, infos, map, win_data);
			infos->j++;
		}
		infos->i++;
	}
	free(infos);
}

void	draw_v(t_data img, t_info_draw *info, t_int_tab *map, t_win_data *win)
{
	int		i;
	int		j;
	float	a;
	t_point	*start;
	t_point	*stop;

	i = info->i;
	j = info->j;
	a = info->a;
	start = malloc(sizeof(t_point));
	stop = malloc(sizeof(t_point));
	start->y = (i * cos(a) * win->zoom - j * cos(a)
			* win->zoom) + win->y_offset - map->tab[i][j] * win->height;
	start->x = (i * sin(a) * win->zoom + j * sin(a)
			* win->zoom - 1 * win->zoom) + win->x_offset;
	stop->y = (i * cos(a) * win->zoom - (j + 1) * cos(a)
			* win->zoom) + win->y_offset - map->tab[i][j + 1] * win->height;
	stop->x = (i * sin(a) * win->zoom + (j + 1) * sin(a)
			* win->zoom - 1 * win->zoom) + win->x_offset;
	ft_drawline(img, start, stop);
	free(start);
	free(stop);
}

void	draw_h(t_data img, t_info_draw *info, t_int_tab *map, t_win_data *win)
{
	int		i;
	int		j;
	float	a;
	t_point	*start;
	t_point	*stop;

	i = info->i;
	j = info->j;
	a = info->a;
	start = malloc(sizeof(t_point));
	stop = malloc(sizeof(t_point));
	start->y = (i * cos(a) * win->zoom - j * cos(a)
			* win->zoom) + win->y_offset - map->tab[i][j] * win->height;
	start->x = (i * sin(a) * win->zoom + j * sin(a)
			* win->zoom - 1 * win->zoom) + win->x_offset;
	stop->y = ((i + 1) * cos(a) * win->zoom - j * cos(a)
			* win->zoom) + win->y_offset - map->tab[i + 1][j] * win->height;
	stop->x = ((i + 1) * sin(a) * win->zoom + j * sin(a)
			* win->zoom - 1 * win->zoom) + win->x_offset;
	ft_drawline(img, start, stop);
	free(start);
	free(stop);
}

int	main(int argc, char **argv)
{
	t_data		img;
	t_win_data	*win;
	t_int_tab	*s_tab;

	if (argc != 2)
		return (0);
	s_tab = set_s_tab();
	if (!s_tab)
		return (0);
	s_tab = get_int_map(argv[1], s_tab);
	if (!s_tab)
	{
		free (s_tab);
		return (0);
	}
	win = set_win_data(s_tab);
	if (!win)
		return (0);
	mlx_loop_hook(win->mlx_ptr, &handle_no_event, &win);
	mlx_key_hook(win->win_ptr, &handle_input, &win);
	img.img = mlx_new_image(win->mlx_ptr, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	render_map(img, s_tab, win);
	//ft_free_double_int(s_tab->tab, s_tab->y_max);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img.img, 0, 0);
	mlx_loop(win->mlx_ptr);
}



/* int main(void)
{
    char    *str;
    char    **tab;
    int     i;
    int     j;

    str = "9 9 9 9 9 9 9 9 9 9 8  9 9 9  9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 10 9 9 9 9 9 9 9 9 9 10 10 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 8 7 10 9 9 9 9 9 9 8 10 9 9 9 9 9 9 8 10 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 ";
    tab = ft_split(str, ' ');

    i = 0;
    j = 0;
    while (tab[i])
    {
        printf("str=|%s|\n", tab[i]);
        i++;
    }

} */