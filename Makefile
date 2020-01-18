# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 23:15:25 by lmarques          #+#    #+#              #
#    Updated: 2020/01/18 17:27:23 by fhenrion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D
SRCS	=	main.c parsing_file.c parsing_options.c parsing_utils.c parsing_map.c

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
	&& echo $(YELLOW)[...] [ Compiling libgrfx ]$(WHITE) \
	|| (echo $(RED)[ ✗ ] [ Minilibx Compilation Fail ]"; exit 1)
	make -C libgrfx \
	&& echo $(GREEN)[ ✓ ] [ Librairies Successfully Compiled ]$(WHITE) \
	|| (echo $(RED)[ ✗ ] [ Libgrfx Compilation Fail ]"; exit 1)
	mv minilibx/libmlx.a .
	mv libft/libft.a .
	mv libgrfx/libgrfx.a .
	echo $(YELLOW)[...] [ Compiling Executable ]$(WHITE)
	$(CC) $(CFLAGS) -I. -L. -lft -lmlx -lgrfx \
	-framework OpenGL -framework Appkit $^ -o $@ \
	&& echo $(GREEN)[ ✓ ] [ Program Successfully Compiled ]$(WHITE) \
	|| (echo $(RED)[ ✗ ] [ Program Compilation Fail ]"; exit 1)

$(OBJ):
	echo $(YELLOW)[...] [ Compiling Objects ]$(WHITE)
	$(CC) $(CFLAGS) -c $(SRCS) \
	&& echo $(GREEN)[ ✓ ] [ Objects Successfully Compiled ]$(WHITE) \
	|| (echo $(RED)[ ✗ ] [ Program Compilation Fail ]"; exit 1)

debug:
	echo $(YELLOW)[...] [ Compiling Objects ]$(WHITE)
	$(CC) $(CFLAGS) -c $(SRCS) -fsanitize=address -g -O0 \
	&& echo $(GREEN)[ ✓ ] [ Objects Successfully Compiled ]$(WHITE) \
	|| (echo $(RED)[ ✗ ] [ Program Compilation Fail ]"; exit 1)
	echo $(YELLOW)[...] [ Compiling Librairies ]$(WHITE)
	echo $(YELLOW)[...] [ Compiling libft ]$(WHITE)
	make -C libft debug\
	&& echo $(YELLOW)[...] [ Compiling minilibx ]$(WHITE) \
	|| (echo $(RED)[ ✗ ] [ Libft Compilation Fail ]"; exit 1)
	make -C minilibx \
	&& echo $(YELLOW)[...] [ Compiling libgrfx ]$(WHITE) \
	|| (echo $(RED)[ ✗ ] [ Minilibx Compilation Fail ]"; exit 1)
	make -C libgrfx debug\
	&& echo $(GREEN)[ ✓ ] [ Librairies Successfully Compiled ]$(WHITE) \
	|| (echo $(RED)[ ✗ ] [ Libgrfx Compilation Fail ]"; exit 1)
	mv minilibx/libmlx.a .
	mv libft/libft_dbg.a .
	mv libgrfx/libgrfx_dbg.a .
	echo $(YELLOW)[...] [ Compiling Executable ]$(WHITE)
	$(CC) $(CFLAGS) -I. -L. -lft_dbg -lmlx -lgrfx_dbg \
	-framework OpenGL -framework Appkit $(OBJ) -o $(NAME) \
	-g -fsanitize=address \
	&& echo $(GREEN)[ ✓ ] [ Program Successfully Compiled ]" \
	|| (echo $(RED)[ ✗ ] [ Program Compilation Fail ]"; exit 1)

clean:
	echo $(YELLOW)[...] [ cleaning ]$(WHITE)
	make -C minilibx clean
	make -C libft clean
	make -C libgrfx clean
	rm -rf $(OBJ) libft.a libmlx.a libgrfx.a FdF.h.gch libft_dbg.a libgrfx_dbg.a
	echo $(GREEN)[ ✓ ] [ Successfull cleaning ]"

fclean: clean
	echo $(YELLOW)[...] [ Program cleaning ]"
	rm -rf $(NAME)
	echo $(GREEN)[ ✓ ] [ Program Successfully Cleaned ]"

re : fclean all
