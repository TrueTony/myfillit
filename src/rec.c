/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:35:57 by ksenaida          #+#    #+#             */
/*   Updated: 2019/11/17 14:24:56 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		comming(char **ma, t_tetris *t, int i, int j)
{
	int		mi;
	int		mj;

	mi = ft_strlen(ma[0]) - mof(t->data[0], t->data[2], t->data[4], t->data[6]);
	mj = ft_strlen(ma[0]) - mof(t->data[1], t->data[3], t->data[5], t->data[7]);
	while (i < mi)
	{
		while (j < mj)
		{
			if (is_fitt(ma, t, i, j))
			{
				if (t->next)
				{
					if (rec(ma, t->next, 0, 0))
						return (1);
				}
				else
					return (1);
			}
			j++;
		}
		i++;
		j = -1;
	}
	return (0);
}

int		rec(char **ma, t_tetris *t, int i, int j)
{
	if (comming(ma, t, i, j))
		return (1);
	free_cells(ma, t->c - 1);
	return (0);
}
