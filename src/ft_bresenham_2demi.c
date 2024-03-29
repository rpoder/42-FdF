/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham_2demi.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:38:26 by rpoder            #+#    #+#             */
/*   Updated: 2022/04/25 22:05:47 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_bresenham_5o(t_vars *vars, t_point start, t_point end)
{
	int	dx;
	int	dy;
	int	pk;
	int	x;
	int	y;

	x = start.x;
	y = start.y;
	dx = end.x - start.x;
	dy = end.y - start.y;
	pk = 2 * dx;
	while (x > end.x)
	{
		my_mlx_pixel_put(vars, x, y, 0x00FFFFFF);
		pk = pk - 2 * dy;
		if (pk >= 0)
		{
			y--;
			pk = pk + 2 * dx;
		}
	x--;
	}
}

void	ft_bresenham_6o(t_vars *vars, t_point start, t_point end)
{
	int	dx;
	int	dy;
	int	pk;
	int	x;
	int	y;

	x = start.x;
	y = start.y;
	dx = end.x - start.x;
	dy = end.y - start.y;
	pk = 2 * dy;
	while (y > end.y)
	{
		my_mlx_pixel_put(vars, x, y, 0x00FFFFFF);
		pk = pk - 2 * dx;
		if (pk >= 0)
		{
			x--;
			pk = pk + 2 * dy;
		}
	y--;
	}
}

void	ft_bresenham_7o(t_vars *vars, t_point start, t_point end)
{
	int	dx;
	int	dy;
	int	pk;
	int	x;
	int	y;

	x = start.x;
	y = start.y;
	dx = end.x - start.x;
	dy = end.y - start.y;
	pk = 2 * dy;
	while (y > end.y)
	{
		my_mlx_pixel_put(vars, x, y, 0x00FFFFFF);
		pk = pk + 2 * dx;
		if (pk >= 0)
		{
			x++;
			pk = pk + 2 * dy;
		}
	y--;
	}
}

void	ft_bresenham_8o(t_vars *vars, t_point start, t_point end)
{
	int	dx;
	int	dy;
	int	pk;
	int	x;
	int	y;

	x = start.x;
	y = start.y;
	dx = end.x - start.x;
	dy = end.y - start.y;
	pk = -dx;
	while (x < end.x)
	{
		my_mlx_pixel_put(vars, x, y, 0x00FFFFFF);
		pk = pk - 2 * dy;
		if (pk >= 0)
		{
			y--;
			pk = pk - 2 * dx;
		}
	x++;
	}
}
