/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:54:40 by rpoder            #+#    #+#             */
/*   Updated: 2022/04/25 20:57:19 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vars	*set_vars(t_int_tab *s_tab)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (NULL);
	vars->mlx_ptr = mlx_init();
	if (vars->mlx_ptr == NULL)
	{
		free(vars);
		return (NULL);
	}
	vars->win_ptr = mlx_new_window(vars->mlx_ptr,
			1920, 1080, "Fer de fil");
	if (vars->win_ptr == NULL)
	{
		free(vars->mlx_ptr);
		free(vars);
		return (NULL);
	}
	vars->img_ptr = mlx_new_image(vars->mlx_ptr, 1920, 1080);
	vars->addr = mlx_get_data_addr(vars->img_ptr, &vars->bits_per_pixel, &vars->line_length, &vars->endian);
	vars->zoom = (WIN_WIDTH / s_tab->x_max) / 3;
	vars->height = 1;
	vars->x_offset = ((WIN_WIDTH - (s_tab->x_max * vars->zoom)) / 2)
		- (s_tab->x_max * vars->zoom) / 3;
	vars->y_offset = WIN_HEIGHT / 2;
	return (vars);
}

t_int_tab	*set_s_tab(void)
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
