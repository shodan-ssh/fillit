/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_backtracking.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: almalfoy <almalfoy@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 15:25:14 by almalfoy     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/07 13:45:50 by almalfoy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_rec_back(char **grid, t_tetri *tetri, int pos, t_nbr nbr)
{
	int x;
	int y;

	x = pos % nbr.size;
	y = pos / nbr.size;
	while (x < nbr.size && y < nbr.size)
	{
		if (ft_check(grid, tetri[nbr.num_tetri], pos, nbr.size))
		{
			grid = ft_place(grid, tetri[nbr.num_tetri], pos, nbr.size);
			if (ft_success(grid, tetri) == 1)
				return (grid);
			nbr.num_tetri = nbr.num_tetri + 1;
			ft_rec_back(grid, tetri, 0, nbr);
			nbr.num_tetri = nbr.num_tetri - 1;
		}
		if (ft_success(grid, tetri) == 1)
			return (grid);
		ft_del_tetri(grid, tetri[nbr.num_tetri]);
		pos++;
		x = pos % nbr.size;
		y = pos / nbr.size;
	}
	return (NULL);
}

int		ft_success(char **grid, t_tetri *tetri)
{
	int		count;
	int		a;
	int		b;
	int		c;

	count = 0;
	a = 0;
	b = 0;
	c = 0;
	while (tetri[c].a != 0)
		c++;
	while (grid[a] != NULL)
	{
		while (grid[a][b] != '\0')
		{
			if (ft_isalpha(grid[a][b]))
				count++;
			b++;
		}
		b = 0;
		a++;
	}
	if (count == c * 4)
		return (1);
	return (0);
}

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
