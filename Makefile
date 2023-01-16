# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: goliano- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 16:52:02 by goliano-          #+#    #+#              #
#    Updated: 2023/01/16 14:36:25 by ajimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		     = gcc
CFLAGS	     = -Wall -Wextra -Werror -g
MLXFLGS      = -framework OpenGL -framework AppKit
SAN		     = -fsanitize=address
LIB 	     = ar -rcs
RM		     = /bin/rm -rf

LIBFT	     = ./includes/libft/libft.a
LIBMLX	     = ./includes/mlx/libmlx.a
LIBP	     = cub3D.a 

NAME	     = cub3d

GAME_PATH	 = srcs/game
INIT_PATH	 = srcs/init
PARSER_PATH  = srcs/parser

GAME_FL		 = key_hook.c game.c 
INIT_FL		 = init_gdata.c init_pdata.c
PARSER_FL	 = utils_file.c iter_spaces_idx.c is_line.c flood_fill.c fill_map.c check.c

SRCS         = 	srcs/main.c \
				$(addprefix $(GAME_PATH), $(GAME_FL)) \
				$(addprefix $(INIT_PATH), $(INIT_FL)) \
				$(addprefix $(PARSER_PATH), $(PARSER_FL))

OBJS	= $(SRCS:.c=.o)
COMP	= $(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(LIBMLX) $(MLXFLGS) -o $(NAME)
SANCOMP	= $(CC) $(CFLAGS) $(SAN) $(LIBFT) $(LIBP) $(SRCS) $(LIBMLX) $(MLXFLGS) -g3 -o $(NAME)

all: 		$(NAME)

$(NAME):			$(OBJS)
					@echo "\n\033[33mMaking libft! ░░░░░░ /(._.)\ ░░░░░\033[39m\n"
					@make -sC ./includes/libft
					@make -sC ./includes/mlx
					@cp ./includes/mlx/libmlx.a ./
					@cp ./includes/libft/libft.a ./
					$(LIB) $(LIBP) $(OBJS)
					$(COMP) 
					@echo "\n\033[1;32mEverything done! ░░░░░░ ＼(>o<)ノ ░░░░░\033[39m\n"

fsanitize:			$(OBJS)
					@echo "\n\033[33mMaking libft! ░░░░░░ /(ಠ_ಠ)\ ░░░░░\033[39m\n"
					@make -sC ./includes/libft
					@make -C ./includes/mlx
					@cp ./includes/mlx/libmlx.a ./
					@cp ./includes/libft/libft.a ./
					$(LIB) $(LIBP) $(OBJS)
					$(SANCOMP)
					@echo "\n\033[1;32mEverything done! ░░░░░░ ＼(>o<)ノ ░░░░░\033[39m\n"

clean:
					@make clean -sC ./includes/libft
					$(RM) $(OBJS) $(OBJS_B)
					@rm libft.a libmlx.a

fclean: 	clean
					@make fclean -sC ./includes/libft
					$(RM) $(NAME)
					$(RM) $(PROG)
					$(RM) $(LIBP)
					@echo "\n\033[31mEverything fcleaned! ░░░░░░ ٩(╬ʘ益ʘ╬)۶ ░░░░░\n\033[39m"

re:			fclean all

.PHONY: all clean fclean re
 
