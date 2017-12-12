/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_coord.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: almalfoy <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 15:12:21 by almalfoy     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 15:12:22 by almalfoy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
/*
Coordonnes	*ft_axe_x_y(int fd)
{
	int		ret_read, i = 0, line = 0;
	char 	buf[21];
	Coordonnes	tab_struct[ft_nb_tetri(fd)];

	while ((ret_read = read(fd, buf, 20)))
	{
		while (i <= 20)
		{
			if (buf[i] == '\n' && buf[i + 1] != '\n')
			{
				line++;
				printf("line = %d\n", line);
			}
		}
	}
	return (tab_struct);
}

int		main(int argc, char **argv)
{
	int fd;

	fd = open("argv[1]", O_RDONLY);
	ft_axe_x_y(fd);
	return (0);
}

void ft_pos(int fd)
{
	int i = 0, ret_read = 0, line = 0;
	char	buf[BUF_SIZE + 1];

	while ((ret_read = read(fd, buf, BUF_SIZE)))
	{
		while (i < ret_read - 1)
		{
			if (line > 3)
				line = line / 4;
			if (buf[i] == '#')
				printf("indice = %d\nligne = %d\n\n", i, line);
			i++;
			if (buf[i] == '\n')
				line++;
		}
		i = 0;
	}
}
*/
