# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: causilva <@student.42lisboa.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/15 10:20:27 by causilva          #+#    #+#              #
#    Updated: 2025/09/24 11:24:48 by causilva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_mlx.a

SOURCES = ft_img_func_put.c \
		ft_img_img_put.c \
		ft_img_pixel_get.c \
		ft_img_pixel_put_special.c \
		ft_img_pixel_put.c \
		ft_my_file_to_image.c \
		ft_my_new_image.c \
		linear_to_color_wheel.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -O3


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