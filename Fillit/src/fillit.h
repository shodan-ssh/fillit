/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: almalfoy <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 15:24:16 by almalfoy     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/05 15:24:17 by almalfoy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _FT_FILLIT_H
# define _FT_FILLIT_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

# define BUF_SIZE 21

typedef struct			s_tetri
{
	char				a;
	int					x[4];
	int					y[4];
}						t_tetri;
typedef struct			s_nbr
{
	int					tetri_nbr;
	int					size;
	int					num_tetri;
}						t_nbr;

int						ft_parse(char *file, int *tetri_nbr);
t_tetri					*ft_stock(char *file, int tetri_nbr);
char					**ft_dim_tab(int dim);
char					**ft_place(char **grid, t_tetri tetri, int position,
						int size);
int						ft_success(char **grid, t_tetri *tetri);
int						ft_check(char **grid, t_tetri tetri, int position,
						int size);
void					ft_print(char **grid);
int						ft_set_dim(int tetri_nbr);
char					**ft_del_tetri(char **grid, t_tetri tetri);
char					**ft_rec_back(char **grid, t_tetri *tetri, int position,
						t_nbr structure);
#endif
