/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:43:02 by jcharloi          #+#    #+#             */
/*   Updated: 2016/12/21 15:13:18 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char		*str;
	char		**map;
	t_tetri		*tab;

	if (argc != 2)
		ft_putendl("usage : ./fillit file");
	else
	{
		str = ft_openfile(argv[1]);
		if (str == NULL || ft_checktetri(str))
			ft_putendl("error");
		else
		{
			tab = ft_split(str);
			map = ft_postetri(tab);
			ft_free(map, tab);
		}
		ft_memdel((void**)&str);
	}
	return (0);
}
