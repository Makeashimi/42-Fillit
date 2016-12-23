/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 12:39:21 by jcharloi          #+#    #+#             */
/*   Updated: 2016/12/23 10:45:01 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 546

# include <unistd.h>
# include <fcntl.h>
# include "Libft/libft.h"

typedef struct		s_tetri
{
	char			**tetri;
	int				m;
	int				l;
}					t_tetri;

char				*ft_openfile(char *param);
int					ft_checktetri(char *file);
t_tetri				*ft_split(char *file);
t_tetri				*ft_optiblock(t_tetri *tab);
int					ft_backtracking(t_tetri *tab, char **map, int i);
char				**ft_postetri(t_tetri *tab);
void				ft_free(char **map, t_tetri *tab);
int					main(int argc, char **argv);

#endif
