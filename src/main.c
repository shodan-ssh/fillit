/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: almalfoy <almalfoy@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 15:24:59 by almalfoy     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/05 18:29:33 by almalfoy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void ft_print(char **map) {
	int i = 0;

	while (map[i] != '\0')
	{
		ft_putstr(map[i]);
		if (i % 1 == 0)
			ft_putchar('\n');
		i++;
	}
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
