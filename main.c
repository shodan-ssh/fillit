/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: almalfoy <almalfoy@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/09 12:19:01 by almalfoy     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/19 14:54:21 by almalfoy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#define BUF_SIZE 545

int		ft_open(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	return (fd);
}

char	*ft_read(int fd)
{
	int 	ret_read;
	char	*buf_bis;
	char 	buf[BUF_SIZE + 1];

	while ((ret_read = read(fd, buf, BUF_SIZE)))
	{
		buf_bis = buf;
		buf[ret_read] = '\0';
	}
	return (buf_bis);
}

void    ft_print_coord(Coordonnes *tab_struct, int nb_tetri)
{
	int i;
	int j;

	j = 0;
	i = 0;
	printf("nb_tetri = %d\n", nb_tetri);
	while (j < nb_tetri)
	{
		while (i < 4)
		{
			printf("x = %d, y = %d\n", tab_struct[j].x[i], tab_struct[j].y[i]);
			i++;
		}
		printf("\n");
		i = 0;
		j++;
	}
}

int			main(int argc, char **argv)
{
	Coordonnes tab_struct[ft_nb_tetri(ft_open(argv[1])) + 1];
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit take 1 argument");
		return (0);
	}
	ft_read(ft_open(argv[1]));
	if (ft_parsing(ft_open(argv[1])) != 1)
	{
		ft_putstr("error\n");
		return (0);
	}
	ft_21_par_21(tab_struct, argv[1]);
	//ft_print_coord(tab_struct, ft_nb_tetri(ft_open(argv[1])));
	ft_print_map(ft_create_final_map(4));
	return (0);
}
