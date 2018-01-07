# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: almalfoy <almalfoy@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/01/05 15:22:34 by almalfoy     #+#   ##    ##    #+#        #
#    Updated: 2018/01/07 16:35:53 by almalfoy    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

CC = gcc

CFLAGS = -Werror -Wextra -Wall

NAME = fillit

D_SRC = src/

SRC1 =	ft_backtracking.c ft_map.c main.c ft_buf_21_parsing.c \
		ft_stock.c ft_place.c ft_fonctions.c

SRC_1 = $(addprefix $(D_SRC), $(SRC1))


OBJ = $(SRC_1:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

./%.o: ./%.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
