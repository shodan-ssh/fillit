/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: almalfoy <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 15:59:21 by almalfoy     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 15:59:23 by almalfoy    ###    #+. /#+    ###.fr     */
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
#include "libft/libft.h"

typedef struct		Coordonnes
{
	int				x[4];
	int				y[4];
}					Coordonnes;

int					ft_parsing(int fd);
Coordonnes			*ft_calc_pos(int fd);
void 				ft_pos(int fd);
int					ft_nb_tetri(int fd);
void				ft_axe_x_y(int fd);
#endif
