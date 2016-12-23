/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 10:43:32 by jcharloi          #+#    #+#             */
/*   Updated: 2016/12/23 10:35:39 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** a = coordinates of new tetri / box.m + k = previous tetri already placed.
*/

int		ft_checksup2(int a, int b, t_tetri box)
{
	int j;
	int k;

	j = 0;
	while (box.tetri[j])
	{
		k = 0;
		while (box.tetri[j][k])
		{
			if (box.tetri[j][k] != '.')
			{
				if (a == box.m + k && b == box.l + j)
					return (0);
			}
			k++;
		}
		j++;
	}
	return (1);
}

int		ft_checksup(t_tetri *tab, int i, int m, int l)
{
	int j;
	int k;
	int o;

	j = 0;
	while (tab[i].tetri[j])
	{
		k = 0;
		while (tab[i].tetri[j][k])
		{
			if (tab[i].tetri[j][k] != '.')
			{
				o = 0;
				while (o < i)
				{
					if (!(ft_checksup2(m + k, l + j, tab[o])))
						return (0);
					o++;
				}
			}
			k++;
		}
		j++;
	}
	return (1);
}

int		ft_checkmap(char **block, char **map, int m, int l)
{
	int j;
	int k;
	int count;

	j = 0;
	count = 0;
	while (block[j])
	{
		k = 0;
		while (block[j][k])
		{
			if (block[j][k] != '.' && ((m + k) < (int)ft_strlen(map[0])
				&& (l + j) < (int)ft_strlen(map[0])))
				count++;
			k++;
		}
		j++;
	}
	if (count == 4)
		return (1);
	return (0);
}

int		ft_backtracking(t_tetri *tab, char **map, int i)
{
	int l;
	int m;

	l = 0;
	while (map[l])
	{
		m = 0;
		while (map[l][m])
		{
			if (ft_checkmap(tab[i].tetri, map, m, l)
				&& ft_checksup(tab, i, m, l))
			{
				tab[i].m = m;
				tab[i].l = l;
				if ((tab[i + 1].tetri == NULL)
					|| (ft_backtracking(tab, map, i + 1)))
					return (1);
			}
			m++;
		}
		l++;
	}
	return (0);
}
