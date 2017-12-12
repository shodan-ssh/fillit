/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   stock_tetriminos.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: almalfoy <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 16:02:37 by almalfoy     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 12:33:09 by almalfoy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#define BUF_SIZE 21

int		ft_nb_tetri(int fd)
{
	int		ret_read, i = 0, nb_block = 0, nb_dieze = 0;
	char	buf[BUF_SIZE + 1];

	while ((ret_read = read(fd, buf, BUF_SIZE)))
	{
		while (i < ret_read - 1)
		{
			if (buf[i] == '#')
			{
				if (nb_dieze > 2)
					nb_block++;
				nb_dieze++;
			}
			i++;
		}
		nb_dieze = 0;
		i = 0;
	}
	return (nb_block);
}
