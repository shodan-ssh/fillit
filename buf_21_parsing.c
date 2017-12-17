/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   buf_21_parsing.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: almalfoy <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 11:49:57 by almalfoy     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 12:32:56 by almalfoy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#define BUF_SIZE 21

int		ft_parsing_bis(char *buf, int i)
{
	if (buf[i] != '#' && buf[i] != '.' && buf[i] != '\n')
		return (0);
	if (i == 4 || i == 9 || i == 14 || i == 19)
	{
		if (buf[i] != '\n')
			return (0);
	}
	return (1);
}

int		ft_parsing(int fd)
{
	int		nb_dieze;
	int		ret_read;
	int		i;
	int		liaison;
	int		last_buf;
	char	buf[BUF_SIZE + 1];

	i = 0;
	liaison = 0;
	nb_dieze = 0;
	while ((ret_read = read(fd, buf, BUF_SIZE)))
	{
		last_buf = ret_read;
		while (i < ret_read - 1)
		{
			if (ft_parsing_bis(buf, i) == 0)
				return (0);
			if (buf[i] == '#')
			{
				nb_dieze++;
				if (buf[i + 1] == '#')
					liaison++;
				if (buf[i - 1] == '#')
					liaison++;
				if (buf[i + 5] == '#')
					liaison++;
				if (buf[i - 5] == '#')
					liaison++;
			}
			i++;
		}
		if (nb_dieze != 4 || liaison < 6 || nb_dieze > 104)
			return (0);
		liaison = 0;
		i = 0;
		nb_dieze = 0;
	}
	if (last_buf != 20)
		return (0);
	return (1);
}
/*
int		main(int argc, char **argv)
{
	printf("File is %d\n", ft_parsing(ft_open(argv[1])));
	return (0);
}
*/
