/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:13:55 by rpoder            #+#    #+#             */
/*   Updated: 2022/03/06 18:51:22 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

char	**ft_handle_free(char **tab, int i)
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

int	*get_int_tab(char *str)
{
	int		*tab;
	char	**tmp;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	tmp = ft_split(str, ' ');
	if (!tmp)
		return (0);
	tab = malloc(ft_strlen_split(tmp) * sizeof(int));
	if (!tab)
		return (0);	
	while (tmp[i])
	{
		if (tmp[i][0] != '\n')
			tab[i] = ft_atoi(tmp[i]);
		i++;
	}
	ft_handle_free(tmp, ft_strlen_split(tmp) + 1);
	return (tab);
}

int	**ft_get_map(int fd, int size)
{
	char	*line;
	int		**map;
	int		*tmp;

	line = get_next_line(fd);
	if (!line)
	{
		map = malloc(size * sizeof(int *));
		printf("je malloc batard\n");
		//printf("add map = %p\n", map);
		printf("size malloc = %d\n", size);
		if (!map)
			exit(1);
	}
	else
	{
		printf("add map = %p\n", map);
		//printf("size = %d\n", size);
		//tmp[size] = map;
		map = ft_get_map(fd, size + 1);
	}
	
	//printf("add map = %p\n", map);
	map[size] = get_int_tab((char *)line);
	free(line);
	return (map);
}

int	main(int argc, char **argv)
{
	// void	*mlx;
	// void	*mlx_win;
	// t_data	img;
	//int	n;
	int 	**map;
	int		fd;
	char *ret;

	fd = open("map.fdf", O_RDONLY);
//	get_next_line(fd);
//	ret = get_next_line(fd);
	//free(ret);
	// free(ret);
	// ret = get_next_line(fd);
	// free(ret);
	//ret = get_next_line(fd);

	map = ft_get_map(fd, 0);
	ft_print_doubleinttab(map, 10, 10);
	free(map);
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