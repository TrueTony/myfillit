/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:15:14 by ksenaida          #+#    #+#             */
/*   Updated: 2019/11/12 19:59:37 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
int     solve(char arr)
{
    char    **grid;
    grid = make_map(5);
    rec(grid, arr, 0, 0, 0, 'A');
    print_map(grid, 5);
    printf("it works!\n");
    return (0);
}
*/
int		main(int argc, char **argv)
{
	int			fd;
	t_tetris	*a;
    t_tetris	*b;
	int 		i;
	int			count;
	int			edge;
	char		str[21];
	char		**map;
	int			min_map_size;

	a = NULL;
	b = NULL;
	//i = 0;
	if (argc != 2)
	{
		//use usage
		return (0);
	}
	//to readf and read must return count of tetrs
	fd = open(argv[1], O_RDONLY);
	while((i = read(fd, str, 21)))
	{
		if (checks(str, i))
			return (0);
	}
	close(fd);

	fd = open(argv[1], O_RDONLY);
    if (read_tet(fd, &a, &b))
        return (0);
    close(fd);

	count = count_of_tet(a);
	min_map_size = min_map(a, count);
	map = make_map(min_map_size);
	edge = ft_strlen(map[0]);
	//printf("min map is %d\n", edge);
	/*
	if (rec(map, a, 0, 0, count-1, edge))
		printf("succes!\n");
	else
		printf("smt wrong\n");
	*/
	while (!(rec(map, a, 0, 0, count-1, edge)))
	{
		free(map);
		min_map_size++;
		map = make_map(min_map_size);
		edge = ft_strlen(map[0]);
	}
	//printf("\n");
	print_map(map, edge);
/*
	while (a)
    {
        i = 0;
        while (i < 8)
        {
            printf("%d, ", a->data[i]);
            i++;
        }
		printf("%c", a->c);
        a = a->next;
        printf("\n");
    }
*/

	return (0);
}


