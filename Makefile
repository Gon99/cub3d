# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: goliano- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 16:52:02 by goliano-          #+#    #+#              #
#    Updated: 2022/12/28 16:26:33 by goliano-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d

LIB_MLX		= libmlx.dylib

SRCS =	./cub3d.c ./libft/ft_calloc.c ./libft/ft_strlen.c \
		./libft/ft_strtrim.c ./libft/ft_memset.c ./libft/ft_strcmp.c \
		./libft/get_next_line.c ./libft/get_next_line_utils.c ./libft/ft_strncmp.c \
		./libft/ft_isspace.c ./utils/map.c ./utils/index.c ./utils/chequer.c \
		./utils/open.c ./srcs/flood_fill.c ./utils/length.c ./utils/chequer2.c \
		./utils/strings.c ./srcs/start.c ./libft/ft_print_matrix.c ./hooks/hooks.c \
		./srcs/moves.c

OBJS		= $(SRCS:.c=.o)

FLAGS		= -Wall -Werror -Wextra

RM			= rm -rf

INC			= -I includes/ -Imlx

%.o: %.c
	cc $(FLAGS) $(INC) -o $@ -c $?

all:	$(NAME)

mlx:	$(LIB_MLX)

$(LIB_MLX):		$(MLX_OBJS)
			ar -r $(LIB_MLX) $(MLX_OBJS)
			ranlib $(LIB_MLX)

libft/libft.a:
		make -C libft

mlx_t:
		make -C mlx

$(NAME):		libft/libft.a $(OBJS)
				$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(CFLAGS)	-o $(NAME)

clean:
		$(RM) $(OBJS)
		make clean -C libft
		make clean -C mlx

fclean:		clean
			$(RM) $(NAME)
			make fclean -C libft

re:			fclean all

.PHONY:		all clean fclean re
