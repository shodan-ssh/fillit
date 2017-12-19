/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: almalfoy <almalfoy@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 15:59:21 by almalfoy     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/19 17:21:54 by almalfoy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef __FT_FILLIT_H
# define __FT_FILLIT_H
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct			Coordonnes
{
	int					x[4];
	int					y[4];
	char				letter;
}						Coordonnes;

typedef struct			s_nbr
{
	int					tetri_nbr;
	int					size;
	int					num_tetri;
}						t_nbr;

int						ft_parsing(int fd);
Coordonnes				*ft_calc_pos(int fd);
void 					ft_pos(int fd);
int						ft_nb_tetri(int fd);
void					ft_axe_x_y(int fd);
void 					ft_putstr(char *str);
void 					ft_putchar(char c);
int						ft_open(char *file);
void    				ft_print_coord(Coordonnes *tab_struct, int nb_tetri);
Coordonnes				*ft_21_par_21(Coordonnes *tab_struct, char *argv);
void					ft_haut_gauche(Coordonnes *tab_struct);
void    				ft_coord(char *buf, Coordonnes *tab_struct);
char					**ft_create_final_map(int size);
char					*ft_read(int fd);
void 					ft_print_map(char **map);
char					**ft_rec_back(char **map, Coordonnes *tetri, int pos, \
						t_nbr nbr);
int						ft_isalpha(int c);
int						ft_success(char **grid, Coordonnes *tetri);
char					**ft_del_tetri(char **map, Coordonnes tetri);
int						ft_check(char **grid, Coordonnes tetri, int position, \
						int size);
char					**ft_place_tetri(char **map, Coordonnes tetri, \
						int position, int size);
#endif
