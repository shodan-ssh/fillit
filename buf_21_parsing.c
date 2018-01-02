/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   buf_21_parsing.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: almalfoy <almalfoy@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 11:49:57 by almalfoy     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/02 14:33:04 by almalfoy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#define BUF_SIZE 21

int		ft_link(char *str)
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

int		ft_tetri_check(char *buf, int ret)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (i < ret)
	{
		if (i == 4 || i == 9 || i == 14 || i == 19)
			if (buf[i++] != '\n')
				return (0);
		if (buf[i] != '.' && buf[i] != '#' && i != 20)
			return (0);
		buf[i++] == '#' ? count++ : count;
	}
	if (ft_link(buf) && count == 4)
		return (1);
	return (0);
}

int		ft_parse(char *file, int *tetri_nbr)
{
	int		fd;
	int		ret;
	int		bufsz;
	char	buf[BUF_SIZE];

	fd = open(file, O_RDONLY);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		bufsz = ret;
		if (!(ft_tetri_check(buf, ret)))
		{
			close(fd);
			return (0);
		}
		*tetri_nbr += 1;
	}
	close(fd);
	if (*tetri_nbr > 26)
		return (0);
	return (bufsz != 20 ? 0 : 1);
}
/*
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
*/
