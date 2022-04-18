/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:54:40 by rpoder            #+#    #+#             */
/*   Updated: 2022/04/18 14:55:23 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_win_data *set_win_data(t_int_tab *s_tab)
{
	t_win_data	*win_data;
	
	win_data = malloc(sizeof(t_win_data));
	win_data->mlx_ptr = mlx_init();
	if (win_data->mlx_ptr == NULL)
		return (0);
	win_data->win_ptr = mlx_new_window(win_data->mlx_ptr, 1920, 1080, "Hello world!");
	if (win_data->win_ptr == NULL)
	{
		free(win_data->win_ptr);
		return (0);
	}
	win_data->zoom = (WIN_WIDTH / s_tab->x_max) / 3;
	win_data->height = 1;
	win_data->x_offset = ((WIN_WIDTH - (s_tab->x_max * win_data->zoom)) / 2) - (s_tab->x_max * win_data->zoom) / 3;
	win_data->y_offset = WIN_HEIGHT / 2;
	return (win_data);
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