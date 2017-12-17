/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dim_tab.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: antdarin <antdarin@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/05 15:29:51 by antdarin     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 10:36:29 by antdarin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_set_dim(int tetri_nbr)
{
	int dim;

	dim = 0;
	tetri_nbr = 4 * tetri_nbr;
	while ((dim * dim) < tetri_nbr)
		dim++;
	return (dim);
}

char	**ft_dim_tab(int dim)
{
	char	**grid;
	int		i;
	int		j;

	i = 0;
	j = 0;
	grid = (char **)malloc(sizeof(char*) * dim + 1);
	grid[dim] = NULL;
	while (i < dim)
		grid[i++] = (char *)malloc(sizeof(char) * dim + 1);
	i = 0;
	while (i < dim)
	{
		while (j < dim)
		{
			grid[i][j] = '.';
			j++;
		}
		grid[i][j] = '\0';
		j = 0;
		i++;
	}
	return (grid);
}
