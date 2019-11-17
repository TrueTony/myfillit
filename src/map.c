/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:27:13 by ksenaida          #+#    #+#             */
/*   Updated: 2019/11/17 14:25:27 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		min_map(int count)
{
	int		size;

	size = 2;
	while (size * size < (count * 4))
		size++;
	return (size);
}

char	**make_map(int size)
{
	char	**map;
	int		i;

	i = 0;
	map = (char**)malloc(sizeof(char *) * size + 1);
	if (!map)
		return (NULL);
	while (i < size)
	{
		map[i] = ft_strnew(size);
		ft_memset(map[i], 46, size);
		map[i][size] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	print_map(char **map, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}
