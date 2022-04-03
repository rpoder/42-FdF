/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:38:26 by rpoder            #+#    #+#             */
/*   Updated: 2022/04/03 19:23:33 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_bresenham_x(t_data img, t_point *start, t_point *end)
{
	int	dx;
	int	dy;
	int	pk;
	int	x;
	int	y;

	x = start->x;
	y = start->y;
	dx = end->x - start->x;
	dy = end->y - start->y;
	printf("Start (%d, %d) || ", start->x, start->y);
	printf("Stop (%d, %d)\n", end->x, end->y);
	pk = 2 * dy - dx;
	while(x <= end->x)
	{
		printf("x = %d, y = %d\n", x, y);

		if(pk >= 0)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			y = y + 1;
			pk = pk + 2 * dy - 2 * dx;
		}
		else
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			pk = pk + 2 * dy;
		}
	x = x + 1;
	}
}

void	ft_bresenham_y(t_data img, t_point *start, t_point *end)
{
	int	dx;
	int	dy;
	int	pk;
	int	x;
	int	y;

	x = start->x;
	y = start->y;
	dx = end->x - start->x;
	dy = end->y - start->y;
	printf("Start (%d, %d) || ", start->x, start->y);
	printf("Stop (%d, %d)\n", end->x, end->y);
	pk = 2 * dy - dx;
	while(y <= end->y)
	{
		printf("x = %d, y = %d\n", x, y);
		printf("pk = %d\n", pk);
		if(pk >= 0)
		{
			printf("if\n");
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			y = y + 1;
			pk = pk + 2 * dy - 2 * dx;
		}
		else
		{
			printf("else\n");
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			pk = pk + 2 * dy;
		}
	x = x + 1;
	}
}

void	ft_drawline(t_data img, t_point *start, t_point *end)
{
	int	dx;
	int	dy;

	dx = end->x - start->x;
	dy = end->y - start->y;
	printf("dx = %d || dy = %d", dx, dy);
	if (dx >= dy)
		ft_bresenham_x(img, start, end);
	if (dx < dy)
		ft_bresenham_y(img, start, end);
}
