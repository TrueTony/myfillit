/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:27:13 by ksenaida          #+#    #+#             */
/*   Updated: 2019/11/12 11:30:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttt.h"

int     min_map(int n)
{
    int size;

    size = 2;
    while (size * size < n)
        size++;
    return (size);
}

char    **make_map(int size)
{
    char **map;
    int i;
    int j;
    i = 0;
    j = 0;
    map = (char**)malloc(sizeof(char *) * size + 1);
	if (!map)
		return NULL;
    while (i < size)
    {
        map[i] = ft_strnew(size);
        while (j < size)
        {
            map[i][j] = '.';
            j++;
        }
        i++;
        j = 0;
    }
    map[i] = NULL;
    return (map);
}

void    print_map(char **map, int count)
{
    int i;
    int j;

    i = 0;
    while(i < count)
    {
        j = 0;
        while (j < count)
        {
            printf("%c", map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}
