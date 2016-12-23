/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optiblock.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 10:36:28 by jcharloi          #+#    #+#             */
/*   Updated: 2016/12/23 10:44:46 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*ft_alphabet(t_tetri *tab)
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
				if (tab[i].tetri[j][k] == '#')
					tab[i].tetri[j][k] = i + 65;
				k++;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

t_tetri		*ft_top(t_tetri *tab)
{
	int i;

	i = 0;
	while (tab[i].tetri)
	{
		while (tab[i].tetri[0][0] == '.' && tab[i].tetri[0][1] == '.'
			&& tab[i].tetri[0][2] == '.' && tab[i].tetri[0][3] == '.')
		{
			ft_strncpy(tab[i].tetri[0], tab[i].tetri[1], 5);
			ft_strncpy(tab[i].tetri[1], tab[i].tetri[2], 5);
			ft_strncpy(tab[i].tetri[2], tab[i].tetri[3], 5);
			ft_strncpy(tab[i].tetri[3], "....\0", 5);
		}
		i++;
	}
	return (tab);
}

t_tetri		*ft_left(t_tetri *tb)
{
	int i;
	int j;
	int k;

	i = 0;
	while (tb[i++].tetri)
	{
		while (tb[i - 1].tetri[0][0] == '.' && tb[i - 1].tetri[1][0] == '.'
			&& tb[i - 1].tetri[2][0] == '.' && tb[i - 1].tetri[3][0] == '.')
		{
			j = 0;
			while (tb[i - 1].tetri[j] && (k = 0) == 0)
			{
				while (tb[i - 1].tetri[j][k++])
				{
					if (ft_isalpha(tb[i - 1].tetri[j][k - 1]) && (
						tb[i - 1].tetri[j][k - 2] = tb[i - 1].tetri[j][k - 1]))
						tb[i - 1].tetri[j][k - 1] = '.';
				}
				j++;
			}
		}
	}
	return (tb);
}

t_tetri		*ft_optiblock(t_tetri *tab)
{
	ft_alphabet(tab);
	ft_top(tab);
	ft_left(tab);
	return (tab);
}
