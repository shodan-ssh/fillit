/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_buf_21_parsing.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: almalfoy <almalfoy@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 15:24:38 by almalfoy     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 12:01:30 by almalfoy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_liaisons(char *str)
{
	int a;
	int count;

	a = 0;
	count = 0;
	while (str[a])
	{
		if (str[a] == '#')
		{
			if (str[a + 1] == '#')
				count++;
			if (str[a - 5] == '#' && a >= 5)
				count++;
			if (str[a + 5] == '#' && a <= 15)
				count++;
			if (str[a - 1] == '#' && a > 0)
				count++;
		}
		a++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}

int		ft_parse2(char *buf, int ret)
{
	int		i;
	int		nb_dieze;

	i = 0;
	nb_dieze = 0;
	while (i < ret)
	{
		if (i == 4 || i == 9 || i == 14 || i == 19)
			if (buf[i++] != '\n')
				return (0);
		if (buf[i] != '.' && buf[i] != '#' && i != 20)
			return (0);
		buf[i++] == '#' ? nb_dieze++ : nb_dieze;
	}
	if (ft_liaisons(buf) && nb_dieze == 4)
		return (1);
	return (0);
}

int		ft_parse(char *file, int *tetri_nbr)
{
	int		fd;
	int		ret;
	int		verif_last_block;
	char	buf[BUF_SIZE];

	fd = open(file, O_RDONLY);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		verif_last_block = ret;
		if (!(ft_parse2(buf, ret)))
		{
			close(fd);
			return (0);
		}
		*tetri_nbr += 1;
	}
	close(fd);
	if (*tetri_nbr > 26)
		return (0);
	return (verif_last_block != 20 ? 0 : 1);
}
