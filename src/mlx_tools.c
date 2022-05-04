/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:37:50 by rpoder            #+#    #+#             */
/*   Updated: 2022/05/04 17:00:30 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	if (x <= 0 || x >= WIN_WIDTH || y <= 0 || y >= WIN_HEIGHT)
		return ;
	dst = vars->addr + (y * vars->line_len + x * (vars->bpp / 8));
	*(unsigned int *)dst = color;
}

int	handle_input(int keysym, t_vars *vars)
{
	if (keysym == ESC)
	{
		mlx_destroy_image(vars->mlx_ptr, vars->img_ptr);
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		mlx_destroy_display(vars->mlx_ptr);
		free(vars->mlx_ptr);
		free(vars);
		exit(0);
	}
	return (0);
}
