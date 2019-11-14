/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:15:14 by ksenaida          #+#    #+#             */
/*   Updated: 2019/11/14 20:19:22 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     solving(t_tetris *a)
{
	int		count;
	int		edge;
	char	**map;
	int		min_map_size;

	count = count_of_tet(a);
	min_map_size = min_map(a, count);
	map = make_map(min_map_size);
	edge = ft_strlen(map[0]);
	while (!(rec(map, a, 0, 0)))
	{
		free(map);
		min_map_size++;
		map = make_map(min_map_size);
		edge = ft_strlen(map[0]);
	}
	free(map);
	print_map(map, edge);
    return (0);
}

int		recread(fd)
{
	int		size;
	char	strbuf[21];

	while((size = read(fd, strbuf, 21)))
	{
		if (strbuf[20] == '\n')
		{
			if ((size = read(fd, strbuf, 21)) != 21)
			{
				printf("recread error\n");
				return (1);
			}
			else
				recread(fd);
		}
	}
	return (0);
}

int		read_functions(char *str, t_tetris **a, t_tetris **b)
{
	int		fd;
	int		size;
	char	strbuf[21];

	fd = open(str, O_RDONLY);
	recread(fd);
	close (fd);

	fd = open(str, O_RDONLY);
	while((size = read(fd, strbuf, 21)))
	{
		if (checks(strbuf, size))
			return (1);
	}
	close(fd);
	fd = open(str, O_RDONLY);
    if (read_tet(fd, a, b))
        return (1);
    close(fd);
	return (0);
}

int		main(int argc, char **argv)
{
	t_tetris	*a;
    t_tetris	*b;

	if (argc != 2)
	{
		ft_putstr("usage\n");
		return (0);
	}
	if (read_functions(argv[1], &a, &b))
	{
		ft_putstr("error\n");
		return (0);
	}
	if (solving(a))
	{
		ft_putstr("error\n");
		return (0);
	}
	return (0);
}


