/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: almalfoy <almalfoy@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 15:24:16 by almalfoy     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 12:17:09 by almalfoy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _FT_FILLIT_H
# define _FT_FILLIT_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# define BUF_SIZE 21

typedef struct			Coordonnees
{
	char				letter;
	int					x[4];
	int					y[4];
}						Coordonnees;
typedef struct			s_nbr
{
	int					tetri_nbr;
	int					size;
	int					num_tetri;
}						t_nbr;

int						ft_parse(char *file, int *tetri_nbr);
Coordonnees				*ft_stock(char *file, int tetri_nbr);
char					**ft_remplissage_tab(int taille);
char					**ft_place(char **grid, Coordonnees tetri, int position,
						int size);
int						ft_check(char **grid, Coordonnees tetri, int position,
						int size);
void					ft_print(char **grid);
int						ft_set_dim(int tetri_nbr);
char					**ft_del_tetri(char **grid, Coordonnees tetri);
int						ft_isalpha(int c);
void					ft_putchar(char c);
void					ft_putstr(char *str);
int						ft_success(char **grid, Coordonnees *tetri);
char					**ft_rec_back(char **grid, Coordonnees *tetri, int position,
						t_nbr structure);
#endif
