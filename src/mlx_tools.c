/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:37:50 by rpoder            #+#    #+#             */
/*   Updated: 2022/04/25 17:29:44 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x <= 0 || x >= WIN_WIDTH || y <= 0 || y >= WIN_HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	handle_no_event(void *data)
{
	(void) data;
	return (0);
}

int	handle_input(int keysym, t_win_data *win_data)
{
	if (keysym == ESC)
	{
		mlx_destroy_window(win_data->mlx_ptr, win_data->win_ptr);
		mlx_destroy_image(win_data->mlx_ptr, win_data->img_ptr);
	//	free(win_data->mlx_ptr);
		//free(win_data->win_ptr);
		exit(0);
	}

}
