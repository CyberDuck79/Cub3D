# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 23:15:25 by lmarques          #+#    #+#              #
#    Updated: 2020/01/31 13:25:56 by fhenrion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d
SRCS	=	main.c parsing_file.c parsing_options.c parsing_map.c \
			parsing_utils.c utils.c ray_casting.c draw.c keys.c move.c \
			sprites.c screenshot.c rotate.c

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

RED		=	"\033[1;31m
GREEN	=	"\033[1;32m
YELLOW	=	"\033[1;33m
WHITE	=	\033[1;0m"

OBJ = $(SRCS:.c=.o)

.SILENT:

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	echo $(YELLOW)[...] [ Compiling Librairies ]$(WHITE)
	echo $(YELLOW)[...] [ Compiling libft ]$(WHITE)
	make -C libft \
	&& echo $(YELLOW)[...] [ Compiling minilibx ]$(WHITE) \
	|| (echo $(RED)[ ✗ ] [ Libft Compilation Fail ]"; exit 1)
	make -C minilibx \
	&& echo $(GREEN)[ ✓ ] [ Librairies Successfully Compiled ]$(WHITE) \
	|| (echo $(RED)[ ✗ ] [ minilibx Compilation Fail ]"; exit 1)
	mv minilibx/libmlx.a .
	mv libft/libft.a .
	echo $(YELLOW)[...] [ Compiling Executable ]$(WHITE)
	$(CC) $(CFLAGS) -I. -L. -lft -lmlx \
	-framework OpenGL -framework Appkit $^ -o $@ \
	&& echo $(GREEN)[ ✓ ] [ Program Successfully Compiled ]$(WHITE) \
	|| (echo $(RED)[ ✗ ] [ Program Compilation Fail ]"; exit 1)

$(OBJ):
	echo $(YELLOW)[...] [ Compiling Objects ]$(WHITE)
	$(CC) $(CFLAGS) -c $(SRCS) \
	&& echo $(GREEN)[ ✓ ] [ Objects Successfully Compiled ]$(WHITE) \
	|| (echo $(RED)[ ✗ ] [ Program Compilation Fail ]"; exit 1)

bonus: bonus_obj
	echo $(YELLOW)[...] [ Compiling Librairies ]$(WHITE)
	echo $(YELLOW)[...] [ Compiling libft ]$(WHITE)
	make -C libft \
	&& echo $(YELLOW)[...] [ Compiling minilibx ]$(WHITE) \
	|| (echo $(RED)[ ✗ ] [ Libft Compilation Fail ]"; exit 1)
	make -C minilibx \
	&& echo $(GREEN)[ ✓ ] [ Librairies Successfully Compiled ]$(WHITE) \
	|| (echo $(RED)[ ✗ ] [ minilibx Compilation Fail ]"; exit 1)
	mv minilibx/libmlx.a .
	mv libft/libft.a .
	echo $(YELLOW)[...] [ Compiling Executable ]$(WHITE)
	$(CC) $(CFLAGS) -DBONUS=1 -I. -L. -lft -lmlx \
	-framework OpenGL -framework Appkit $(OBJ) -o $(NAME) \
	&& echo $(GREEN)[ ✓ ] [ Program Successfully Compiled ]$(WHITE) \
	|| (echo $(RED)[ ✗ ] [ Program Compilation Fail ]"; exit 1)

bonus_obj:
	echo $(YELLOW)[...] [ Compiling Objects ]$(WHITE)
	$(CC) $(CFLAGS) -DBONUS=1 -c $(SRCS) \
	&& echo $(GREEN)[ ✓ ] [ Objects Successfully Compiled ]$(WHITE) \
	|| (echo $(RED)[ ✗ ] [ Program Compilation Fail ]"; exit 1)

clean:
	echo $(YELLOW)[...] [ cleaning ]$(WHITE)
	make -C minilibx clean
	make -C libft clean
	rm -rf $(OBJ) libft.a libmlx.a
	echo $(GREEN)[ ✓ ] [ Successfull cleaning ]"

fclean: clean
	echo $(YELLOW)[...] [ Program cleaning ]"
	rm -rf $(NAME)
	echo $(GREEN)[ ✓ ] [ Program Successfully Cleaned ]"

re : fclean all
