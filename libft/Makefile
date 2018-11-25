# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 17:16:01 by cdelahay          #+#    #+#              #
#    Updated: 2018/11/10 18:05:04 by cdelahay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./*.c
NAME = libft.a
FLAG = 
OBJ = ./*.o

all: $(NAME)

$(NAME):
	gcc -c $(FLAG) $(SRC) -I includes/
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
