/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checktetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:50:59 by jcharloi          #+#    #+#             */
/*   Updated: 2016/12/23 10:21:54 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_checksharp(char *file, int i, int k)
{
	int link;

	link = 0;
	while (file[i])
	{
		while (k++ < 21)
		{
			if (file[i] == '#' && file[i + 1] == '#' && k - 1 < 21)
				link++;
			if (file[i] == '#' && file[i - 1] == '#' && k - 1 > 0)
				link++;
			if (file[i] == '#' && file[i + 5] == '#' && k - 1 < 16)
				link++;
			if (file[i] == '#' && file[i - 5] == '#' && k - 1 > 4)
				link++;
			i++;
		}
		if (link < 6)
			return (1);
		if (file[i - 1] == '\0')
			return (0);
		k = 0;
		link = 0;
	}
	return (0);
}

int		ft_checkchar(char *file, int i, int k)
{
	int dot;
	int sharp;

	while (file[i] != '\0')
	{
		dot = 0;
		sharp = 0;
		while (k++ < 21 && file[i] != '\0')
		{
			if (((k % 5 == 0 && file[i] != '\n') || (k - 1 == 20
				&& file[i] != '\n' && i < (int)(ft_strlen(file)) - 1)))
				return (1);
			if (file[i] == '.')
				dot++;
			if (file[i] == '#')
				sharp++;
			i++;
		}
		k = 0;
		if (dot != 12 || sharp != 4)
			return (1);
	}
	if (file[i - 2] == '\n')
		return (1);
	return (0);
}

int		ft_checktetri(char *file)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (file[i] != '\0')
	{
		if (file[i] != '.' && file[i] != '#' && file[i] != '\n')
			return (1);
		i++;
	}
	if (file[i - 1] != '\n')
		return (1);
	i = 0;
	if (ft_checkchar(file, i, k))
		return (1);
	if (ft_checksharp(file, i, k))
		return (1);
	return (0);
}
