/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pos_tetri.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: almalfoy <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 17:50:48 by almalfoy     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 17:50:50 by almalfoy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fillit.h"
#define BUF_SIZE 21


void ft_pos(int fd)
{
	int i = 0, ret_read = 0, line = 0;
	char	buf[BUF_SIZE + 1], *pos_tetri;

	while ((ret_read = read(fd, buf, BUF_SIZE)))
	{
		while (i < ret_read - 1)
		{
			if (buf[i] == '\n')
				line++;
			i++;
			printf("i = %d\n", i);
		}
		i = 0;
		line = 0;
		printf("line = %d\n", line);
	}
}

/*
Coordonnes		*ft_calc_pos(int fd)
{
	int		ret_read, indice = 0, line = 0, i = 0, j = 0;
	char	buf[BUF_SIZE + 1];
	Coordonnes	tab_pos[ft_nb_tetri(fd)];

	while ((ret_read = read(fd, buf, BUF_SIZE)))
	{
		while (i < ret_read - 1)
		{
			line++;
			i++;
			printf("i = %d\nline = %d\n", i, line);
		}
		i = 0;
		line = 0;
		printf("yo\n");
	}
	return (tab_pos);
}
*/
int		main(void)
{
	int fd;

	fd = open("list_tetriminos", O_RDONLY);
	ft_pos(fd);
	//ft_calc_pos("list_tetriminos");
	return (0);
}
