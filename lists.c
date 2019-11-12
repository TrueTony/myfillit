#include "ttt.h"

t_tetris	*newlist_with_c(char *data, char letter)
{
	t_tetris	*list;
	list = (t_tetris*)malloc(sizeof(t_tetris));

	if (!letter)
		return NULL;
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
			return NULL;;
		}
		ft_memcpy(list->data, data, 8);
		list->data[8] = '\0';
	}
	list->next = NULL;
	return (list);
}

void	ft_lstadd_tet(t_tetris **alst, t_tetris *new)
{
	if (new != NULL && alst != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}
