# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 13:41:10 by fhenrion          #+#    #+#              #
#    Updated: 2020/01/02 11:35:26 by fhenrion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HDR_NAME = libft.h
SRC_NAME = memset bzero memcpy memccpy memmove memchr memcmp strlen islower \
isupper isalpha isdigit isalnum isascii isprint toupper tolower strchr \
strrchr strncmp strlcpy strlcat strnstr atoi calloc strdup substr strjoin \
strtrim split itoa strmapi putchar_fd putstr_fd putendl_fd putnbr_fd \
lstnew lstadd_front lstsize lstlast lstadd_back lstdelone \
lstclear lstiter lstmap lstat putstrlst_fd putnbrlst_fd lstreverse lstmerge \
isspace memdel putchar putendl putnbr putstr strchri strrchri substrchr \
substrrchr lststrsort lststrrsort strcmp lstchrsplit putstrtab_fd tabstrsort \
tabstrrsort

SRC = $(addprefix ft_,$(SRC_NAME))
O_SRC = $(addsuffix .o,$(SRC))

CC = gcc
CFLAGS = -Werror -Wall -Wextra

.PHONY: clean fclean all re bonus

all : $(NAME)

$(NAME): $(O_SRC)
	@ar rc $@ $^
	@ranlib $@
	@echo "\033[0;32m[ ✓ ] [ Libft Successfully Compiled ]\033[0m"

%.o : %.c ${HDR_NAME}
	$(CC) -c $(CFLAGS) -I $(HDR_NAME) $< -o $@

clean:
	@/bin/rm -f $(O_SRC)
	@/bin/rm -f libft.h.gch

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean $(NAME)
