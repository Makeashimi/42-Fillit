/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:48:02 by jcharloi          #+#    #+#             */
/*   Updated: 2016/12/23 10:44:12 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*ft_split(char *file)
{
	char		*fresh;
	char		**block;
	t_tetri		*tab;
	size_t		i;

	i = 0;
	fresh = ft_strnew(20);
	tab = (t_tetri*)ft_memalloc((((ft_strlen(file) + 1) / 21) *
		(sizeof(t_tetri))) + sizeof(t_tetri));
	while (file[i] && i < ft_strlen(file))
	{
		ft_strncpy(fresh, file + i, 20);
		block = ft_strsplit(fresh, '\n');
		tab[i / 21].tetri = block;
		i = i + 21;
	}
	tab[(i / 21)].tetri = NULL;
	free(fresh);
	return (tab);
}
