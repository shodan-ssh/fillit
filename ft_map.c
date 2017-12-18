/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_map.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: almalfoy <almalfoy@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 11:33:28 by almalfoy     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/18 16:08:00 by almalfoy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_create_final_map(int size)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = (char **)malloc(sizeof(char*) * size + 1);
	map[size] = NULL;
	while (i < size)
		map[i++] = (char *)malloc(sizeof(char) * size + 1);
	i = 0;
	while (i < size)
	{
		while (j < size)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		j = 0;
		i++;
	}
	return (map);
}

void ft_print_map(char **map) {
	int i = 0;

	while (map[i] != '\0')
	{
		if (i % 1 == 0)
			ft_putchar('\n');
		ft_putstr(map[i]);
		i++;
	}
}

char	**ft_place_tetri(Coordonnes tetri, char **map, int position, int size)
{
	int i;
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

char	**ft_del_tetri(Coordonnes tetri, char **map)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == tetri.letter)
				map[j][i] = '.';
			i++;
		}
		i = 0;
		j++;
	}
	return (map);
}
