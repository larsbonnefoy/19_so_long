# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbonnefo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 13:54:46 by lbonnefo          #+#    #+#              #
#    Updated: 2022/10/24 08:07:28 by lbonnefo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_is_hex.c \
		ft_is_int.c \
		ft_is_ptr.c \
		ft_is_str.c \
		ft_is_unsigned.c \
		ft_printf.c \
		ft_putchar_fd.c \
		ft_strlen.c \

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
		ar -rc $(NAME) $(OBJ)

.c.o:
		cc $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

clean:
		rm -f $(OBJ) 

fclean: clean
		rm -f $(NAME)

re :	fclean $(NAME)
	
.PHONY: all clean fclean re 
