# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 17:38:32 by rpoder            #+#    #+#              #
#    Updated: 2022/05/06 23:56:25 by rpoder           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = exec
CC = cc
#CFLAGS = -Werror -Wall -Wextra
LIBFT = libft.a
LIBFT_DIR = ./libftprintf
MLX_DIR = ./mlx_linux
MLX = -L/usr/lib -Imlx_Linux -lXext -lX11 -lm -lz
INC = -I$(MLX_DIR) -I ./includes -I $(LIBFT_DIR)/includes -O3 -I/usr/include
SRCSPATH = ./src/
MAP = 10-2
SRCS = $(addprefix $(SRCSPATH), \
	main.c \
	mlx_tools.c \
	map_parser.c \
	setters.c \
	libft_addons.c \
	get_next_line.c \
	get_next_line_utils.c \
	ft_bresenham_1demi.c \
	ft_bresenham_2demi.c \
	ft_bresenham_parser.c \
	)

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $< $(INC) $(CFLAGS) -c -o $@

all: $(NAME)

test: $(NAME)
	$(NAME) && ./$(NAME) test_maps/$(MAP).fdf

leaks: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) test_maps/$(MAP).fdf

%.a:
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS) $(addprefix $(LIBFTDIR),$(LIBFT))
	$(CC) $(OBJS) $(CFLAGS) -lft -L$(LIBFT_DIR) -lmlx -L$(MLX_DIR) $(MLX) $(INC) -o $(NAME)

push:
	make fclean
	git add *
	git status
	git commit -m "$m"
	git push origin master

norminette:
	norminette ./libftprintf ./src ./includes

clean:
	rm -rf $(SRCSPATH)*.o
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
