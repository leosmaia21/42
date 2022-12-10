# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 18:05:32 by ledos-sa          #+#    #+#              #
#    Updated: 2022/12/10 00:13:48 by ledos-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
# CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)

clean:	
		rm -rf $(OBJS)

fclean:	clean
		rm -rf $(NAME)

re:	fclean all
