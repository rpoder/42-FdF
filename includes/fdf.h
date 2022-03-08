/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:43:24 by rpoder            #+#    #+#             */
/*   Updated: 2022/03/08 17:24:37 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include  <mlx.h>
//# include  <mlx_int.h>
//# include  <mlx_new_window.h>

# include "libft.h"
# include "get_next_line.h"

typedef struct s_data {
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
