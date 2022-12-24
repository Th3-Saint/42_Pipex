# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucifer <lucifer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 14:29:22 by mrobaii           #+#    #+#              #
#    Updated: 2022/12/24 18:56:38 by lucifer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Pipex

SRC  =	./srcs/Pipex.c \
		./srcs/Pipex_utils.c \
		./srcs/ft_split.c \
		./srcs/libft_functions.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c 
 

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	=	-Wall -Werror -Wextra -D BUFFER_SIZE=1

RM	= rm -rf

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean re