/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_parsing.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: almalfoy <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/05 16:16:02 by almalfoy     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 16:16:04 by almalfoy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fillit.h"
#define BUF_SIZE 1

int		ft_read_file(const char *file)
{
	int		ret_read = 0, fic = 0, result = 0, i = 0, nb_dieze = 0, nb_point = 0, flag = 0;
	char	buf[BUF_SIZE + 1];

	fic = open(file, O_RDONLY);
	printf("ret_open = %d\n", fic);
	if (fic == -1)
	{
		printf("error");
		exit(1);
	}
	while ((ret_read = read(fic, buf, BUF_SIZE)))
	{
		buf[ret_read] = '\0';
		if (*buf == '#')
			nb_dieze++;
		if (*buf == '.')
			nb_point++;
		if (*buf == '\n' && (i / 5) % 21 == 0)
			flag++;
//		if (i > 0 && i % 5 != 0)
//		{
//			if (buf[i] != '#' || buf[i] != '.')
//				return (0);
//		}
//		printf("nb_point = %d\nnb_dieze = %d\n", nb_point, nb_dieze);
//		printf("%c", *buf);
		printf("i = %d\n", i);
		i++;
	}
	printf("%d\n", flag);
	if (nb_point % 12 != 0 || nb_dieze % 4 != 0)
		return (0);
	if (close(fic) == -1)
	{
		printf("close() failed\n");
		exit(1);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	printf("list tetriminos is %d", ft_read_file("list_tetriminos"));
	return (0);
}
