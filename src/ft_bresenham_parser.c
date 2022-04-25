/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:38:26 by rpoder            #+#    #+#             */
/*   Updated: 2022/04/25 21:12:12 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drawline(t_vars *vars, t_point start, t_point stop)
{
	int	dx;
	int	dy;

	dx = stop.x - start.x;
	dy = stop.y - start.y;
	if (dx >= 0 && dy >= 0)
		ft_bresenham_parser_1demi(vars, start, stop);
	else if (dx <= 0 && dy >= 0)
		ft_bresenham_parser_1demi(vars, start, stop);
	else if (dx <= 0 && dy <= 0)
		ft_bresenham_parser_2demi(vars, start, stop);
	else if (dx >= 0 && dy <= 0)
		ft_bresenham_parser_2demi(vars, start, stop);
}

void	ft_bresenham_parser_1demi(t_vars *vars, t_point start, t_point stop)
{
	int	dx;
	int	dy;

	dx = stop.x - start.x;
	dy = stop.y - start.y;
	if (dx >= 0 && dy >= 0)
	{
		if (dx >= dy)
			ft_bresenham_1o(vars, start, stop);
		else
			ft_bresenham_2o(vars, start, stop);
	}
	else if (dx <= 0 && dy >= 0)
	{
		if (dx < -dy)
			ft_bresenham_3o(vars, start, stop);
		else
			ft_bresenham_4o(vars, start, stop);
	}
}

void	ft_bresenham_parser_2demi(t_vars *vars, t_point start, t_point stop)
{
	int	dx;
	int	dy;

	dx = stop.x - start.x;
	dy = stop.y - start.y;
	if (dx <= 0 && dy <= 0)
	{
		if (dx <= dy)
			ft_bresenham_5o(vars, start, stop);
		else
			ft_bresenham_6o(vars, start, stop);
	}
	else if (dx >= 0 && dy <= 0)
	{
		if (dx < -dy)
			ft_bresenham_7o(vars, start, stop);
		else
			ft_bresenham_8o(vars, start, stop);
	}
}
