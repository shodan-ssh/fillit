/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: antdarin <antdarin@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 13:42:34 by antdarin     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/13 15:26:38 by antdarin    ###    #+. /#+    ###.fr     */
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
