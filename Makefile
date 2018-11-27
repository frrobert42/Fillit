NAME	= fillit

PGM		= fillit
FILES	= 	main.c \
			test.c
SRC		= $(FILES)
OBJ		= $(SRC:srcs/%.c=.obj/%.o)

INC		= -I includes -I libft/includes
FLAGS	= -Wall -Wextra -Werror
LIB		= -L libft -lft
CC		= gcc

.SILENT:

all: $(NAME)

$(NAME): make_libft $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(INC) $(LIB)

.obj/%.o: srcs/%.c
	@mkdir -p .obj
	$(CC) -c $< -o $@ $(FLAGS) $(INC)

make_libft:
	@echo "                                 "
	@echo "        \\\||||||////            "
	@echo "         \\  ~ ~  //             "
	@echo "         (  8 8  )               "
	@echo "______ oOOo-(_)-oOOo___________  "
	@echo "                                 "
	@echo " Salut tu veut voir ma libft ?   "
	@echo "                                 "
	@echo "_____________Oooo._____________  "
	@echo "   .oooO     (   )               "
	@echo "    (   )     ) /                "
	@echo "     \ (     (_/                 "
	@echo "      \_)                        "
	@echo "                                 "
	@echo "                                 "
	make -C libft

clean:
	@echo "                                 "
	@echo "        \\\||||||////            "
	@echo "         \\  ~ ~  //             "
	@echo "         (  8 8  )               "
	@echo "______ oOOo-(_)-oOOo___________  "
	@echo "                                 "
	@echo "      remove .obj files          "
	@echo "                                 "
	@echo "_____________Oooo._____________  "
	@echo "   .oooO     (   )               "
	@echo "    (   )     ) /                "
	@echo "     \ (     (_/                 "
	@echo "      \_)                        "
	@echo "                                 "
	@echo "                                 "
	rm -rf .obj

fclean: clean
	@echo "                                 "
	@echo "        \\\||||||////            "
	@echo "         \\  ~ ~  //             "
	@echo "         (  8 8  )               "
	@echo "______ oOOo-(_)-oOOo___________  "
	@echo "                                 "
	@echo "     remove fillit file          "
	@echo "                                 "
	@echo "_____________Oooo._____________  "
	@echo "   .oooO     (   )               "
	@echo "    (   )     ) /                "
	@echo "     \ (     (_/                 "
	@echo "      \_)                        "
	@echo "                                 "
	@echo "                                 "
	rm -f $(NAME)

re: fclean all
	make -C libft

gdb: make_libft
	cc -g $(FLAGS) $(SRC) -o $(NAME) $(INC) $(LIB)

.PHONY: all clean fclean re gdb
