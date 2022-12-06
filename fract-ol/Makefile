CC = gcc
MLXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11
SRCS = main.c complex.c
CFLAGS =  -O3 -lm
# -Wall -Wextra -Werror

OBJ = $(SRCS:.c=.o)
NAME = final

all: $(NAME)

$(NAME): $(OBJ)
	$(CC)  $(OBJ) $(MLXFLAGS) -o $(NAME) $(CFLAGS)
	./final

