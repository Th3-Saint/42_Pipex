# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucifer <lucifer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 14:29:22 by mrobaii           #+#    #+#              #
#    Updated: 2022/12/24 22:00:23 by lucifer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


define HEADER

                                             
,------. ,--.                    ,--.   ,--. 
|  .--. '`--' ,---.  ,---.        \  `.'  /  
|  '--' |,--.| .-. || .-. :        .'    \   
|  | --' |  || '-' '\   --.,----. /  .'.  \  
`--'     `--'|  |-'  `----''----''--'   '--' 
             `--'                            
  

endef

define COMPILING


   ___ ___  __  __ ___ ___ _    ___ _  _  ___       
  / __/ _ \|  \/  | _ \_ _| |  |_ _| \| |/ __|      
 | (_| (_) | |\/| |  _/| || |__ | || .` | (_ |_ _ _ 
  \___\___/|_|  |_|_| |___|____|___|_|\_|\___(_|_|_)
                                                              
endef

export HEADER
export COMPILING

NAME = Pipex_bonus

SRC  =	./srcs/Pipex_bonus.c \
		./srcs/Pipex_bonus_utils.c \
		./srcs/ft_split.c \
		./srcs/libft_functions.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c 
 

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	=	-Wall -Werror -Wextra -D BUFFER_SIZE=1

RM	= rm -rf

all: $(NAME) header

header:
		@echo "\033[38;5;40m$$HEADER\n"
		
$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo "\033[38;5;40m$$COMPILING\n"
		
clean:
		@$(RM) $(OBJ)

fclean: clean
		@$(RM) $(NAME)

re: fclean all