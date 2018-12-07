NAME = push_swap

LIB = libft/libft.a

SRC = ft_checker.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAG) $(OBJ) $(LIB) -o $(NAME)

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $< 

re: fclean all

clean:
	@/bin/rm -Rf $(OBJ)

fclean: clean
	@/bin/rm -Rf $(NAME)
