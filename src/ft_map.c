/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_map.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: almalfoy <almalfoy@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 15:25:26 by almalfoy     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/07 16:27:37 by almalfoy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_set_dim(int nb_tetri)
{
	int dim;

	dim = 0;
	nb_tetri = 4 * nb_tetri;
	while ((dim * dim) < nb_tetri)
		dim++;
	return (dim);
}

char	**ft_remplissage_tab(int taille)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = (char **)malloc(sizeof(char*) * taille + 1);
	tab[taille] = NULL;
	while (i < taille)
		tab[i++] = (char *)malloc(sizeof(char) * taille + 1);
	i = 0;
	while (i < taille)
	{
		while (j < taille)
		{
			tab[i][j] = '.';
			j++;
		}
		tab[i][j] = '\0';
		j = 0;
		i++;
	}
	return (tab);
}
