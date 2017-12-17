/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   place.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: antdarin <antdarin@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/05 17:07:51 by antdarin     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/13 12:06:37 by antdarin    ###    #+. /#+    ###.fr     */
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
