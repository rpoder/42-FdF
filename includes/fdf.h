/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:43:24 by rpoder            #+#    #+#             */
/*   Updated: 2022/05/10 15:35:43 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include  <mlx.h>
# include  <mlx_int.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define ESC 65307

typedef struct vars
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		height;
	int		zoom;
	int		x_offset;
	int		y_offset;
}	t_vars;

typedef struct int_tab
{
	int	x_max;
	int	y_max;
	int	**tab;
}	t_int_tab;

typedef struct info_draw {
	int		i;
	int		j;
	float	a;
}	t_info_draw;

typedef struct point {
	int	x;
	int	y;
}	t_point;

typedef struct last_seen {
	int	last;
	int	i;
}	t_last_seen;

void		my_mlx_pixel_put(t_vars *data, int x, int y, int color);
int			handle_no_event(void *data);
int			handle_input(int keysym, t_vars *vars);

t_vars		*set_vars(t_int_tab *s_tab);
t_int_tab	*set_s_tab(void);

int			**ft_free_double_int(int **tab, int i);
char		**ft_free_double_char(char **tab, int i);
int			ft_strlen_split(char **tab);
char		**trim_split(char **tab);
void		ft_print_double_tab(t_int_tab *s_tab);

int			tab_parser(char *to_open, t_int_tab *s_tab);
int			*get_line(int fd, t_int_tab *s_tab, int k);
int			get_line_count(int fd);
int			line_loop(int fd, char *buf, int count, t_last_seen *last_seen);

void		draw_v(t_info_draw *info, t_int_tab *map, t_vars *vars);
void		draw_h(t_info_draw *info, t_int_tab *map, t_vars *vars);

void		ft_drawline(t_vars *vars, t_point start, t_point end);

void		ft_bresenham_parser_1demi(t_vars *vars,
				t_point start, t_point stop);
void		ft_bresenham_parser_2demi(t_vars *vars,
				t_point start, t_point stop);

void		ft_bresenham_1o(t_vars *vars, t_point start, t_point end);
void		ft_bresenham_2o(t_vars *vars, t_point start, t_point end);
void		ft_bresenham_3o(t_vars *vars, t_point start, t_point end);
void		ft_bresenham_4o(t_vars *vars, t_point start, t_point end);
void		ft_bresenham_5o(t_vars *vars, t_point start, t_point end);
void		ft_bresenham_6o(t_vars *vars, t_point start, t_point end);
void		ft_bresenham_7o(t_vars *vars, t_point start, t_point end);
void		ft_bresenham_8o(t_vars *vars, t_point start, t_point end);

#endif
