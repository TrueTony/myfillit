/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:27:13 by ksenaida          #+#    #+#             */
/*   Updated: 2019/11/12 19:18:54 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
//#include "ttt.h"

int     min_map(t_tetris *tetro, int count)
{
    int     i;
    int     size;

    i = 0;
    size = '2';
    if (count == 1)
    {
        while (i < 8)
        {
            if (tetro->data[i] > size)
                size = tetro->data[i] + 1;
            i++;
        }
    }
    else
        while ((size-48) * (size-48) < (count * 4))
            size++;
    return (size-48);
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
