# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 17:38:32 by rpoder            #+#    #+#              #
#    Updated: 2022/03/05 19:31:35 by rpoder           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = exec
CC = cc
#CFLAGS = -Werror -Wall -Wextra
LIBFT = libft.a
LIBFT_DIR = ./libftprintf
MLX = -lmlx_Linux -lXext -lX11 -lm -lz
MLX_DIR = ./mlx_linux/
INC = -I ./mlx_linux -I ./includes -I ./libftprintf/includes
SRCSPATH = ./src/

SRCS = $(addprefix $(SRCSPATH), \
	main.c \
	get_next_line.c \
	get_next_line_utils.c \
	print_functions.c \
	)

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $< $(INC) $(CFLAGS) -c -o $@

all: $(NAME)

test: $(NAME)
	$(NAME) && ./$(NAME)

leaks: $(NAME)
	$(NAME) && ./$(NAME) && valgrind ./$(NAME) --leak-check=full --show-leak-kinds=all

%.a:
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(addprefix $(LIBFTDIR),$(LIBFT))
	$(CC) $(OBJS) $(CFLAGS) -lft -L$(LIBFT_DIR) $(MLX) -L$(MLX_DIR) $(INC) -o $(NAME)

push:
	git add *
	git status
	git commit -m "$m"
	git push origin master

clean:
	rm -rf $(SRCSPATH)*.o
#make clean $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
#make fclean $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re