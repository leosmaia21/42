# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 20:54:16 by ledos-sa          #+#    #+#              #
#    Updated: 2022/12/03 21:15:23 by ledos-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror


SERVER = server
CLIENT = client
SERVER_SRCS = server.c                                                                             
CLIENT_SRCS = client.c
SERVER_BONUS_SRCS = server_bonus.c
CLIENT_BONUS_SRCS = client_bonus.c


SERVER_OBJS = ${SERVER_SRCS:.c=.o}
SERVER_BONUS_OBJS = ${SERVER_BONUS_SRCS:.c=.o}
CLIENT_OBJS = ${CLIENT_SRCS:.c=.o}
CLIENT_BONUS_OBJS = ${CLIENT_BONUS_SRCS:.c=.o}
LIBFT= libft/libft.a
NAME = $(SERVER) $(CLIENT)
all: $(NAME) 

$(NAME): ${SERVER_OBJS} ${CLIENT_OBJS} ${LIBFT}
	${CC} ${SERVER_OBJS} libft/libft.a -o ${SERVER}
	${CC} ${CLIENT_OBJS} libft/libft.a -o ${CLIENT}

$(LIBFT):
	${MAKE} -C ./libft

bonus: ${SERVER_BONUS_OBJS} ${CLIENT_BONUS_OBJS} ${LIBFT}
	${CC} ${SERVER_BONUS_OBJS} libft/libft.a -o ${SERVER}
	${CC} ${CLIENT_BONUS_OBJS} libft/libft.a -o ${CLIENT}

clean:	
	rm -rf ${SERVER_OBJS} ${SERVER_BONUS_OBJS} ${CLIENT_OBJS} ${CLIENT_BONUS_OBJS}

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
