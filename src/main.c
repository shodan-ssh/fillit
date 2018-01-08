/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: almalfoy <almalfoy@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 15:24:59 by almalfoy     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 12:10:30 by almalfoy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char		**map;
	Coordonnees		*tetri;
	t_nbr		nbr;

	map = NULL;
	if (argc != 2 || !(ft_parse(argv[1], &nbr.tetri_nbr)))
	{
		argc != 2 ? ft_putstr("usage: ./fillit file\n") : ft_putstr("error\n");
		return (0);
	}
	tetri = ft_stock(argv[1], nbr.tetri_nbr);
	nbr.size = ft_set_dim(nbr.tetri_nbr);
	while (!(map))
	{
		nbr.num_tetri = 0;
		free(map);
		map = ft_remplissage_tab(nbr.size);
		map = ft_rec_back(map, tetri, 0, nbr);
		nbr.size++;
	}
	ft_print(map);
	free(map);
	return (0);
}
