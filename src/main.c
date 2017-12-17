/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: antdarin <antdarin@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 13:39:58 by antdarin     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/13 12:11:45 by antdarin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print(char **grid)
{
	while (*grid)
	{
		ft_putstr(*grid++);
		ft_putchar('\n');
	}
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	char		**grid;
	t_tetri		*tetri;
	t_nbr		nbr;

	grid = NULL;
	if (argc != 2 || !(ft_parse(argv[1], &nbr.tetri_nbr)))
	{
		argc != 2 ? ft_putstr("usage: ./fillit file\n") : ft_putstr("error\n");
		return (0);
	}
	tetri = ft_stock(argv[1], nbr.tetri_nbr);
	nbr.size = ft_set_dim(nbr.tetri_nbr);
	while (!(grid))
	{
		nbr.num_tetri = 0;
		free(grid);
		grid = ft_dim_tab(nbr.size);
		grid = ft_rec_back(grid, tetri, 0, nbr);
		nbr.size++;
	}
	ft_print(grid);
	free(grid);
	return (0);
}
