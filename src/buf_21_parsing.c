/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   buf_21_parsing.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: almalfoy <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 11:49:57 by almalfoy     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 11:49:59 by almalfoy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fillit.h"
#define BUF_SIZE 21

int		ft_parsing(char *file)
{
	int		ret_open, nb_dieze = 0, nb_point = 0;
	int		ret_read;
	int		i;
	char	buf[BUF_SIZE + 1];

	ret_open = open(file, O_RDONLY);
//	printf("open as %d\n", ret_open);
	i = 0;
	while ((ret_read = read(ret_open, buf, BUF_SIZE)))
	{
		while (i <= 20)
		{
			if (buf[i] == '#' || buf[i] == '.' || buf[i] == '\n')
			{
				if (i == 4 || i == 9 || i == 14 || i == 19)
				{
					if (buf[i] != '\n')
						return (0);
				}
				printf("%c", buf[i]);
/*				if (i != 4 || i != 9 || i != 14 || i != 19)
				{
					if (buf[i] != '#' || buf[i] != '.')
						return (0);
				} */
				if (buf[i] == '#')
					nb_dieze++;
				if (buf[i] == '#')
					if (buf[i + 1] != '#' && buf[i - 1] != '#' && buf[i + 5] != '#' && buf[i - 5] != '#')
						return (0);
				if (buf[i] == '.')
					nb_point++;
				i++;
			} else {
				return (0);
			}
		}
		if (nb_dieze % 4 != 0 || nb_point % 4 != 0)
			return (0);
		i = 0;
	}
	printf("nb_dieze = %d\nnb_point = %d\n", nb_dieze, nb_point);
	return (1);
}
int		main(int argc, char **argv)
{
	printf("File is %d\n", ft_parsing("list_tetriminos"));
	return (0);
}
