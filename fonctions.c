/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fonctions.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: almalfoy <almalfoy@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 12:55:23 by almalfoy     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/19 15:26:07 by almalfoy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#define BUF_SIZE 21

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int		ft_nb_tetri(int fd)
{
	int		ret_read, i = 0, nb_block = 0, nb_dieze = 0;
	char	buf[BUF_SIZE + 1];

	while ((ret_read = read(fd, buf, BUF_SIZE)))
	{
		while (i < ret_read - 1)
		{
			if (buf[i] == '#')
			{
				if (nb_dieze > 2)
					nb_block++;
				nb_dieze++;
			}
			i++;
		}
		nb_dieze = 0;
		i = 0;
	}
	return (nb_block);
}

int		ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

int		ft_sqrt(int n)
{
	int i;

	i = 2;
	while (i * i < n)
		i++;
	return (i);
}
