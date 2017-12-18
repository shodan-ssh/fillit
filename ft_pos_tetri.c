/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pos_tetri.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: almalfoy <almalfoy@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 17:50:48 by almalfoy     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/18 16:42:44 by almalfoy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#define BUF_SIZE 21

void    ft_coord(char *buf, Coordonnes *tab_struct)
{
	int i;
	int cpt;

	i = 0;
	cpt = 0;
	while (cpt < 20)
	{
		if (buf[cpt] == '#')
		{
			tab_struct->y[i] = cpt / 5;
			tab_struct->x[i] = cpt % 5;
			i++;
		}
		cpt++;
	}
}

Coordonnes	*ft_21_par_21(Coordonnes *tab_struct, char *argv)
{
	int fd;
	int ret_read;
	int j;
	char buf[BUF_SIZE + 1];

	(void)argv;
	j = 0;
	fd = open("list_tetriminos", O_RDONLY);
	while ((ret_read = read(fd, buf, BUF_SIZE)))
	{
		ft_coord(buf, &tab_struct[j]);
		tab_struct[j].letter = 'A' + j;
		ft_haut_gauche(&tab_struct[j]);
		j++;
	}
	return (tab_struct);
}

void	ft_haut_gauche(Coordonnes *tab_struct)
{
	int min;
	int i;

	min = tab_struct->x[0];
	i = 0;
	while (i < 3)
	{
		min > tab_struct->x[i] ? min = tab_struct->x[i] : min;
		i++;
	}
	i = -1;
	while (i++ < 3)
		tab_struct->x[i] -= min;
	i = 0;
	min = tab_struct->y[0];
	while (i++ < 3)
		min > tab_struct->y[i] ? min = tab_struct->y[i] : min;
	i = -1;
	while (i++ < 3)
		tab_struct->y[i] -= min;
}
