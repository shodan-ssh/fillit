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

typedef struct		Coordonnes
{
	int				x[4];
	int				y[4];
}					Coordonnes;

int					ft_parsing(char *file);
Coordonnes			*ft_calc_pos(int fd);
void 				ft_pos(int fd);
#endif
