# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: almalfoy <almalfoy@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/27 11:30:00 by almalfoy     #+#   ##    ##    #+#        #
#    Updated: 2017/12/19 15:08:27 by almalfoy    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fillit

SRC = main.c ft_pos_tetri.c buf_21_parsing.c fonctions.c ft_map.c \
		ft_backtrack.c ft_succes.c ft_check.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $^

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all, clean, fclean, re
