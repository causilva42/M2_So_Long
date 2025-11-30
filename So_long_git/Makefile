# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: causilva <@student.42lisboa.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/15 10:20:27 by causilva          #+#    #+#              #
#    Updated: 2025/09/25 17:30:15 by causilva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SOURCES = src/main.c \
		src/game.c \
		src/graphics.c \
		src/parse_map.c \
		src/utils.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -O3


MLX_DIR = mlx_extended/mlx

MLX = $(MLX_DIR)/libmlx.a

LIBFT_MLX_DIR = mlx_extended/libft_mlx

LIBFT_MLX_LIB = $(LIBFT_MLX_DIR)/libft_mlx.a

FT_PRINTF_DIR = libft_extended/ft_printf

FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

GNL_DIR = libft_extended/get_next_line

GNL_LIB = $(GNL_DIR)/libftgnl.a

LIBFT_DIR = libft_extended/libft

LIBFT_LIB = $(LIBFT_DIR)/libft.a

LIBS = $(LIBFT_MLX_LIB) $(FT_PRINTF_LIB) $(GNL_LIB) $(LIBFT_LIB)


all: $(NAME)

$(NAME): $(MLX) $(OBJECTS) $(LIBS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBS) \
	-Lmlx_extended/mlx -lmlx -lXext -lX11 -lm -lz -o $(NAME)

$(MLX):
	git clone https://github.com/42paris/minilibx-linux.git $(MLX_DIR)
	$(MAKE) --no-print-directory -C $(MLX_DIR) all > /dev/null

$(LIBFT_MLX_LIB):
	$(MAKE) --no-print-directory -C $(LIBFT_MLX_DIR) > /dev/null

$(FT_PRINTF_LIB):
	$(MAKE) --no-print-directory -C $(FT_PRINTF_DIR) > /dev/null

$(GNL_LIB):
	$(MAKE) --no-print-directory -C $(GNL_DIR) > /dev/null

$(LIBFT_LIB):
	$(MAKE) --no-print-directory -C $(LIBFT_DIR) > /dev/null

clean:
	rm -f $(OBJECTS)
	$(MAKE) --no-print-directory clean -C $(LIBFT_MLX_DIR) > /dev/null
	$(MAKE) --no-print-directory clean -C $(FT_PRINTF_DIR) > /dev/null
	$(MAKE) --no-print-directory clean -C $(GNL_DIR) > /dev/null
	$(MAKE) --no-print-directory clean -C $(LIBFT_DIR) > /dev/null

fclean:
	rm -f $(OBJECTS)
	rm -f $(NAME)
	$(MAKE) --no-print-directory fclean -C $(LIBFT_MLX_DIR) > /dev/null
	$(MAKE) --no-print-directory fclean -C $(FT_PRINTF_DIR) > /dev/null
	$(MAKE) --no-print-directory fclean -C $(GNL_DIR) > /dev/null
	$(MAKE) --no-print-directory fclean -C $(LIBFT_DIR) > /dev/null

re: fclean all

.PHONY: all clean fclean re