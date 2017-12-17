/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   success.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: antdarin <antdarin@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 15:04:20 by antdarin     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/12 17:12:13 by antdarin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

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
