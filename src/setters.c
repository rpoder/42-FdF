/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:54:40 by rpoder            #+#    #+#             */
/*   Updated: 2022/05/11 17:24:33 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vars	*set_vars(t_int_tab *s_tab)
{
	t_vars	*v;

	v = malloc(sizeof(t_vars));
	if (!v)
		return (NULL);
	v->mlx_ptr = mlx_init();
	if (v->mlx_ptr == NULL)
		free(v);
	if (v->mlx_ptr == NULL)
		return (NULL);
	v->win_ptr = mlx_new_window(v->mlx_ptr, 1920, 1080, "Fer de fil");
	if (v->win_ptr == NULL)
		return ((free(v->mlx_ptr), free(v)), NULL);
	v->img_ptr = mlx_new_image(v->mlx_ptr, 1920, 1080);
	v->addr = mlx_get_data_addr(v->img_ptr, &v->bpp, &v->line_len, &v->endian);
	v->zoom = (WIN_WIDTH / s_tab->x_max) / 3;
	v->height = 1;
	if (s_tab->x_max != 0)
		v->x_offset = ((WIN_WIDTH - (s_tab->x_max * v->zoom)) / 2)
			- (s_tab->x_max * v->zoom) / 3;
	v->y_offset = WIN_HEIGHT / 2;
	return (v);
}

t_int_tab	*set_s_tab(void)
{
	t_int_tab	*s_tab;

	s_tab = malloc(sizeof(t_int_tab));
	if (!s_tab)
		return (NULL);
	s_tab->tab = NULL;
	s_tab->x_max = 0;
	s_tab->y_max = 0;
	return (s_tab);
}
