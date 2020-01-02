# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 23:15:25 by lmarques          #+#    #+#              #
#    Updated: 2020/01/02 15:49:36 by fhenrion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

NAME	=	Cub3D

SRCS	=	main.c
HDR_NAME = Cub3D.h

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
	&& echo $(GREEN)[ ✓ ] [ Minilibx Successfully Compiled ]$(WHITE) \
	|| (echo $(RED)[ ✗ ] [ Minilibx Compilation Fail ]"; exit 1)
	echo $(YELLOW)[...] [ Compiling libgrfx ]$(WHITE)
	make -C libgrfx \
	&& echo $(GREEN)[ ✓ ] [ Librairies Successfully Compiled ]$(WHITE) \
	|| (echo $(RED)[ ✗ ] [ Libgrfx Compilation Fail ]"; exit 1)
	mv minilibx/libmlx.dylib .
	mv libft/libft.a .
	mv libgrfx/libgrfx.a .
	echo $(YELLOW)[...] [ Compiling Executable ]$(WHITE)
	$(CC) $(CFLAGS) libmlx.dylib -I. -L. -lft -lgrfx \
	-framework OpenGL -framework Appkit $^ -o $@ -g3\
	&& echo $(GREEN)[ ✓ ] [ Program Successfully Compiled ]$(WHITE) \
	|| (echo $(RED)[ ✗ ] [ Program Compilation Fail ]"; exit 1)

%.o : %.c ${HDR_NAME}
	echo $(YELLOW)[...] [ Compiling Objects ]$(WHITE)
	$(CC) -c $(CFLAGS) -I $(HDR_NAME) $< -o $@ -g3\
	&& echo $(GREEN)[ ✓ ] [ Objects Successfully Compiled ]$(WHITE) \
	|| (echo $(RED)[ ✗ ] [ Program Compilation Fail ]"; exit 1)

clean:
	echo $(YELLOW)[...] [ cleaning ]$(WHITE)
	make -C minilibx clean
	make -C libft clean
	make -C libgrfx clean
	rm -rf $(OBJ) libft.a libgrfx.a libmlx.dylib
	echo $(GREEN)[ ✓ ] [ Successfull cleaning ]"

fclean: clean
	echo $(YELLOW)[...] [ Program cleaning ]"
	rm -rf $(NAME)
	echo $(GREEN)[ ✓ ] [ Program Successfully Cleaned ]"

re : fclean all
