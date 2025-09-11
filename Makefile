# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brunmigu <brunmigu@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/11 18:31:26 by brunmigu          #+#    #+#              #
#    Updated: 2025/09/11 18:31:30 by brunmigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes
MLX_DIR = minilibx-linux
LIBFT_DIR = libft

SRC = $(SRC_DIR)/main.c
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR)
LDFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -L$(LIBFT_DIR) -lft

all: $(NAME)

$(NAME): $(OBJ) $(MLX_DIR)/libmlx.a $(LIBFT_DIR)/libft.a
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(MLX_DIR)/libmlx.a:
	$(MAKE) -C $(MLX_DIR)

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

