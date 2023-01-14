CC = clang
MLXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11 -lm 
SRCS = main.c complex.c minilib.c fractals.c 
CFLAGS = -O3 -march=native -Wall -Wextra -Werror

OBJ = $(SRCS:.c=.o)
NAME = fractol

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(MAKE) -C ./libft
	$(MAKE) -C ./libftprintf
	$(CC)  $(OBJ) $(CFLAGS) $(MLXFLAGS) libft/libft.a libftprintf/libftprintf.a -o $(NAME) 

$(LIB):
clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./libftprintf
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./libftprintf
	rm -rf $(NAME)

re: fclean all
