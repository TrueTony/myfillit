/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:15:14 by ksenaida          #+#    #+#             */
/*   Updated: 2019/12/07 19:53:58 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			count_of_tet(t_tetris *a)
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

int			solving(t_tetris *a)
{
	int		count;
	int		edge;
	char	**map;
	int		min_map_size;

	count = count_of_tet(a);
	if (count > 26)
		return (1);
	min_map_size = min_map(count);
	map = make_map(min_map_size);
	edge = ft_strlen(map[0]);
	while (!(rec(map, a, 0, 0)))
	{
		free(map);
		min_map_size++;
		map = make_map(min_map_size);
		edge = ft_strlen(map[0]);
	}
	print_map(map, edge);
	free_map(map, edge);
	return (0);
}

int			recread(int fd)
{
	int				i;
	char			strbuf[21];
	unsigned int	size;

	i = 20;
	size = read(fd, strbuf, 21);
	strbuf[size] = '\0';
	if (ft_strlen(strbuf) == 21)
		if (!recread(fd))
			return (0);
	if (ft_strlen(strbuf) == 20)
		return (0);
	if (strbuf[i] != '\n')
		return (1);
	return (1);
}

int			read_functions(char *str, t_tetris **a, t_tetris **b)
{
	int		fd;
	int		size;
	char	strbuf[21];

	fd = open(str, O_RDONLY);
	if (recread(fd))
		return (1);
	close(fd);
	fd = open(str, O_RDONLY);
	while ((size = read(fd, strbuf, 21)))
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

int			main(int argc, char **argv)
{
	t_tetris	*a;
	t_tetris	*b;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
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
	ft_lstdelnew(&a);
	return (0);
}
