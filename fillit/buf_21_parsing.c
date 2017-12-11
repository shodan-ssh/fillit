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

int		ft_parsing_bis(int fd)
{
	return (0);
}

int		ft_parsing(int fd)
{
	int		ret_open, nb_dieze = 0, ret_read = 0, i = 0, nb_point = 0, last_buf;
	char	buf[BUF_SIZE + 1];

	while ((ret_read = read(fd, buf, BUF_SIZE)))
	{
		while (i < ret_read - 1)
		{
			last_buf = ret_read;
			if (buf[i] == '#' || buf[i] == '.' || buf[i] == '\n')
			{
				if (i == 4 || i == 9 || i == 14 || i == 19)
				{
					if (buf[i] != '\n')
						return (0);
				}
				if (buf[i] == '.')
					nb_point++;
				if (buf[i] == '#')
				{
					nb_dieze++;
					if (buf[i + 1] != '#' && buf[i + 5] != '#')
						if (buf[i - 1] != '#' && buf[i - 5] != '#')
							return (0);
					if (buf[i + 1] == '\n' && ((buf[i + 5] != '#') && (buf[i - 5] != '#')) && (buf[i - 2] != '#') && (buf[i - 4] != '#') && buf[i + 4] != '#')
						return (0);
				}
				i++;
				if (nb_dieze > 4)
					return (0);
			}
			else
				return (0);
		}
		if (nb_dieze % 4 != 0 || nb_dieze > 104 || nb_point % 12 != 0 || nb_point > 312)
			return (0);
		i = 0;
		nb_dieze = 0;
	}
	if (last_buf > 20)
		return (0);
	return (1);
}

int		main(void)
{
	int fd;

	fd = open("list_tetriminos", O_RDONLY);
	printf("File is %d\n", ft_parsing(fd));
	return (0);
}
