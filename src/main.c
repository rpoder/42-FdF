/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:13:55 by rpoder            #+#    #+#             */
/*   Updated: 2022/05/06 23:21:06 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render_map(t_int_tab *map, t_vars *vars)
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
				draw_v(infos, map, vars);
			if (infos->i + 1 < map->y_max)
				draw_h(infos, map, vars);
			infos->j++;
		}
		infos->i++;
	}
	free(infos);
}

void	draw_v(t_info_draw *info, t_int_tab *map, t_vars *vars)
{
	int		i;
	int		j;
	float	a;
	t_point	start;
	t_point	stop;

	i = info->i;
	j = info->j;
	a = info->a;
	start.y = (i * cos(a) * vars->zoom - j * cos(a)
			* vars->zoom) + vars->y_offset - map->tab[i][j] * vars->height;
	start.x = (i * sin(a) * vars->zoom + j * sin(a)
			* vars->zoom - 1 * vars->zoom) + vars->x_offset;
	stop.y = (i * cos(a) * vars->zoom - (j + 1) * cos(a)
			* vars->zoom) + vars->y_offset - map->tab[i][j + 1] * vars->height;
	stop.x = (i * sin(a) * vars->zoom + (j + 1) * sin(a)
			* vars->zoom - 1 * vars->zoom) + vars->x_offset;
	ft_drawline(vars, start, stop);

}

void	draw_h(t_info_draw *info, t_int_tab *map, t_vars *vars)
{
	int		i;
	int		j;
	float	a;
	t_point	start;
	t_point	stop;

	i = info->i;
	j = info->j;
	a = info->a;
	start.y = (i * cos(a) * vars->zoom - j * cos(a)
			* vars->zoom) + vars->y_offset - map->tab[i][j] * vars->height;
	start.x = (i * sin(a) * vars->zoom + j * sin(a)
			* vars->zoom - 1 * vars->zoom) + vars->x_offset;
	stop.y = ((i + 1) * cos(a) * vars->zoom - j * cos(a)
			* vars->zoom) + vars->y_offset - map->tab[i + 1][j] * vars->height;
	stop.x = ((i + 1) * sin(a) * vars->zoom + j * sin(a)
			* vars->zoom - 1 * vars->zoom) + vars->x_offset;
	ft_drawline(vars, start, stop);
}

int	main(int argc, char **argv)
{
	t_vars		*vars;
	t_int_tab	*s_tab;
	int			ret;

	if (argc != 2)
		return (0);
	s_tab = set_s_tab();
	if (!s_tab)
		return (0);
	ret = tab_parser(argv[1], s_tab);
	if (ret == 0)
	{
		free (s_tab);
		return (0);
	}
	ft_printf("x=%d", s_tab->x_max);
	vars = set_vars(s_tab);
	if (!vars)
		ft_free_double_int(s_tab->tab, s_tab->y_max);
	if (!vars)
		return (0);
	render_map(s_tab, vars);
	ft_free_double_int(s_tab->tab, s_tab->y_max);
	free(s_tab);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img_ptr, 0, 0);
	mlx_key_hook(vars->win_ptr, handle_input, vars);
	mlx_loop(vars->mlx_ptr);


	//--------------------------------------
	//get_line_count(argv[1]);
	//tab_parser(argv[1]);
}
