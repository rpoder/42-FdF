/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:38:26 by rpoder            #+#    #+#             */
/*   Updated: 2022/04/05 16:24:26 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drawline(t_data img, t_point *start, t_point *end)
{
	int	dx;
	int	dy;

	dx = end->x - start->x;
	dy = end->y - start->y;
	if (dx >= 0 && dy >= 0)
		ft_bresenham_parser_1demi(img, start, end);
	else if (dx <= 0 && dy >= 0)
        ft_bresenham_parser_1demi(img, start, end);
	else if (dx <= 0 && dy <= 0)
        ft_bresenham_parser_2demi(img, start, end);
	else if(dx >= 0 && dy <= 0)
        ft_bresenham_parser_2demi(img, start, end);
}

void ft_bresenham_parser_1demi(t_data img, t_point *start, t_point *end)
{
    int	dx;
	int	dy;

	dx = end->x - start->x;
	dy = end->y - start->y;
	if (dx >= 0 && dy >= 0)
	{
		if (dx >= dy)
			ft_bresenham_1o(img, start, end);
		else
			ft_bresenham_2o(img, start, end);
	}
	else if (dx <= 0 && dy >= 0)
	{
		if (dx < -dy)
			ft_bresenham_3o(img, start, end);
		else
			ft_bresenham_4o(img, start, end);
	}
}

void ft_bresenham_parser_2demi(t_data img, t_point *start, t_point *end)
{
    int	dx;
	int	dy;

	dx = end->x - start->x;
	dy = end->y - start->y;
    if (dx <= 0 && dy <= 0)
	{
		if (dx <= dy)
			ft_bresenham_5o(img, start, end);
		else
			ft_bresenham_6o(img, start, end);
	}
	else if(dx >= 0 && dy <= 0)
	{
		if (dx < -dy)
			ft_bresenham_7o(img, start, end);
		else
			ft_bresenham_8o(img, start, end);
	}
    
}