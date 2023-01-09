# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajimenez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/01 17:15:58 by ajimenez          #+#    #+#              #
#    Updated: 2023/01/08 15:47:02 by ajimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
LIB1	= ar -rcs
LIB2	= ranlib
RM		= /bin/rm -f

NAME	= libft.a

INCLUDE	= libft.h
SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		  	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c\
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c\
			ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c\
			ft_putendl_fd.c ft_strmapi.c ft_striteri.c ft_itoa.c ft_split.c\
			ft_putmatrix.c ft_free_matrix.c ft_isspace.c ft_iter_str_bool.c\
			get_next_line.c ft_strcpy.c ft_iter_matrix_bool.c ft_matrixlen.c\
			ft_matrix_data.c ft_max_int.c ft_min_int.c ft_countchars.c \
			ft_dlstadd_back.c ft_dlstadd_front.c ft_dlstclear.c \
			ft_dlstdelone.c ft_dlstlast.c ft_dlstnew.c ft_dlstsize.c \
			ft_dlstnew_struct.c ft_atob.c ft_boti.c



OBJS	= $(SRCS:.c=.o)

BONUS_S = 	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
			ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

BONUS_O = $(BONUS_S:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDE)
			$(LIB1) $(NAME) $(OBJS)
			$(LIB2) $(NAME)

bonus:		$(NAME) $(BONUS_O)
			$(LIB1) $(NAME) $(BONUS_O)
			$(LIB2) $(NAME)
			
.c.o:
			$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)
			
clean:
			$(RM) $(OBJS) $(BONUS_O)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

rebonus:	fclean bonus

.PHONY:		all clean fclean re bonus rebonus
