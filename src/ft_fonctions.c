/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fonctions.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: almalfoy <almalfoy@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/07 15:08:03 by almalfoy     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/07 17:24:48 by almalfoy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	if (str)
	{
		while (*str)
			ft_putchar(*str++);
	}
}

void	ft_print(char **map)
{
	int i;

	i = 0;
	while (map[i] != '\0')
	{
		ft_putstr(map[i]);
		if (i % 1 == 0)
			ft_putchar('\n');
		i++;
	}
}
