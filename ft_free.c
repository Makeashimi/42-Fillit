/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 10:33:48 by jcharloi          #+#    #+#             */
/*   Updated: 2016/12/19 16:59:58 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free(char **map, t_tetri *tab)
{
	int i;

	i = 0;
	ft_tabdel((void***)(&map));
	while (tab[i].tetri)
	{
		ft_tabdel((void***)&(tab[i].tetri));
		i++;
	}
	ft_memdel((void**)&tab);
}
