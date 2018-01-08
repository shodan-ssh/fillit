/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_place.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: almalfoy <almalfoy@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 15:25:38 by almalfoy     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 12:08:31 by almalfoy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_place(char **map, Coordonnees tetri, int position, int size)
{
	int	i;
	int x;
	int y;

	x = position % size;
	y = position / size;
	i = 0;
	while (i < 4)
	{
		map[tetri.y[i] + y][tetri.x[i] + x] = tetri.letter;
		i++;
	}
	return (map);
}

char	**ft_del_tetri(char **map, Coordonnees tetri)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == tetri.letter)
				map[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (map);
}
