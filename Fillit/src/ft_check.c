/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: almalfoy <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 15:24:28 by almalfoy     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/05 15:24:29 by almalfoy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_max(int *tab)
{
	int		i;
	int		max;

	i = 0;
	max = tab[i];
	while (i++ < 3)
		max < tab[i] ? max = tab[i] : max;
	return (max);
}

int		ft_check(char **grid, t_tetri tetri, int position, int size)
{
	int i;
	int count;
	int x;
	int y;

	x = position % size;
	y = position / size;
	i = 0;
	count = 0;
	if ((ft_max(tetri.y) + y) >= size
	|| (ft_max(tetri.x) + x) >= size)
		return (0);
	while (i < 4)
	{
		if (grid[tetri.y[i] + y][tetri.x[i] + x] == '.')
			count++;
		i++;
	}
	if (count == 4)
		return (1);
	return (0);
}