# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 15:43:39 by ajimenez          #+#    #+#              #
#    Updated: 2023/07/22 13:20:10 by ajimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		     = gcc
CFLAGS	     = -Wall -Wextra -Werror -g
SAN		     = -fsanitize=address
LIB 	     = ar -rcs
RM		     = /bin/rm -rf

OS  		 = $(shell uname -s)

NAME	     = cub3d

LIBFT	     = ./includes/libft/libft.a
LIBP	     = cub3D.a 

ifeq ($(OS), Darwin)
	MLXFLGS  = -lz -framework OpenGL -framework AppKit -lm
	MLXDIR   = ./includes/mlx_mac
	LIBMLX   = ./includes/mlx_mac/libmlx.a
endif
ifeq ($(OS), Linux)
	MLXFLGS  = -lXext -lX11 -lm -lz
	MLXDIR   = ./includes/mlx_linux
	LIBMLX   = ./includes/mlx_linux/libmlx.a
endif

MATH_PATH	 = srcs/math/
GAME_PATH	 = srcs/game/
DRAW_PATH	 = srcs/draw/
INIT_PATH	 = srcs/init/
PARSER_PATH  = srcs/parser/
ANGLE_PATH	 = srcs/angle/
FREE_PATH	 = srcs/free/

GAME_FL		 = game.c key_hook.c moves.c parse_color.c \
			   start.c player_dir.c steps.c do_dda.c
DRAW_FL		 = draw.c draw_wall.c
INIT_FL		 = init_gdata.c init_pdata.c init_rdata.c init_mlx.c init_textures.c
PARSER_FL	 = utils_file.c iter_spaces_idx.c is_line.c flood_fill.c fill_map.c check.c \
			   parse_color.c
ANGLE_FL	 = angle.c
MATH_FL		 = math.c
FREE_FL		 = free.c

SRCS         = 	srcs/main.c \
				$(addprefix $(GAME_PATH), $(GAME_FL)) \
				$(addprefix $(INIT_PATH), $(INIT_FL)) \
				$(addprefix $(PARSER_PATH), $(PARSER_FL)) \
				$(addprefix $(DRAW_PATH), $(DRAW_FL)) \
				$(addprefix $(ANGLE_PATH), $(ANGLE_FL)) \
				$(addprefix $(MATH_PATH), $(MATH_FL)) \
				$(addprefix $(FREE_PATH), $(FREE_FL))

OBJS	= $(SRCS:.c=.o)
COMP	= $(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(LIBMLX) $(MLXFLGS) -o $(NAME)
SANCOMP	= $(CC) $(CFLAGS) $(SAN) $(LIBFT) $(LIBP) $(SRCS) $(LIBMLX) $(MLXFLGS) -g3 -o $(NAME)

all: 		$(NAME)

$(NAME):			$(OBJS)
					@echo "\n\033[33mMaking libft! ░░░░░░ /(._.)\ ░░░░░\033[39m\n"
					@make -sC ./includes/libft
					@make -sC $(MLXDIR)
					@cp ./includes/libft/libft.a ./
					@echo $(MLXDIR)
					@cp $(LIBMLX) ./
					$(LIB) $(LIBP) $(OBJS)
					$(COMP) 
					@echo "\n\033[1;32mEverything done! ░░░░░░ ＼(>o<)ノ ░░░░░\033[39m\n"

fsanitize:			$(OBJS)
					@echo "\n\033[33mMaking libft! ░░░░░░ /(ಠ_ಠ)\ ░░░░░\033[39m\n"
					@make -sC ./includes/libft
					@cp ./includes/libft/libft.a ./
					@make -sC $(MLXDIR)
					@cp $(LIBMLX) ./
					$(LIB) $(LIBP) $(OBJS)
					$(SANCOMP)
					@echo "\n\033[1;32mEverything done! ░░░░░░ ＼(>o<)ノ ░░░░░\033[39m\n"

clean:
					@make clean -sC ./includes/libft
					$(RM) $(OBJS) $(OBJS_B)
					@rm -rf libft.a libmlx.a cub3d.dSYM cub3d.a
					@rm $(LIBMLX)

fclean: 	clean
					@make fclean -sC ./includes/libft
					$(RM) $(NAME)
					$(RM) $(PROG)
					$(RM) $(LIBP)
					@echo "\n\033[31mEverything fcleaned! ░░░░░░ ٩(╬ʘ益ʘ╬)۶ ░░░░░\n\033[39m"

re:			fclean all

.PHONY: all clean fclean re
