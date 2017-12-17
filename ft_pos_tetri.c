/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pos_tetri.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: almalfoy <almalfoy@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 17:50:48 by almalfoy     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/17 16:07:46 by almalfoy    ###    #+. /#+    ###.fr     */
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
	int a;

	min = tab_struct->x[0];
	a = 0;
	while (a++ < 3)
		min > tab_struct->x[a] ? min = tab_struct->x[a] : min;
	a = -1;
	while (a++ < 3)
		tab_struct->x[a] -= min;
	a = 0;
	min = tab_struct->y[0];
	while (a++ < 3)
		min > tab_struct->y[a] ? min = tab_struct->y[a] : min;
	a = -1;
	while (a++ < 3)
		tab_struct->y[a] -= min;
}

/*
void	ft_haut_gauche(Coordonnes *tab_struct, int nb_tetri)
{
	int i;
	int cpt;

	cpt = 0;
	i = 0;
	j = 0;
	while (j < nb_tetri)
	{
		while (i < 4)
		{
			if ()
			printf("%d\n", tab_struct[j].x[i]);
			i++;
		}
	}
}

void    ft_coord(char *buf, Coordonnes *tab_struct)
{
	int i;
	int cpt;
	int line;
	int fd;

	fd = open("list_tetriminos", O_RDONLY);
	i = 0;
	cpt = 0;
	line = 0;
	while (cpt < 20)
	{
		if (buf[cpt] == '\n')
			line++;
		if (buf[cpt] == '#')
		{
			tab_struct->y[i] = line;
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
//		ft_haut_gauche(&tab_struct[j], ft_nb_tetri(ft_open(argv)));
		j++;
	}
	return (tab_struct);
}
*/
