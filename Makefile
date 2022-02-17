# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 17:38:32 by rpoder            #+#    #+#              #
#    Updated: 2022/02/17 15:55:50 by rpoder           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = exec
CC = gcc
CFLAGS = -Werror -Wall -Wextra
MLXFLAGS = -L./mlx_linux -lmlx_Linux -lXext -lX11 -lm -lz
INC = -I ./mlx_linux -I ./includes
SRCSPATH = ./src/

SRCS = $(addprefix $(SRCSPATH), \
	main.c \
	)

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $< $(INC) -c -o $@

all: $(NAME)

test: $(NAME)
	$(NAME) && ./$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLXFLAGS) $(INC) -o $(NAME)

push:
	git add *
	git status
	git commit -m "$m"
	git push origin master

clean:
	rm -rf $(SRCSPATH)*.o

fclean: clean
	rm -rf $(NAME)