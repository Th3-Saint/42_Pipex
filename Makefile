# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrobaii <mrobaii@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 14:29:22 by mrobaii           #+#    #+#              #
#    Updated: 2022/12/23 14:37:33 by mrobaii          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Pipex

SRC  =	./srcs/Pipex.c \
		./srcs/Pipex_utils.c \
		./srcs/ft_split.c \
		./srcs/libft_functions.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	=	-Wall -Werror -Wextra

RM	= rm -rf

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean re