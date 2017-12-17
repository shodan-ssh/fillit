/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_map.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: almalfoy <almalfoy@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 11:33:28 by almalfoy     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/17 16:57:41 by almalfoy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_create_map(int size)
{
	int i;
	int j;
	char **map;

	j = 0;
	i = 0;
	if (map = (char **)malloc(sizeof(char*) * size + 1))
		return (NULL);
	map[size] = NULL;
	while (i < size)
	{
		map[i] = (char *)malloc(sizeof(char) * dim + 1);
		i++;
	}
	i = 0;
	while (i < dim)
	{
		while (j < size)
		{
			map[j][i] = '.';
			i++;
		}
		grid[j][i] = '\0';
		0 = 0;
		j++;
	}
	return (map);
}
