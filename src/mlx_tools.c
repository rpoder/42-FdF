/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:37:50 by rpoder            #+#    #+#             */
/*   Updated: 2022/04/25 21:53:26 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	if (x <= 0 || x >= WIN_WIDTH || y <= 0 || y >= WIN_HEIGHT)
		return ;
	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	handle_no_event(void *data)
{
	(void) data;
	return (0);
}

int	handle_input(int keysym, t_vars *vars)
{
	if (keysym == ESC)
	{

		mlx_destroy_image(vars->mlx_ptr, vars->img_ptr);
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		//free(vars->win_ptr);
		free(vars);
		exit(0);
	}
	return (0);
}
