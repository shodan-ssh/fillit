# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: almalfoy <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/01/05 15:22:34 by almalfoy     #+#   ##    ##    #+#        #
#    Updated: 2018/01/05 15:22:40 by almalfoy    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

CC = gcc

CFLAGS = -Werror -Wextra -Wall

NAME = fillit

D_SRC = src/

D_LIBFT = libft/

SRC1 =	ft_backtracking.c ft_check.c ft_dim_tab.c main.c ft_parse.c ft_stock.c \
		ft_success.c ft_place.c

SRC2 =	ft_putstr.c ft_putchar.c ft_isalpha.c

SRC_1 = $(addprefix $(D_SRC), $(SRC1))

SRC_2 = $(addprefix $(D_LIBFT), $(SRC2))

OBJ = $(SRC_1:.c=.o) $(SRC_2:.c=.o)

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
