/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:46:12 by ksenaida          #+#    #+#             */
/*   Updated: 2019/11/13 17:47:16 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris	*newlist_with_c(char *data, char letter)
{
	t_tetris	*list;

	list = (t_tetris*)malloc(sizeof(t_tetris));
	if (!letter)
		return (NULL);
	else
		list->c = letter;
	if (!data)
	{
		list->data = NULL;
	}
	else
	{
		list->data = (char*)malloc(sizeof(char) * 8 + 1);
		if (!list->data)
		{
			free(list->data);
			return (NULL);
		}
		ft_memcpy(list->data, data, 8);
		list->data[8] = '\0';
	}
	list->next = NULL;
	return (list);
}

void		ft_lstadd_tet(t_tetris **alst, t_tetris *new)
{
	if (new != NULL && alst != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}

void		to_lst(t_tetris **a, t_tetris **b, char *gab, char letter)
{
	if (letter == 'A')
	{
		*a = newlist_with_c(gab, letter);
		letter++;
	}
	else
	{
		*b = newlist_with_c(gab, letter);
		letter++;
		ft_lstadd_tet(a, *b);
	}
}
