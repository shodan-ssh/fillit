/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dim_tab.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: almalfoy <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 15:25:26 by almalfoy     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/05 15:25:28 by almalfoy    ###    #+. /#+    ###.fr     */
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
