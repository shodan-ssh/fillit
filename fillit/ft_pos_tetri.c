/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pos_tetri.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: almalfoy <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 17:50:48 by almalfoy     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 12:33:24 by almalfoy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void		ft_axe_x_y(int fd)
{
	int 	ret_y, y = 0, line = 0, j = 0, z = 0, x = 0, ret_x;
	char	buf_x[6]; // buffer pour calculer l'indice
	char	buf_y[22]; // buffer pour calculer la ligne
	Coordonnes	tab_struct[ft_nb_tetri(fd) + 1]; // Tableau de structure

	while ((ret_y = read(fd, buf_y, 21))) // Boucle pour les Coord  des lignes
	{
		buf_y[ret_y] = '\0';
		while (y <= 20)
		{
			if (buf_y[y] == '\n')
				line++;
			if (buf_y[y] == '#')
			{
				tab_struct[j].y[j] = line;
				printf("line is %d\n", tab_struct[j].y[j]);
				j++;
			}
		}
		y = 0;
	}
	while ((ret_x = read(fd, buf_x, 5)))
	{
		buf_x[ret_x] = '\0';
		while (x <= 5)
		{
			if (buf_x[x] == '#')
			{
				tab_struct[z].x[z] = x;
				printf("z = %d\n", z);
				printf("x = %d\n", tab_struct[z].x[z]);
				z++;
			}
		}
		x = 0;
	}
}

int		main(void)
{
	int fd;

	fd = open("list_tetriminos", O_RDONLY);

	ft_axe_x_y(fd);
//	ft_axe_x(fd);
//	ft_axe_y(fd);
	return (0);
}
/*
void ft_tab_struct(int fd)
{
	int		i = 0;
	int		nb_tetri = ft_nb_tetri(fd);
	Coordonnes tab_struct[ft_nb_tetri(fd)];


	while (i < nb_tetri)
	{
		tab_struct[i].x = ft_axe_x(fd);
		tab_struct[i].y = ft_axe_y(fd);
		printf("tab[i] = %d\n", tab_struct[i].x);
		i++;
	}
}

void	ft_axe_y(int fd)
{
	int		i = 0, ret_read, line = 0, j = 0;
	char	buf[21];
	Coordonnes y;

	while ((ret_read = read(fd, buf, 21)))
	{
		buf[ret_read] = '\0';
		while (i <= 20)
		{
			if (buf[i] == '\n' && buf[i + 1] != '\n')
				line++;
			if (buf[i] == '#')
			{
				y.y[j] = line;
//				printf("%c -> line is %d\n", buf[i], y.y[j]);
				printf("line is %d\n", line);
				j++;
			}
			i++;
		}
		i = 0;
		line = 0;
	}
}

void	ft_axe_x(int fd)
{
	int i = 0, ret_read = 0, line = 0, j = 0;
	char	buf[6];
	Coordonnes x;

	while ((ret_read = read(fd, buf, 5)))
	{
		buf[ret_read] = '\0';
		while (i < ret_read)
		{
			if (buf[i] == '#')
			{
				x.x[j] = i;
				j++;
				printf("i = %d\n", x.x[j]);
			}
			i++;
		}
		i = 0;
	}
}
*/
