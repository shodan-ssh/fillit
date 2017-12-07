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
	int		ret_open, nb_dieze = 0, ret_read = 0, i = 0, nb_point = 0, last_buf;
	char	buf[BUF_SIZE + 1];

	ret_open = open(file, O_RDONLY); // ouvrir fichier
	while ((ret_read = read(ret_open, buf, BUF_SIZE))) // lit le fichier
	{
		while (i < ret_read - 1)
		{
			last_buf = ret_read;
			if (buf[i] == '#' || buf[i] == '.' || buf[i] == '\n')
			{
				if (i == 4 || i == 9 || i == 14 || i == 19)
				{
					if (buf[i] != '\n') // verifie si un '\n' est a chaque fin de ligne
						return (0);
				}
				printf("%c", buf[i]); // Affiche les tetriminos
				if (buf[i] == '.')
					nb_point++;
				if (buf[i] == '#') // verifie si une dieze
				{
					nb_dieze++;
					if (buf[i + 1] != '#' && buf[i + 5] != '#')
						if (buf[i - 1] != '#' && buf[i - 5] != '#')
							return (0);
					if (buf[i + 1] == '\n' && ((buf[i + 5] != '#') && (buf[i - 5] != '#') && (buf[i - 2] != '#') && (buf[i - 6] != '#') && (buf[i + 4] != '#')))
						return (0);
				}
				i++;
			}
			else
				return (0); // return  0 si pas # ou . ou \n
		}
		if (nb_dieze % 4 != 0 || nb_dieze > 104 || nb_point % 12 != 0 || nb_point > 312 || nb_dieze > 4)
			return (0);
		i = 0; // reinitialise i pour le prochain block
	}
	if (last_buf > 20)
		return (0);
	return (1);
}

int		main(void)
{
	printf("\n\nLe fichier est %d\n", ft_parsing("list_tetriminos"));
	return (0);
}
