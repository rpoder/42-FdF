# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 17:38:32 by rpoder            #+#    #+#              #
#    Updated: 2022/05/11 17:26:43 by rpoder           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROGNAME			:=	fdf

LIBFT				:=	./libftprintf/libft.a
MLX					:=	./mlx_linux/libmlx_Linux.a

INCLUDEDIR			:=	./includes
SRCDIR				:=	./src

MLXFLAGS			:=	-L/usr/lib -lXext -lX11 -lm -lz

OBJDIR				:=	./obj

SRCS				:=	main.c \
						mlx_tools.c \
						map_parser.c \
						setters.c \
						libft_addons.c \
						get_next_line.c \
						get_next_line_utils.c \
						ft_bresenham_1demi.c \
						ft_bresenham_2demi.c \
						ft_bresenham_parser.c \

CC					:=	cc
RM					:=	rm

CCFLAGS				:=	-Wall -Wextra -Werror

NAME				:=	$(PROGNAME)

OUTDIR				:=	$(OBJDIR)

$(OUTDIR)/%.o		:	$(SRCDIR)/%.c | $(OUTDIR)
	@mkdir -p $(dir $@)
	$(CC) -c $(CCFLAGS) -I $(INCLUDEDIR) $(addprefix -I ,$(dir $(MLX))) $(addprefix -I ,$(dir $(LIBFT))) $< -o $@

$(NAME)				:	$(addprefix $(OUTDIR)/,$(SRCS:.c=.o)) $(LIBFT)
	$(CC) $(CCFLAGS) $(addprefix $(OUTDIR)/,$(SRCS:.c=.o)) $(MLXFLAGS) $(LIBFT) $(MLX) -o $(NAME)

all					:	$(NAME)

bonus				:	$(NAME)

ifdef LIBFT
$(LIBFT)			:
	$(MAKE) -C $(dir $(LIBFT)) $(notdir $(LIBFT))
endif

$(OUTDIR)			:
	mkdir $(OUTDIR)

clean				:
ifdef LIBFT
	$(MAKE) -C $(dir $(LIBFT)) fclean
endif
	$(RM) -rf $(OBJDIR) $(DEBUGDIR)

fclean				:	clean
	$(RM) -f $(PROGNAME) $(DEBUGNAME)

re					:	fclean $(NAME)

norm				:
	norminette ./libftprintf ./src ./includes

push				:
	$(MAKE) fclean
	git add *
	git status
	git commit -m "$m"
	git push github master

MAP 				:= test_maps/julia.fdf
test				: $(NAME)
	./$(NAME) $(MAP)

.PHONY				:	all clean fclean re norminette