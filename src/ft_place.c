/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_place.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: almalfoy <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 15:25:38 by almalfoy     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/05 15:25:39 by almalfoy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_place(char **grid, t_tetri tetri, int position, int size)
{
	int	i;
	int x;
	int y;

	x = position % size;
	y = position / size;
	i = 0;
	while (i < 4)
	{
		grid[tetri.y[i] + y][tetri.x[i] + x] = tetri.a;
		i++;
	}
	return (grid);
}

char	**ft_del_tetri(char **grid, t_tetri tetri)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (grid[a])
	{
		while (grid[a][b])
		{
			if (grid[a][b] == tetri.a)
				grid[a][b] = '.';
			b++;
		}
		b = 0;
		a++;
	}
	return (grid);
}
