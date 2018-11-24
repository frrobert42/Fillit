NAME	= fillit

PGM		= fillit
FILES	= main.c check_tetri.c
SRC		= $(FILES)
OBJ		= $(SRC:srcs/%.c=.obj/%.o)

INC		= -I includes -I libft/includes
FLAGS	= -Wall -Wextra -Werror
LIB		= -L libft -lft
CC		= gcc

all: $(NAME)

$(NAME): make_libft $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(INC) $(LIB)

.obj/%.o: srcs/%.c
	@mkdir -p .obj
	$(CC) -c $< -o $@ $(FLAGS) $(INC)

make_libft:
	@echo "##  Compilation of libft ##"
	@make -C libft

clean:
	@echo "## remove .obj files     ##"
	rm -rf .obj

fclean: clean
	@echo "## remove fillit file    ##"
	rm -f $(NAME)

re: fclean all
	@echo "## re                    ##"

gdb: make_libft
	cc -g $(FLAGS) $(SRC) -o $(NAME) $(INC) $(LIB)

.PHONY: all clean fclean re gdb
