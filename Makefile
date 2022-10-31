# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: goliano- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 16:52:02 by goliano-          #+#    #+#              #
#    Updated: 2022/10/31 16:55:32 by goliano-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d

LIB_MLX		= libmlx.dylib

SRCS =	./cub3d.c ./utils/strings.c

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
		make -C Libft

mlx_t:
		make -C mlx

$(NAME):		Libft/libft.a $(OBJS)
				$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(CFLAGS)	-o $(NAME)

clean:
		$(RM) $(OBJS)
		make clean -C Libft
		make clean -C mlx

fclean:		clean
			$(RM) $(NAME)
			make fclean -C Libft

re:			fclean all

.PHONY:		all clean fclean re
