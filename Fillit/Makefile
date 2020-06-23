NAME	= fillit
COM		= gcc
FLAGS	= -Wall -Wextra -Werror
SRC		= ./src/main.c ./src/ft_strlen.c ./src/read.c ./src/error_handling.c \
		  ./src/validate_map_basic.c ./src/validate_map_advanced.c ./src/uni_to_bi.c \
		  ./src/adjust_coords.c ./src/move_pieces_up.c ./src/move_pieces_left.c \
		  ./src/alloc_n_assign_arr.c ./src/solver.c ./src/ft_putchar.c \
		  ./src/ft_putstr.c
OBJ		= $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(COM) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ): %.o: %.c
	$(COM) -c $(FLAGS) $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all