/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_stock.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: almalfoy <almalfoy@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 15:24:46 by almalfoy     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 11:55:18 by almalfoy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

Coordonnees		ft_stock_pos(char *buf)
{
	int		i;
	int		j;
	Coordonnees	tab;

	i = 0;
	j = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
		{
			tab.x[j] = i % 5;
			tab.y[j] = i / 5;
			j++;
		}
		i++;
	}
	return (tab);
}

void		ft_ajustement(Coordonnees *tetri)
{
	int min;
	int a;

	min = tetri->x[0];
	a = 0;
	while (a++ < 3)
		min > tetri->x[a] ? min = tetri->x[a] : min;
	a = -1;
	while (a++ < 3)
		tetri->x[a] -= min;
	a = 0;
	min = tetri->y[0];
	while (a++ < 3)
		min > tetri->y[a] ? min = tetri->y[a] : min;
	a = -1;
	while (a++ < 3)
		tetri->y[a] -= min;
}

Coordonnees		*ft_stock(char *file, int tetri_nbr)
{
	int			fd;
	char		buf[BUF_SIZE];
	Coordonnees		*tetri;
	int			num_tetri;

	num_tetri = 0;
	if (!(tetri = (Coordonnees*)malloc(sizeof(Coordonnees) * tetri_nbr + 1)))
		return (NULL);
	fd = open(file, O_RDONLY);
	while (read(fd, buf, BUF_SIZE))
	{
		tetri[num_tetri] = ft_stock_pos(buf);
		tetri[num_tetri].letter = 65 + num_tetri;
		ft_ajustement(&tetri[num_tetri]);
		num_tetri++;
	}
	close(fd);
	tetri[num_tetri].letter = 0;
	return (tetri);
}
