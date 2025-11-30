# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: causilva <@student.42lisboa.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/15 10:20:27 by causilva          #+#    #+#              #
#    Updated: 2025/08/28 12:02:58 by causilva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

SOURCES = main.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -O3


all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -Lmlx -lmlx -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re