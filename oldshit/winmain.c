
#include "ttt.h"

int		main(void)
{
	t_tetris	*a;
    t_tetris	*b;
	//int 		i;
	int			count;
	char		**map;
	int			edge;

	tet_to_lst(&a, &b);

	//to readf and read must return count of tetrs
	/*
	while (a)
    {
        i = 0;
        while (i < 8)
        {
            printf("%c, ", a->data[i]);
            i++;
        }
		printf("%c", a->c);
        a = a->next;
        printf("\n");
    }
	*/
	count = count_of_tet(a);
	printf("count %d\n", count);

	map = make_map(4);
	edge = ft_strlen(map[0]);
	if (rec(map, a, 0, 0, count-1, edge))
		printf("succes!\n");
	else
		printf("smt wrong\n");
	print_map(map, 4);


	return (0);
}
