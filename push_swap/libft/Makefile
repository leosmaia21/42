# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 16:25:44 by ledos-sa          #+#    #+#              #
#    Updated: 2023/01/15 16:25:46 by ledos-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cc = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c\
	  ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c\
	  ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
	  ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
	  libftprintf/ft_printf.c libftprintf/ft_printf_utils.c


BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)

bonus: $(NAME) $(OBJS_BONUS)
		ar r $(NAME) $(OBJS_BONUS)
clean:	
		rm -rf $(OBJS)

fclean:	clean
		rm -rf $(NAME)

re:	fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	cc -nostartfiles -shared -o libft.so $(OBJS)
