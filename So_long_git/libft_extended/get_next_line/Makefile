# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: causilva <@student.42lisboa.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 10:44:39 by causilva          #+#    #+#              #
#    Updated: 2025/09/22 16:49:14 by causilva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftgnl.a

SOURCES = src/get_next_line.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJECTS)
	rm -f $(NAME)
	ar -rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
