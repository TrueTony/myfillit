#include "ttt.h"

int		count_of_tet(t_tetris *a)
{
	int		i;

	i = 1;
	while (a->next)
	{
		i++;
		a = a->next;
	}
	return (i);
}
