# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 23:15:25 by lmarques          #+#    #+#              #
#    Updated: 2020/01/02 15:49:37 by fhenrion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgrfx.a
HDR_NAME = libgrfx.h
SRC_NAME = line image vector environment

O_SRC = $(addsuffix .o,$(SRC_NAME))

CC = gcc
CFLAGS = -Werror -Wall -Wextra

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(O_SRC)
	@ar rc $@ $^
	@ranlib $@
	@echo "\033[0;32m[ ✓ ] [ Libgrfx Successfully Compiled ]\033[0m"

%.o : %.c ${HDR_NAME}
	$(CC) -c $(CFLAGS) -I $(HDR_NAME) $< -o $@ -g3

clean:
	@/bin/rm -f $(O_SRC)
	@/bin/rm -f libft.h.gch

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
