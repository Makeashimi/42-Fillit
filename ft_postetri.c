/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_postetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:22:12 by jcharloi          #+#    #+#             */
/*   Updated: 2016/12/23 10:41:33 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** 1) malloc = lenght;
** 2) malloc = width;
*/

char	**ft_map(int size)
{
	char	**map;
	int		i;

	i = 0;
	map = (char**)malloc(sizeof(char*) * (size + 1));
	while (i < size)
	{
		map[i] = ft_strnew(size);
		map[i] = ft_memset((void*)map[i], '.', size);
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	ft_display(t_tetri *tab, char **map)
{
	int i;
	int j;
	int k;

	i = 0;
	while (tab[i].tetri)
	{
		j = 0;
		while (tab[i].tetri[j])
		{
			k = 0;
			while (tab[i].tetri[j][k])
			{
				if (tab[i].tetri[j][k] != '.')
					map[tab[i].l + j][tab[i].m + k] = tab[i].tetri[j][k];
				k++;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (map[i++])
		ft_putendl(map[i - 1]);
}

char	**ft_postetri(t_tetri *tab)
{
	char	**map;
	int		count;
	int		size;
	int		i;

	tab = ft_optiblock(tab);
	count = 0;
	i = 0;
	while (tab[count].tetri)
		count++;
	count = count * 4;
	while ((size = ft_sqrt(count)) == 0)
		count++;
	map = ft_map(size);
	while ((ft_backtracking(tab, map, 0)) == 0)
	{
		size++;
		ft_tabdel((void***)&map);
		map = ft_map(size);
	}
	ft_display(tab, map);
	return (map);
}
