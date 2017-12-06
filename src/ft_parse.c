/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_open_file.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: almalfoy <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 16:25:55 by almalfoy     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 16:38:12 by almalfoy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fillit.h"
#define BUF_SIZE 21

int		ft_nb_diez(char *buf)
{
	int nb_dieze;
	int	nb_point;
	int i;

	nb_dieze = 0;
	i = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
			nb_dieze++;
		if (buf[i] == '.')
			nb_point++;
		printf("%c", buf[i]);
		i++;
	}
	printf("nb_point = %d\nnb_dieze = %d", nb_point, nb_dieze);
//	if (i == 21 && buf[i] != '\n')
//		return (0);
	if (nb_point != 12 || nb_dieze != 4)
		return (0);
	return (1);
}

int		ft_read_file(const char *file)
{
	int		ret_read;
	char	buf[BUF_SIZE + 1];
	int 	fic;
	int		result;

	result = 2;
	fic = open(file, O_RDONLY);
	printf("ret_open = %d\n", fic);
	if (fic == -1)
	{
		printf("error");
		exit(1);
	}
	while (read(fic, buf, BUF_SIZE))
	{
		result = ft_nb_diez(buf);
		if (result == 0)
			return (0);
	}
	if (close(fic) == -1)
	{
		printf("close() failed\n");
		exit(1);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	printf("result -> %d\n", ft_read_file("list_tetriminos"));
	return (0);
}
