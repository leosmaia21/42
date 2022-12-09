CC = clang
MLXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11 -lm
SRCS = main.c complex.c minilib.c fractals.c libft/libft.a
CFLAGS =  -O3 -march=native -Wall -Wextra -Werror

OBJ = $(SRCS:.c=.o)
NAME = fract-ol

all: $(NAME)

$(NAME): $(OBJ)
	$(CC)  $(OBJ) $(CFLAGS) $(MLXFLAGS) -o $(NAME) 

