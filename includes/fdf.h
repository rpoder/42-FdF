/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:43:24 by rpoder            #+#    #+#             */
/*   Updated: 2022/04/18 15:21:08 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include  <mlx.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

# define MOVE_UP 119
# define MOVE_DOWN 115
# define MOVE_LEFT 97
# define MOVE_RIGHT 100
# define ESC 65307
# define SPC 32
# define PLUS 65451
# define MINUS 65453

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct win_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		zoom;
	int		x_offset;
	int		y_offset;
}	t_win_data;

typedef struct screen_data
{
	int	height;
	int	zoom;
	int	x_offset;
	int	y_offset;
}	t_screen_data;


typedef struct int_tab
{
	int	x_max;
	int	y_max;
	int	**tab;
}	t_int_tab;

typedef struct point {
	int	x;
	int	y;
}	t_point;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		handle_no_event(void *data);
int		handle_input(int keysym, t_win_data *win_data);

t_win_data	*set_win_data(t_int_tab *s_tab);
t_int_tab	*set_s_tab(void);

int    **ft_free_double_int(int **tab, int i);
char	**ft_free_double_char(char **tab, int i);
int 	ft_strlen_split(char **tab);

t_int_tab	*get_int_map(char *to_open, t_int_tab *s_tab);

// Bresenham
void	ft_drawline(t_data img, t_point *start, t_point *end);

void ft_bresenham_parser_1demi(t_data img, t_point *start, t_point *end);
void ft_bresenham_parser_2demi(t_data img, t_point *start, t_point *end);

void	ft_bresenham_1o(t_data img, t_point *start, t_point *end);
void	ft_bresenham_2o(t_data img, t_point *start, t_point *end);
void	ft_bresenham_3o(t_data img, t_point *start, t_point *end);
void	ft_bresenham_4o(t_data img, t_point *start, t_point *end);
void	ft_bresenham_5o(t_data img, t_point *start, t_point *end);
void	ft_bresenham_6o(t_data img, t_point *start, t_point *end);
void	ft_bresenham_7o(t_data img, t_point *start, t_point *end);
void	ft_bresenham_8o(t_data img, t_point *start, t_point *end);

#endif
