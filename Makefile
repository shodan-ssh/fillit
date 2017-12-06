# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: almalfoy <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/27 11:30:00 by almalfoy     #+#   ##    ##    #+#        #
#    Updated: 2017/11/27 11:30:18 by almalfoy    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fillit

SRC = src/ft_parse.c

FLAGS = -Wall -Wextra -Werror
all: $(NAME)

$(NAME):
	gcc $(FLAGS) -L/include -lft $(SRC)
clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
