# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbonnefo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 13:54:46 by lbonnefo          #+#    #+#              #
#    Updated: 2022/11/28 09:09:07 by lbonnefo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c\
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_split.c \
		ft_strtrim.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_strjoinf.c \
		ft_strtrimf.c \

SRCS_BONUS =	ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c \

OBJ = $(SRCS:.c=.o)

OBJ_BONUS = $(SRCS_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
		@ar -rc $(NAME) $(OBJ)

.c.o:
		@cc $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

clean:
		rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
		rm -f $(NAME)

re :	fclean $(NAME)

bonus : all $(OBJ_BONUS)
		ar -rc $(NAME) $(OBJ) $(OBJ_BONUS)
	
.PHONY: all clean fclean re bonus
