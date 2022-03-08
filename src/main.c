/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:13:55 by rpoder            #+#    #+#             */
/*   Updated: 2022/03/08 21:16:00 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

char	**ft_free_double_char(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (NULL);
}

int	ft_strlen_split(char **tab)
{
	int	count;

	count = 0;
	if (tab)
	{
		while (tab[count])
		{
			count++;
		}
		count--;
	}
	return (count);
}

int	get_line_count(fd)
{
	int		count;
	int		ret;
	char 	*buf;

	count = 0;
	ret = 1;
	buf = malloc(sizeof(char));
	while (ret != 0)
	{
		ret = read(fd, buf, 1);
		if (buf[0] == '\n')
			count++;
	}
	free(buf);
	return (count - 1);
}

char	***get_map(int fd, int map_height)
{
	char	***map;
	char	*ret;
	int		i;

	i = 0;
	map = malloc((map_height + 1) * sizeof(char **));
	map[map_height] = NULL;
	while (i < map_height)
	{
		map[i] = ft_split(get_next_line(fd), ' ');
		i++;
	}
	return (map);
}

int	main(int argc, char **argv)
{
	// void	*mlx;
	// void	*mlx_win;
	// t_data	img;
	//int	n;
	char	***map;
	int		fd;
	char *ret;
	fd = open("map.fdf", O_RDONLY);
	printf("nombre de lignes = %d", get_line_count(fd));
	close(fd);
	fd = open("map.fdf", O_RDONLY);
	map = get_map(fd, 10);
	ft_print_double_char_tab(map);
	printf("result %s", map[0][4]);
	//get_next_line(fd);
	//ret = get_next_line(fd);
	//free(ret);
	// free(ret);
	// ret = get_next_line(fd);
	// free(ret);
	//ret = get_next_line(fd);

	//printf("\n");
	//printf("%d", map[0][0]);

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// n = 0;
	// while (n < 600)
	// {
	// 	my_mlx_pixel_put(&img, n, n, 0x00FF0000);
	// 	n++;
	// }
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// mlx_loop(mlx);
}
