# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 13:10:56 by lbonnefo          #+#    #+#              #
#    Updated: 2022/11/22 08:33:52 by lbonnefo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =	main.c \
		parsing.c \
		utils_parsing.c \
		struct_init.c \
		player_mvt.c \
		pathfinding.c \
		struct_cpy.c \
		key_hook.c \

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

###LIB INCLUDES###

LIBFT_DIR = 19_libft

LIBFT = $(LIBFT_DIR)/libft.a

GNL_DIR = gnl

GNL = $(GNL_DIR)/gnl.a

MLX_DIR = mlx

MLX_PATH = $(MLX_DIR)/libmlx.a

MLX = -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit $(MLX_PATH)

$(NAME): $(OBJ)
		@make -C $(LIBFT_DIR)
		@make -C $(GNL_DIR)
		@make -C $(MLX_DIR)
		cc $(CFLAGS) -g $(OBJ) $(LIBFT) $(GNL) $(MLX) -o $(NAME)
.c.o:
		cc $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

clean:
		@make --no-print-directory clean -C $(LIBFT_DIR)
		@make --no-print-directory clean -C $(GNL_DIR)
		rm -f $(OBJ) 

fclean: clean
		@make --no-print-directory fclean -C $(LIBFT_DIR)
		@make --no-print-directory fclean -C $(GNL_DIR)
		rm -f $(NAME)

re :	fclean $(NAME)
	
.PHONY: all clean fclean re 
