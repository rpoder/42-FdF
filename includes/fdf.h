/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:43:24 by rpoder            #+#    #+#             */
/*   Updated: 2022/03/09 16:55:25 by rpoder           ###   ########.fr       */
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
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct int_tab {
	int	x_max;
	int	y_max;
	int	**tab;
}	t_int_tab;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	ft_print_inttab(int *tab, int size);
void	ft_print_doubleinttab(int **tab, int h_size, int w_size);
void	ft_print_char_tab(char **tab);
void	ft_print_double_char_tab(char ***tab);
char	**ft_free_double_char(char **tab, int i);

#endif
