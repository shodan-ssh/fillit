/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_backtrack.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: almalfoy <almalfoy@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/18 16:19:20 by almalfoy     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/18 16:31:11 by almalfoy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_rec_back(char **map, Coordonnes *tetri, int pos, t_nbr nbr)
{
	int x;
	int y;

	x = pos % nbr.size;
	y = pos / nbr.size;
	while (x < nbr.size && y < nbr.size)
	{
		if (ft_check(map, tetri[nbr.num_tetri], pos, nbr.size))
		{
			map = ft_place_tetri(map, tetri[nbr.num_tetri], pos, nbr.size);
			if (ft_success(map, tetri) == 1)
				return (map);
			nbr.num_tetri = nbr.num_tetri + 1;
			ft_rec_back(map, tetri, 0, nbr);
			nbr.num_tetri = nbr.num_tetri - 1;
		}
		if (ft_success(map, tetri) == 1)
			return (map);
		ft_del_tetri(map, tetri[nbr.num_tetri]);
		pos++;
		x = pos % nbr.size;
		y = pos / nbr.size;
	}
	return (NULL);
}
